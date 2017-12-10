#pragma once
#include <string>
#include "Erreur.h"
#include <sstream>
using namespace std;
class Couleur {
private:
	// 0 a 255
	unsigned char _rouge, _bleu, _vert;
public:
	Couleur(int rouge, int vert, int bleu);
	Couleur(const string &hexa);

	int const getRouge() const;
	int const getBleu() const;
	int const getVert() const;

	void setRouge(int rouge);
	void setBleu(int bleu);
	void setVert(int vert);

	virtual operator string() const;
	friend ostream & operator<<(ostream & os, const Couleur & couleur);
	virtual bool operator==(const Couleur & couleur) const;

	//Une forme géométrique est caractérisée par une couleur parmi "black", "blue", "red", "green", "yellow" et "cyan"
	static const Couleur & Black;
	static const Couleur & Blue;
	static const Couleur & Red;
	static const Couleur & Green;
	static const Couleur & Yellow;
	static const Couleur & Cyan;
};

inline int const Couleur::getRouge() const
{
	return _rouge;
}

inline int const Couleur::getBleu() const
{
	return _bleu;
}

inline int const Couleur::getVert() const
{
	return _vert;
}

inline void Couleur::setRouge(int rouge)
{
	if (rouge < 0 && rouge > 255)
		Erreur("La valeur doit être comprise entre 0 et 255");
	_rouge = rouge;
}

inline void Couleur::setBleu(int bleu)
{
	if(bleu < 0 && bleu > 255)
		Erreur("La valeur doit être comprise entre 0 et 255");
	_bleu = bleu;
}

inline void Couleur::setVert(int vert)
{
	if(vert < 0 && vert > 255)
		Erreur("La valeur doit être comprise entre 0 et 255");
	_vert = vert;
}