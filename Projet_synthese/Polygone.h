#pragma once

#include <vector>
#include "Forme.h"

class Polygone : public Forme {
private :
	vector<Point> listesPoints;
public :
	string toString() const;
	Polygone();
	Polygone(vector<Point> points);
	Polygone(const Couleur & couleur);

	int getNombrePoints();
	void visite(Visiteur * v);
	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);
	double calculAire();
	void ajoutePoint(Point & p);

	Point operator[](int pos) const;
	Polygone * clone() const;
};