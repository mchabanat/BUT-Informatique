#ifndef MACLASSE_H
#define MACLASSE_H

#include <QObject>

class MaClasse : public QObject
{
    Q_OBJECT
public:
    explicit MaClasse(int num = 0,QObject *parent = nullptr);

    void emettre();
    void quitter();

public slots:
    void recevoir(int);

private:
int _numero;
signals:
    void estEmis(int); // signal : pas de définition dans le cpp
};

#endif // MACLASSE_H
