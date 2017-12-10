#pragma once

#include "Forme.h"
 
class Cercle : public Forme {
private:
	Point _milieu;
	double _rayon;
public :
	Cercle(const Point & milieu, double rayon);

	/* a faire
	void visite(Visiteur * v);
	void translation(const Vecteur & v);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);
	*/
};