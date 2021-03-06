#include "Polygone.h"
#include "Visiteur.h"

Polygone::Polygone(){ }

Polygone::Polygone(vector<Point> points) : listesPoints(points){ }

Polygone::Polygone(const Couleur & couleur) : Forme(couleur) { }

string Polygone::toString() const
{
	ostringstream oss;
	oss << "Polygone : { Points : { ";
	int taille = listesPoints.size();
	for (int i = 0; i < taille; i++)
	{
		oss << listesPoints[i];
		if (taille > i + 1)
			oss << ",";
		oss << " ";
	}
	oss << "}";
	return oss.str();
}

int Polygone::getNombrePoints()
{
	return listesPoints.size();
}

void Polygone::visite(Visiteur *v)
{
	v->visite(this);
}

void Polygone::translation(double translationX, double translationY)
{
	vector<Point>::iterator it;
	Point pointCourant;
	double valeurX, valeurY;
	for (it = listesPoints.begin(); it != listesPoints.end(); it++) {
		pointCourant = *it;
		valeurX =pointCourant.getX() + translationX;
		valeurY =pointCourant.getY() + translationY;
		pointCourant.setX(valeurX);
		pointCourant.setY(valeurY);
        *it = pointCourant;
	}
}

void Polygone::homothetie(const Point & p, double rapport)
{
	vector<Point>::iterator it;
	Point pointCourant;
	double distPX, distPY;
	for (it = listesPoints.begin(); it != listesPoints.end(); it++) {
		pointCourant = *it;
		distPX = pointCourant.getX() - p.getX();
		distPX = abs(distPX);
		distPY = pointCourant.getY() - p.getY();
		distPY = abs(distPY);
		pointCourant.setX(p.getX() + (distPX*rapport));
		pointCourant.setY(p.getY() + (distPY*rapport));
        *it = pointCourant;
	}
}

void Polygone::rotation(const Point & p, double angle)
{
	vector<Point>::iterator it;
	Point pointCourant;
	double distPX, distPY, angleRad, distDeplX, distDeplY;
	for (it = listesPoints.begin(); it != listesPoints.end(); it++) {
		pointCourant = *it;
		// Calcul des distances entre le centre de rotation et le centre du cercle � faire tourner
		distPX = pointCourant.getX() - p.getX();
		distPX = abs(distPX);
		distPY = pointCourant.getY() - p.getY();
		distPY = abs(distPY);

		// Conversion de l'angle en radians
		angleRad = angle * (3.141592 / 180);

		// Calcul de la distance entre le nouvel emplacement du point apr�s rotation et le centre de rotation
		distDeplX = cos(angleRad)*distPX - sin(angleRad)*distPY;
		distDeplY = sin(angleRad)*distPX + cos(angleRad)*distPY;

		// On met les coordonn�es � jour
		pointCourant.setX(p.getX() + distDeplX);
		pointCourant.setY(p.getY() + distDeplY);
        *it = pointCourant;
	}
}

double Polygone::calculAire()
{
	// Application de la m�thode de https://fr.wikihow.com/calculer-la-surface-d%27un-polygone #3
	vector<Point>::iterator itXFirst;
	vector<Point>::iterator itYFirst;
	Point pointCourantX, pointCourantY, pointSuivantX, pointSuivantY;
	double xFirst = 0, yFirst = 0, aireGlobale = 0;
	itXFirst = listesPoints.begin();
	itYFirst = listesPoints.begin();
	while (itXFirst != listesPoints.end()) {
		pointCourantX = *itXFirst;
		pointCourantY = *itYFirst;
		itXFirst++;
		itYFirst++;
		if (itXFirst != listesPoints.end())
		{
			pointSuivantX = *itXFirst;
		}
		if (itYFirst != listesPoints.end())
		{
			pointSuivantY = *itYFirst;
		}
		xFirst += (pointCourantX.getX()*pointSuivantY.getY());
		yFirst += (pointCourantY.getY()*pointSuivantX.getX());
	}
	xFirst = abs(xFirst);
	yFirst = abs(yFirst);
	aireGlobale = (yFirst - xFirst) / 2;
	return aireGlobale;
}

void Polygone::ajoutePoint(Point & p)
{
	//tester s'il existe deja
	listesPoints.push_back(p);
}

Point Polygone::operator[](int pos) const
{
	return listesPoints[pos];
}

Polygone * Polygone::clone() const
{
	return new Polygone(*this);
}
