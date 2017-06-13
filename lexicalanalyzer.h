#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QList>
#include <QPair>

enum class TokenType {
    Keyword,
    Identifier,
    Operator,
    Number,
    Punctuation,
    Character
};

enum class KeywordType {
    IF,
    ELSE,
    WHILE,
    INT,
    CHAR,
    BOOL,
    _NULL,
    TRUE,
    FALSE
};

class LexicalAnalyzer
{
public:
    LexicalAnalyzer();
    void analyze(QTextStream *_textStream);

private:
    // Tables
    QList < QPair < TokenType, int > > symbolTable;
    QList < QPair < int, KeywordType > > keywordTable;

    // Lists
    QList < QString > validKeywords;
    QList < QString > validOperator;
    QList < QString > validPunctuation;

};

#endif // LEXICALANALYZER_H
