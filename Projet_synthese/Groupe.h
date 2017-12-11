#pragma once
#include <vector>
#include "Forme.h"

class Groupe : public Forme {
private :
	vector<Forme *> listeFormes;

public :
	Groupe();
	virtual ~Groupe();

	int getNombreForme();

	void formeNonGroupee();
	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);

	void visite(Visiteur * v);

	double calculAire();
};