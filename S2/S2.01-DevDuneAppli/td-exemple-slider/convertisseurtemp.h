#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class convertisseurTemp; }
QT_END_NAMESPACE

class convertisseurTemp : public QMainWindow
{
    Q_OBJECT

public:
    convertisseurTemp(QWidget *parent = nullptr);

    ~convertisseurTemp();

private:
    Ui::convertisseurTemp *ui;
    float convertirToFar(float cels);


private slots:
   void remiseAZero();
   void convertir();
   void aProposDe();
   void sliderrrMoved(int);
   void degresCchanged(const QString &);

};

#endif // CONVERTISSEURTEMP_H
