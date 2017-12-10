#pragma once
#include <vector>
#include "Forme.h"

class Groupe : public Forme {
private :
	vector<Forme *> listeFormes;

public :
	Groupe();
	virtual ~Groupe();

	void Groupe::formeNonGroupee();
};