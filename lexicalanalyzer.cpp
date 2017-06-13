#include "lexicalanalyzer.h"

LexicalAnalyzer::LexicalAnalyzer()
{
    keywordCnt = 0;
    identifierCnt = 0;
    operatorCnt = 0;
    numberCnt = 0;
    characterCnt = 0;
    punctuationCnt = 0;

    validKeywords << "if"
                  << "else"
                  << "while"
                  << "int"
                  << "char"
                  << "bool"
                  << "null"
                  << "true"
                  << "false";


}

void LexicalAnalyzer::analyze(QTextStream* _textStream)
{
    qDebug() << validKeywords;
    while (!_textStream->atEnd()) {
        QString line = _textStream->readLine();
        QStringList tokens = line.split(' ');
        for (int i = 0 ; i < tokens.size() ; i++) {
            TokenType tempType = getTokenType(tokens.at(i));
            if (tempType == TokenType::UNKNOWN) {
                qDebug() << "Wrong Token : " << tokens.at(i) << " AT : " << i;
            } else {
                appendToTables(tempType, tokens.at(i));
            }
        }
    }
}

TokenType LexicalAnalyzer::getTokenType(QString _token)
{
    if      (validKeywords.contains(_token))    return TokenType::Keyword;
    else if (validOperator.contains(_token))    return TokenType::Operator;
    else if (validPunctuation.contains(_token)) return TokenType::Punctuation;
    else if (isValidIdentifier(_token))         return TokenType::Identifier;
    else if (isValidCharacter(_token))          return TokenType::Character;
    else if (isValidNumber(_token))             return TokenType::Number;
    else                                        return TokenType::UNKNOWN;
}

bool LexicalAnalyzer::isValidIdentifier(QString _token)
{
    QRegExp rx("∧([a−z][A−Z])+([a−z][A−Z][0−9])∗");
    return rx.exactMatch(_token);
}

bool LexicalAnalyzer::isValidCharacter(QString _token)
{
    if (_token.size() == 1) return _token.at(0).isLetter();
    else                    return false;
}

bool LexicalAnalyzer::isValidNumber(QString _token)
{
    if (_token.size() == 1) return _token.at(0).isNumber();
    else                    return false;
}

void LexicalAnalyzer::appendToTables(TokenType _type, QString _token)
{
    switch (_type) {
    case TokenType::Keyword :
        symbolTable.append(qMakePair(_type, keywordCnt));
        keywordTable.append(qMakePair(keywordCnt, getKeywordType(_token)));
        keywordCnt++;
        break;
    case TokenType::Identifier :

        break;
    case TokenType::Operator :

        break;
    case TokenType::Number :

        break;
    case TokenType::Punctuation :

        break;
    case TokenType::Character :

        break;
    case TokenType::UNKNOWN:
        qDebug() << "Something went wrong in filtering";
        break;
    }
}

KeywordType LexicalAnalyzer::getKeywordType(QString _str)
{
    return KeywordType(validKeywords.indexOf(_str));
}
