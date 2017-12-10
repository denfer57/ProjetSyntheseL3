#pragma once
#include <string>
#include "Visiteur.h"


class VisiteurRealiseSocket {
private:
	string _adresseServeur;
	int _portServeurDessin;

public :
	VisiteurRealiseSocket(const string & IP, int port);

	int getPort();
	const string getIP();

	void setIP(const string & IP);
	void setPort(int port);
};
