#include "testselectbdd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testSelectBDD w;
    w.show();
    return a.exec();
}
