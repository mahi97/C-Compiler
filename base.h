#ifndef BASE_H
#define BASE_H

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

#endif // BASE_H
