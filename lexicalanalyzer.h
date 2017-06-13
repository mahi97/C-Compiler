#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QList>
#include <QPair>
#include <QRegExp>
#include <QDebug>

enum class TokenType {
    Keyword,
    Identifier,
    Operator,
    Number,
    Punctuation,
    Character,
    UNKNOWN
};

enum class KeywordType {
    IF    = 0,
    ELSE  = 1,
    WHILE = 2,
    INT   = 3,
    CHAR  = 4,
    BOOL  = 5,
    _NULL = 6,
    TRUE  = 7,
    FALSE = 8
};

struct IdentifierData {
    QString value;
    int* registerAddr;
    int* memoryAddr;
};

struct NumberData {
    QString name;
    int value;
    int* registerAddr;
    int* memoryAddr;
};

class LexicalAnalyzer
{
public:
    LexicalAnalyzer();
    void analyze(QTextStream *_textStream);

private:
    // methodes
    TokenType getTokenType(QString);
    bool isValidIdentifier(QString);
    bool isValidCharacter(QString);
    bool isValidNumber(QString);
    void appendToTables(TokenType, QString);
    KeywordType getKeywordType(QString);
    IdentifierData getIdentifierData(QString);
    NumberData getNumberData(QString);

    // Tables
    QList < QPair < TokenType, int > > symbolTable;
    QList < QPair < int, KeywordType > > keywordTable;
    QList < QPair < int, IdentifierData > > identiTable;
    QList < QPair < int, NumberData > > numberTable;
    QList < QPair < int, QChar > > characterTable;
    QList < QPair < int, QString > > operatorTable;
    QList < QPair < int, QChar > > punctuationTable;
    // Lists
    QList < QString > validKeywords;
    QList < QString > validOperator;
    QList < QString > validPunctuation;

    QList < int > headOfLines;

    // symbol counters
    int keywordCnt;
    int identifierCnt;
    int operatorCnt;
    int numberCnt;
    int characterCnt;
    int punctuationCnt;

};

#endif // LEXICALANALYZER_H
