#ifndef COMPILER_H
#define COMPILER_H

#include <QString>
#include <QFile>
#include <QDebug>

#include "lexicalanalyzer.h"

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

    void lexicalAnalyze();

};

#endif // COMPILER_H
