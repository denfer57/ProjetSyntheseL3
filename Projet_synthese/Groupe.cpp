#include "Groupe.h"
#include "Visiteur.h"

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
	double aireGroupe;
	vector<Forme *>::iterator it;
	Forme * formeCourante;
	for (it = listeFormes.begin(); it != listeFormes.end(); it++) {
		formeCourante = *it;
		aireGroupe += formeCourante->calculAire();
	}
	return aireGroupe;
}

