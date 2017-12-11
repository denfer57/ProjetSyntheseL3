#include "Segment.h"
#include "Visiteur.h"

string Segment::toString() const
{
	ostringstream oss;
	oss << "Segment : { PointA : " << getA() << ", PointB : " << getB() << " }";
	return oss.str();
}

Segment::Segment(Point & a, Point & b) : _a(a), _b(b){ }

Segment::Segment(const Point & a, const Point & b, const Couleur & couleur) : _a(a), _b(b), Forme(couleur) { }

void Segment::setA(const Point & a)
{
	_a = a;
}

void Segment::setB(const Point & b)
{
	_b = b;
}

void Segment::visite(Visiteur *v)
{
	v->visite(this);
}

Segment * Segment::clone() const
{
	return new Segment(*this);
}

void Segment::translation(double translationX, double translationY)
{
	_a.setX(translationX + _a.getX());
	_a.setY(translationY + _a.getY());
	_b.setX(translationX + _b.getX());
	_b.setY(translationY + _b.getY());
}

void Segment::homothetie(const Point & p, double rapport)
{
	// a
	double distPX = abs(_a.getX() - p.getX());
	double distPY = abs(_a.getY() - p.getY());
	_a.setX(p.getX() + (distPX*rapport));
	_a.setY(p.getY() + (distPY*rapport));

	// b
	distPX = abs(_b.getX() - p.getX());
	distPY = abs(_b.getY() - p.getY());
	_b.setX(p.getX() + (distPX*rapport));
	_b.setY(p.getY() + (distPY*rapport));
}

void Segment::rotation(const Point & p, double angle)
{
	// Traitement de a
	// Calcul des distances entre le centre de rotation et le centre du point à faire tourner
	double distPX = abs(_a.getX() - p.getX());
	double distPY = abs(_a.getY() - p.getY());

	// Conversion de l'angle en radians
	double angleRad = angle * (3.141592 / 180);

	// Calcul de la distance entre le nouvel emplacement du point après rotation et le centre de rotation
	double distDeplX = cos(angleRad)*distPX - sin(angleRad)*distPY;
	double distDeplY = sin(angleRad)*distPX + cos(angleRad)*distPY;

	// On met les coordonnées à jour
	_a.setX(p.getX() + distDeplX);
	_a.setY(p.getY() + distDeplY);

	// Traitement de b
	// Calcul des distances entre le centre de rotation et le centre du point à faire tourner
	distPX = abs(_b.getX() - p.getX());
	distPY = abs(_b.getY() - p.getY());

	// Conversion de l'angle en radians
	angleRad = angle * (3.141592 / 180);

	// Calcul de la distance entre le nouvel emplacement du point après rotation et le centre de rotation
	distDeplX = cos(angleRad)*distPX - sin(angleRad)*distPY;
	distDeplY = sin(angleRad)*distPX + cos(angleRad)*distPY;

	// On met les coordonnées à jour
	_b.setX(p.getX() + distDeplX);
	_b.setY(p.getY() + distDeplY);

}

double Segment::calculAire()
{
	return 0;
}
