#include "Groupe.h"
#include "Visiteur.h"

string Groupe::toString() const
{
	ostringstream oss;
	oss << "Groupe : { Formes : { ";
	int nbFormes = listeFormes.size();
	for (int i = 0; i < nbFormes; i++)
	{
		oss << listeFormes[i]->toString();
		oss << ", Couleur : " << listeFormes[i]->getCouleur();
		if (nbFormes > i + 1)
			oss << " / ";
		else oss << " } ";
	}
	return oss.str();
}

Groupe::Groupe(){ }

Groupe::~Groupe()
{
	formeNonGroupee();
}

int Groupe::getNombreForme()
{
	return listeFormes.size();
}

void Groupe::formeNonGroupee()
{
	for (vector<Forme *>::iterator iterateur = listeFormes.begin(); iterateur != listeFormes.end(); ++iterateur)
		(*iterateur)->estDansGroupe = false;
}

void Groupe::translation(double translationX, double translationY)
{
	vector<Forme *>::iterator it;
	Forme * formeCourante;
	for (it = listeFormes.begin(); it != listeFormes.end(); it++) {
		formeCourante = *it;
		formeCourante->translation(translationX, translationY);
	}
}

void Groupe::homothetie(const Point & p, double rapport)
{
	vector<Forme *>::iterator it;
	Forme * formeCourante;
	for (it = listeFormes.begin(); it != listeFormes.end(); it++) {
		formeCourante = *it;
		formeCourante->homothetie(p, rapport);
	}
}

void Groupe::rotation(const Point & p, double angle)
{
	vector<Forme *>::iterator it;
	Forme * formeCourante;
	for (it = listeFormes.begin(); it != listeFormes.end(); it++) {
		formeCourante = *it;
		formeCourante->rotation(p, angle);
	}
}

void Groupe::visite(Visiteur *v)
{
	v->visite(this);
}

double Groupe::calculAire()
{
	double aireGroupe = 0;
	vector<Forme *>::iterator it;
	Forme * formeCourante;
	for (it = listeFormes.begin(); it != listeFormes.end(); it++) {
		formeCourante = *it;
		aireGroupe += formeCourante->calculAire();
	}
	return aireGroupe;
}

void Groupe::ajouteForme(Forme * f)
{
	//tester si elle existe deja
	listeFormes.push_back(f);
}

Forme * Groupe::operator[](int pos) const
{
	return listeFormes[pos];
}

Groupe * Groupe::clone() const
{
	return new Groupe(*this);;
}

