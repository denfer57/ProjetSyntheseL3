#pragma once
#include "Couleur.h"
#include "Point.h"
class Visiteur;

class Forme {
	// du coup on peut acc�der � la variable "estDanGroupe" depuis groupe
	friend class Groupe;
private :
	Couleur _couleur;
	string _nom;
	bool  estDansGroupe;
public:
	Forme();
};