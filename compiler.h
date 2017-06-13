#ifndef COMPILER_H
#define COMPILER_H

#include "lexicalanalyzer.h"
#include "syntaxanalyzer.h"

class Compiler
{
public:
    Compiler();
    ~Compiler();

    bool open(QString _path);
    void compile();
private:

    QFile* m_file;
    LexicalAnalyzer* m_lexi;
    SyntaxAnalyzer * m_syntx;

    QList < QPair < TokenType, int > >      symbolTable;
    QList < QPair < int, KeywordType > >    keywordTable;
    QList < QPair < int, IdentifierData > > identiTable;
    QList < QPair < int, NumberData > >     numberTable;
    QList < QPair < int, QChar > >          characterTable;
    QList < QPair < int, QString > >        operatorTable;
    QList < QPair < int, QChar > >          punctuationTable;

    void lexicalAnalyze();
    void syntaxAnalyze();

};

#endif // COMPILER_H
