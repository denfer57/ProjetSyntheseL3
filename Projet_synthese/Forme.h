#pragma once
#include <math.h>
#include "Couleur.h"
#include "Point.h"
class Visiteur;

class Forme {
	// du coup on peut accéder à la variable "estDanGroupe" depuis groupe
	friend class Groupe;
private :
	Couleur _couleur;
	bool  estDansGroupe;
public:
	Forme();
	Forme(const Couleur & couleur);
	Forme(const Forme & forme);

	const Couleur & getCouleur();

	void setCouleur(const Couleur & couleur);

	virtual void visite(Visiteur *v) = 0;
	virtual void translation(double translationX, double translationY) = 0;
	virtual void homothetie(const Point & p, double rapport) = 0;
	virtual void rotation(const Point & p, double angle) = 0;
	virtual double calculAire() = 0;

	virtual Forme * clone() const = 0;
};