#include "Cercle.h"
#include "Visiteur.h"

Cercle::Cercle(const Point & milieu, double rayon) : _milieu(milieu), _rayon(rayon){ }

Cercle::Cercle(const Point & centre, double rayon, const Couleur & couleur) : _milieu(centre), _rayon(rayon), Forme(couleur) { }

string Cercle::toString() const
{
	ostringstream oss;
	oss << "Cercle : { Centre : " << getMilieu() << ", Rayon : " << getRayon()  << " }";
	return oss.str();
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

void Cercle::translation(double translationX, double translationY)
{
	_milieu.setX(translationX + _milieu.getX());
	_milieu.setY(translationY + _milieu.getY());
}

void Cercle::homothetie(const Point & p, double rapport)
{
	double distPX = abs(_milieu.getX() - p.getX());
	double distPY = abs(_milieu.getY() - p.getY());
	_milieu.setX(p.getX() + (distPX*rapport));
	_milieu.setY(p.getY() + (distPY*rapport));
	_rayon = _rayon*rapport;
}

void Cercle::rotation(const Point & p, double angle)
{
	// Calcul des distances entre le centre de rotation et le centre du cercle à faire tourner
	double distPX = abs(_milieu.getX() - p.getX());
	double distPY = abs(_milieu.getY() - p.getY());

	// Conversion de l'angle en radians
	double angleRad = angle * (3.141592 / 180);

	// Calcul de la distance entre le nouvel emplacement du point après rotation et le centre de rotation
	double distDeplX = cos(angleRad)*distPX - sin(angleRad)*distPY;
	double distDeplY = sin(angleRad)*distPX + cos(angleRad)*distPY;

	// On met les coordonnées à jour
	_milieu.setX(p.getX() + distDeplX);
	_milieu.setY(p.getY() + distDeplY);
}

double Cercle::calculAire()
{
	return (_rayon * _rayon * 3.141592);
}