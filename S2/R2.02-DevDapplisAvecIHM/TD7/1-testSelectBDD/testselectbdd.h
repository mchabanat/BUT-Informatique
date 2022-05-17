#ifndef TESTSELECTBDD_H
#define TESTSELECTBDD_H

#include <QMainWindow>
#include <QtWidgets>
#include "database.h"
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class testSelectBDD; }
QT_END_NAMESPACE

class testSelectBDD : public QMainWindow
{
    Q_OBJECT

public:
    testSelectBDD(QWidget *parent = nullptr);
    ~testSelectBDD();

private:
    Ui::testSelectBDD *ui;
    Database *db;
};
#endif // TESTSELECTBDD_H
