// Constructeurs
Cercle::Cercle():
    m_x(20),
    m_y(20),
    m_rayon(10),
    m_couleur(0,0,255)
{
}

Cercle::Cercle(const Cercle& original):
    m_x(original.m_x),
    m_y(original.m_y),
    m_rayon(original.m_rayon),
    m_couleur(original.m_couleur)
{
}

Cercle::Cercle(int x, int y, int rayon, Couleur coul):
    m_x(x),
    m_y(y),
    m_rayon(rayon),
    m_couleur(coul)
{
}

// Methodes
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
