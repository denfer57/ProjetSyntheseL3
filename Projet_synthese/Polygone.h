#pragma once

#include <vector>
#include "Forme.h"

class Polygone : public Forme {
private :
	vector<Point> listesPoints;

public :
	Polygone();
	Polygone(vector<Point> points);

	string toString() const;

	int getNombrePoints();
	void visite(Visiteur * v);
	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);
	double calculAire();

};