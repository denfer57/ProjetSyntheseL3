#pragma once
#include "Visiteur.h"
//d'apres le schéma, mais devrait s'appeller visiteurTexte
class VisiteurXML : public Visiteur
{
protected:
	string chercheForme(Forme * f);
	string envoiInfos(Cercle * c);
	string envoiInfos(Segment * s);
	string envoiInfos(Polygone * p);
	string envoiInfos(Groupe * g);

public:
	virtual void visite(Cercle * c) = 0;
	virtual void visite(Segment * s) = 0;
	virtual void visite(Polygone * p) = 0;
	virtual void visite(Groupe * g) = 0;
};