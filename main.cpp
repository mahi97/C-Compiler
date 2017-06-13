#include <QCoreApplication>
#include <QDebug>

#include "compiler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Compiler* cmplr = new Compiler();
    if (cmplr->open("./code.c")) {
        qDebug() << "Source code opened successfully";
        cmplr->compile();
    } else {
        qDebug() << "Can not open source file";
    }
    return a.exec();
}
