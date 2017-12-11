#include "Couleur.h"

Couleur::Couleur(int rouge, int vert, int bleu)
{
	setRouge(rouge);
	setVert(vert);
	setBleu(bleu);
}

Couleur::Couleur(const string & hexa)
{
	if(hexa.length() != 7)
		throw Erreur("La couleur hexa doit comporter exactement 7 caractères");
	//Le premier caractère doit être un #
	if (hexa.at(0) != '#')
		throw Erreur("La couleur hexa doit commencer par un #");
	//Tout est bon, on convertit
	int r = stoi(hexa.substr(1, 2), 0, 16); // 2 premiers pour le rouge
	int v = stoi(hexa.substr(3, 2), 0, 16); // 2 du milieu pour le vert
	int b = stoi(hexa.substr(5, 2), 0, 16); // 2 derniers pour le bleu

	setRouge(r);
	setBleu(b);
	setVert(v);
}

Couleur::operator string() const
{
	ostringstream os;

	os.fill('0'); os.width(3); os << getRouge() << ".";
	os.fill('0'); os.width(3); os << getVert() << ".";
	os.fill('0'); os.width(3); os << getBleu();

	return os.str();
}

bool Couleur::operator==(const Couleur & couleur) const
{
	return (_rouge == couleur._rouge) && (_bleu == couleur._bleu) && (_vert == couleur._vert);
}

const Couleur & Couleur::Black = Couleur(0, 0, 0);
const Couleur & Couleur::Blue = Couleur(0, 0, 255);
const Couleur & Couleur::Red = Couleur(255, 0, 0);
const Couleur & Couleur::Green = Couleur(0, 255, 0);
const Couleur & Couleur::Yellow = Couleur(255, 255, 0);
const Couleur & Couleur::Cyan = Couleur(0, 255, 255);

ostream & operator<<(ostream & os, const Couleur & couleur)
{
	// TODO: insérer une instruction return ici
	return os << string(couleur);
}
