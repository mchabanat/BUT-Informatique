#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QtWidgets> // Inclus tous les widgets de qt5


class ConvertisseurTemp : public QWidget
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
    ConvertisseurTemp(QWidget *parent = nullptr);
    ~ConvertisseurTemp();

public slots:
    void convertir();
    void effacer();


};
#endif // CONVERTISSEURTEMP_H
