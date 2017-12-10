#include "Cercle.h"
#include "Visiteur.h"

Cercle::Cercle(const Point & milieu, double rayon) : _milieu(milieu), _rayon(rayon){ }

Cercle::Cercle(const Point & centre, double rayon, const Couleur & couleur) : _milieu(centre), _rayon(rayon), Forme(couleur) { }

const Point & Cercle::getMilieu()
{
	// TODO: insérer une instruction return ici
	return _milieu;
}

double Cercle::getRayon()
{
	return _rayon;
}

void Cercle::setMilieu(const Point & milieu)
{
	_milieu = milieu;
}

void Cercle::setRayon(double rayon)
{
	_rayon = rayon;
}

void Cercle::visite(Visiteur *v)
{
	v->visite(this);
}

Cercle * Cercle::clone() const
{
	return new Cercle(*this);
}