#pragma once

#include "Forme.h"
 
class Cercle : public Forme {
private:
	Point _milieu;
	double _rayon;
public :
	Cercle(const Point & milieu, double rayon);
	Cercle(const Point & centre, double rayon, const Couleur & couleur);

	const Point & getMilieu();
	double getRayon();
	
	void setMilieu(const Point & milieu);
	void setRayon(double rayon);

	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);

	void visite(Visiteur * v);

	double calculAire();

	Cercle * clone() const;
};