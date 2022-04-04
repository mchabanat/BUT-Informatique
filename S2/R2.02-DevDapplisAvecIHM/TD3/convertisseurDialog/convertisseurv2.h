#ifndef CONVERTISSEURV2_H
#define CONVERTISSEURV2_H

#include <QtWidgets>
#include <QDialog>

class convertisseurv2 : public QDialog
{
    Q_OBJECT

private:
    QLabel *labelConvertisseur;
    QLabel *labelCels;
    QLabel *labelFgt;
    QLabel *labelResult;
    QLineEdit *inputTemp;
    QPushButton *eraseButton;
    QPushButton *convertButton;
    QPushButton *quitButton;

public:
    convertisseurv2(QWidget *parent = nullptr);
    ~convertisseurv2();

public slots:
    void saisiVerif();
    void convertir();
    void effacer();
};
#endif // CONVERTISSEURV2_H
