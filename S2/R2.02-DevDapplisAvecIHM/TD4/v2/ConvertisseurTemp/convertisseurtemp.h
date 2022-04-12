#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class ConvertisseurTemp; }
QT_END_NAMESPACE

class ConvertisseurTemp : public QMainWindow
{
    Q_OBJECT

public:
    ConvertisseurTemp(QWidget *parent = nullptr);
    ~ConvertisseurTemp();

public slots:
    void convertir();
    void effacer();
    void activerConvertir();
    //BUT : rend actif le bouton convertir
    void aProposDe();

private:
    Ui::ConvertisseurTemp *ui;
};
#endif // CONVERTISSEURTEMP_H
