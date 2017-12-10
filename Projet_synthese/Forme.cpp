#include "Forme.h"
//couleur par défaut bleu
Forme::Forme() : _couleur(Couleur::Blue), estDansGroupe(false) { }

Forme::Forme(const Couleur & couleur) : _couleur(couleur), estDansGroupe(false) { }

Forme::Forme(const Forme & forme) : _couleur(forme._couleur), estDansGroupe(false) { }

const Couleur & Forme::getCouleur()
{
	// TODO: insérer une instruction return ici
	return _couleur;
}

void Forme::setCouleur(const Couleur & couleur)
{
	_couleur = couleur;
}

