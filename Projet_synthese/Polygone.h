#pragma once

#include <vector>
#include "Forme.h"

class Polygone : public Forme {
private :
	vector<Point> listesPoints;

public :
	Polygone();
	Polygone(vector<Point> points);

	void visite(Visiteur * v);

};