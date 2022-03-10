void Cercle::placer(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

void Cercle::dimensionner(int rayon)
{
    this->m_rayon = rayon;
}

void Cercle::definirCouleur(int r, int g, int b)
{
    this->m_couleur.definir(r,g,b);
}

void Cercle::definirCouleur(Couleur coul)
{
    this->m_couleur.definir(coul.rouge(),coul.vert(),coul.bleu());
}

int Cercle::coordX() const
{
    return this->m_x;
}

int Cercle::coordY() const
{
    return this->m_y;
}

int Cercle::rayon() const
{
    return this->m_rayon;
}

Couleur Cercle::couleur() const
{
    return this->m_couleur;
}

void Cercle::dessiner(Fenetre& f,Couleur c) const
{
    f.choixCouleurTrace(c);
    f.traceArc(this->m_x-this->m_rayon,this->m_y-this->m_rayon,this->m_rayon,this->m_rayon);
}

void Cercle::afficher(Fenetre & f) const
{
    this->dessiner(f,this->m_couleur);
}

void Cercle::effacer(Fenetre & f) const
{
    this->dessiner(f,f.couleurFond());
}

bool Cercle::touche(int x, int y) const
{
    return (x-this->m_coordX)*(x-this->m_coordX) + (y-this->m_coordY)*(y-this->m_coordY) <= (this->m_rayon*this->m_rayon);
}
