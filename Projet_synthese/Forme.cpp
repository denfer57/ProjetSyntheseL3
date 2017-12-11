#include "Forme.h"
//couleur par défaut bleu
Forme::Forme() : _couleur(Couleur::Blue), estDansGroupe(false) { }

Forme::Forme(const Couleur & couleur) : _couleur(couleur), estDansGroupe(false) { }

Forme::Forme(const Forme & forme) : _couleur(forme._couleur), estDansGroupe(false) { }

void Forme::setCouleur(const Couleur & couleur)
{
	_couleur = couleur;
}

Forme::operator string() const
{
	return toString();
}

ostream & operator<<(ostream & os, const Forme & forme)
{
	return os << string(forme);
}
