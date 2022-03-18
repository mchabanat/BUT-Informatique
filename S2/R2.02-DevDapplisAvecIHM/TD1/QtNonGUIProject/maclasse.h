#ifndef MACLASSE_H
#define MACLASSE_H

#include <QObject>

class MaClasse : public QObject
{
    Q_OBJECT
public:
    explicit MaClasse(int num, QObject *parent = nullptr);
    void emettre();
    int getNumero();
    void quit();

public slots:
    void recevoir(int);

signals:
    void  estEmis(int); // Pas de definition

private:
    int _numero; // rang de creation de l'objet



};

#endif // MACLASSE_H
