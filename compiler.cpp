#include "compiler.h"

Compiler::Compiler()
{
    m_file = NULL;
    m_lexi = NULL;
}

Compiler::~Compiler()
{

}

bool Compiler::open(QString _path)
{
    if (m_file) delete m_file;
    m_file = new QFile(_path);
    return m_file->open(QIODevice::ReadOnly);

}

void Compiler::compile()
{
    lexicalAnalyze();
}

void Compiler::lexicalAnalyze() {
    if (m_lexi) delete m_lexi;
    m_lexi = new LexicalAnalyzer();
    QTextStream in(m_file);
    m_lexi->analyze(&in);
}
