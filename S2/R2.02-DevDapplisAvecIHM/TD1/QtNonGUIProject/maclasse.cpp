#include "maclasse.h"
#include <iostream>
using namespace std;

MaClasse::MaClasse(int num, QObject *parent) :
    QObject(parent),
    _numero(num)
{
    cout << "Creation de " << num << endl;
}

void MaClasse::emettre()
{
    cout << "Moi, " << _numero << ", j'emets un signal" << endl;
    emit estEmis(_numero);
}

int MaClasse::getNumero()
{
    return _numero;
}

void MaClasse::quit()
{

}

void MaClasse::recevoir(int num)
{
    cout << "Moi, " << _numero << ", j'ai recu le signal " << num << endl;
}
