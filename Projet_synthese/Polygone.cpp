#include "Polygone.h"
#include "Visiteur.h"

Polygone::Polygone(){ }

Polygone::Polygone(vector<Point> points) : listesPoints(points){ }

string Polygone::toString() const
{
	ostringstream oss;
	oss << " : { { ";
	int taille = listesPoints.size();
	for (int i = 0; i < taille; i++)
	{
		oss << listesPoints[i];
		if (taille > i + 1)
			oss << ",";
		oss << " ";
	}
	oss << "}, Couleur : " << getCouleur() << " }";
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
	for (it = listesPoints.begin(); it != listesPoints.end(); it++) {
		pointCourant = *it;
		pointCourant.setX(translationX + pointCourant.getX());
		pointCourant.setY(translationY + pointCourant.getY());
	}
}

void Polygone::homothetie(const Point & p, double rapport)
{
	vector<Point>::iterator it;
	Point pointCourant;
	double distPX, distPY;
	for (it = listesPoints.begin(); it != listesPoints.end(); it++) {
		pointCourant = *it;
		distPX = abs(pointCourant.getX() - p.getX());
		distPY = abs(pointCourant.getY() - p.getY());
		pointCourant.setX(p.getX() + (distPX*rapport));
		pointCourant.setY(p.getY() + (distPY*rapport));
	}
}

void Polygone::rotation(const Point & p, double angle)
{
	vector<Point>::iterator it;
	Point pointCourant;
	double distPX, distPY, angleRad, distDeplX, distDeplY;
	for (it = listesPoints.begin(); it != listesPoints.end(); it++) {
		pointCourant = *it;
		// Calcul des distances entre le centre de rotation et le centre du cercle à faire tourner
		distPX = abs(pointCourant.getX() - p.getX());
		distPY = abs(pointCourant.getY() - p.getY());

		// Conversion de l'angle en radians
		angleRad = angle * (3.141592 / 180);

		// Calcul de la distance entre le nouvel emplacement du point après rotation et le centre de rotation
		distDeplX = cos(angleRad)*distPX - sin(angleRad)*distPY;
		distDeplY = sin(angleRad)*distPX + cos(angleRad)*distPY;

		// On met les coordonnées à jour
		pointCourant.setX(p.getX() + distDeplX);
		pointCourant.setY(p.getY() + distDeplY);
	}
}

double Polygone::calculAire()
{
	// Application de la méthode de https://fr.wikihow.com/calculer-la-surface-d%27un-polygone #3
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
	aireGlobale = (xFirst - yFirst) / 2;
	return aireGlobale;
}