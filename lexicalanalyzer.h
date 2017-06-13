#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include "base.h"

class LexicalAnalyzer
{
public:
    LexicalAnalyzer();
    void analyze(QTextStream *_textStream);
    void init(QList<QPair<TokenType, int> > &symbolTable,
              QList<QPair<int, KeywordType> > &keywordTable,
              QList<QPair<int, IdentifierData> > &identiTable,
              QList<QPair<int, NumberData> > &numberTable,
              QList<QPair<int, QChar> > &characterTable,
              QList<QPair<int, QString> > &operatorTable,
              QList<QPair<int, QChar> > &punctuationTable);
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
    QList < QPair < TokenType, int > > *symbolTable;
    QList < QPair < int, KeywordType > > *keywordTable;
    QList < QPair < int, IdentifierData > > *identiTable;
    QList < QPair < int, NumberData > > *numberTable;
    QList < QPair < int, QChar > > *characterTable;
    QList < QPair < int, QString > > *operatorTable;
    QList < QPair < int, QChar > > *punctuationTable;
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
