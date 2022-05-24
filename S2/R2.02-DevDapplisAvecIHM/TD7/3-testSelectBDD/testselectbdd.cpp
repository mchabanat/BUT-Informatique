#include "testselectbdd.h"
#include "ui_testselectbdd.h"

TestSelectBDD::TestSelectBDD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestSelectBDD)
{
    ui->setupUi(this);
}

TestSelectBDD::~TestSelectBDD()
{
    delete ui;
}

