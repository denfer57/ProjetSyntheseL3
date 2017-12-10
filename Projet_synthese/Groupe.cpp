#include "Groupe.h"

Groupe::Groupe(){ }

Groupe::~Groupe()
{
	formeNonGroupee();
}

void Groupe::formeNonGroupee()
{
	for (vector<Forme *>::iterator iterateur = listeFormes.begin(); iterateur != listeFormes.end(); ++iterateur)
		(*iterateur)->estDansGroupe = false;
}
