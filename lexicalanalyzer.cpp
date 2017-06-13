#include "lexicalanalyzer.h"

LexicalAnalyzer::LexicalAnalyzer()
{

}

void LexicalAnalyzer::analyze(QTextStream* _textStream)
{
    while (!_textStream->atEnd()) {
        QString line = _textStream->readLine();

    }
}
