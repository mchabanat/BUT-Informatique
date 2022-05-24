#ifndef TESTSELECTBDD_H
#define TESTSELECTBDD_H

#include <QMainWindow>
#include <QtWidgets>
#include "database.h"
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class TestSelectBDD; }
QT_END_NAMESPACE

class TestSelectBDD : public QMainWindow
{
    Q_OBJECT

public:
    TestSelectBDD(QWidget *parent = nullptr);
    ~TestSelectBDD();

private:
    Ui::TestSelectBDD *ui;
};
#endif // TESTSELECTBDD_H
