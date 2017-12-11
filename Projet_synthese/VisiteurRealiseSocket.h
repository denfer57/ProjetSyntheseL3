#pragma once
#include <string>
#include "VisiteurXML.h"

class VisiteurRealiseSocket : public VisiteurXML {
private:
	string _adresseServeur;
	int _portServeurDessin;

	void envoi(const string &texte);
public :
	VisiteurRealiseSocket(const string & IP, int port);

	int getPort() { return _portServeurDessin; }
	const string & getIP() { return _adresseServeur; }

	void setIP(const string & IP) { _adresseServeur = IP; }
	void setPort(int port) { _portServeurDessin = port; }

	void visite(Cercle * c);
	void visite(Segment * s);
	void visite(Polygone * p);
	void visite(Groupe * g);
};
