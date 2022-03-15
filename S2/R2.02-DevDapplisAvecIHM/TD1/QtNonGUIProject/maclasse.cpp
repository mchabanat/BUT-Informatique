#include "maclasse.h"
#include <iostream>
using namespace std;

MaClasse::MaClasse(int num, QObject *parent) : QObject(parent),
                                               _numero(num)
{
    cout << "Creation de " << _numero << endl;
}

void MaClasse::emettre()
{
    cout << "Moi, " << _numero << ", j'emets un signal " << endl;
    emit estEmis(_numero);
}

void MaClasse::recevoir(int num)
{
    cout << "Moi, " << _numero << ", j''emets un signal'ai recu le signal " << num << endl;
}

void MaClasse::quitter()
{

}


