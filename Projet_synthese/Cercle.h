#pragma once

#include "Forme.h"
 
class Cercle : public Forme {
private:
	string toString() const;
	Point _milieu;
	double _rayon;
public :
	Cercle(const Point & milieu, double rayon);
	Cercle(const Point & centre, double rayon, const Couleur & couleur);

	const Point & getMilieu() const { return _milieu; }
	double getRayon() const { return _rayon; }
	
	void setMilieu(const Point & milieu);
	void setRayon(double rayon);

	void visite(Visiteur * v);
	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);

	double calculAire();

	Cercle * clone() const;
	
};