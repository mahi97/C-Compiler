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

    validOperator << "=" << "+=" << "-=" << "*=" << "/=" << "%="
                  << "&&" << "||" << "!"
                  << "==" << "!=" << ">" << "<" << ">=" << "<="
                  << "+" << "-" << "*" << "/" << "++" << "--";

    validPunctuation << "," << "(" << ")" << "{" << "}" << ":" << ";";

}

void LexicalAnalyzer::analyze(QTextStream* _textStream)
{
    bool comment = false;
    while (!_textStream->atEnd()) {
        QString line = _textStream->readLine();
        QStringList tokens = line.split(' ');
        headOfLines.append(symbolTable.size());
        for (int i = 0 ; i < tokens.size() ; i++) {

            // handle comments
            if (tokens.at(i) == "//") break;
            if (tokens.at(i) == "/*") comment = true;
            if (tokens.at(i) == "*/") comment = false;

            if (!comment) {
                TokenType tempType = getTokenType(tokens.at(i));
                if (tempType == TokenType::UNKNOWN) {
                    qDebug() << "Wrong Token : " << tokens.at(i) << " AT : " << i;
                } else {
                    appendToTables(tempType, tokens.at(i));
                }
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
    QRegExp rx("([a-z]|[A-Z])+([a-z]|[A-Z]|[0-9])*");
    return rx.exactMatch(_token);
}

bool LexicalAnalyzer::isValidCharacter(QString _token)
{
    if (_token.size() == 1) return _token.at(0).isLetter();
    else                    return false;
}

bool LexicalAnalyzer::isValidNumber(QString _token)
{
    if (_token.size() > 0)  return _token.at(0).isNumber();
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
        symbolTable.append(qMakePair(_type, identifierCnt));
        identiTable.append(qMakePair(identifierCnt, getIdentifierData(_token)));
        identifierCnt++;
        break;
    case TokenType::Operator :
        symbolTable.append(qMakePair(_type, operatorCnt));
        operatorTable.append(qMakePair(operatorCnt, _token));
        operatorCnt++;
        break;
    case TokenType::Number :
        symbolTable.append(qMakePair(_type, numberCnt));
        numberTable.append(qMakePair(numberCnt, getNumberData(_token)));
        numberCnt++;
        break;
    case TokenType::Punctuation :
        symbolTable.append(qMakePair(_type, punctuationCnt));
        punctuationTable.append(qMakePair(punctuationCnt, _token[0]));
        punctuationCnt++;
        break;
    case TokenType::Character :
        symbolTable.append(qMakePair(_type, characterCnt));
        characterTable.append(qMakePair(characterCnt, _token[0]));
        characterCnt++;
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

IdentifierData LexicalAnalyzer::getIdentifierData(QString _value)
{
    IdentifierData id;
    id.value = _value;
    id.memoryAddr = NULL;
    id.registerAddr = NULL;
    return id;
}

NumberData LexicalAnalyzer::getNumberData(QString _number)
{
    NumberData nd;
    nd.name = QString("S%1").arg(numberCnt);
    nd.value = _number.toInt();
    nd.memoryAddr = NULL;
    nd.registerAddr = NULL;
    return nd;
}
