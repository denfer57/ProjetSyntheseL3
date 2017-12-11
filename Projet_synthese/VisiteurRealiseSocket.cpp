#include "VisiteurRealiseSocket.h"
#include "ConnectionSocket.h"

VisiteurRealiseSocket::VisiteurRealiseSocket(const string & IP, int port): _adresseServeur(IP), _portServeurDessin(port) { }

void VisiteurRealiseSocket::visite(Cercle * c)
{
	envoi(envoiInfos(c));
}

void VisiteurRealiseSocket::visite(Segment * s)
{
	envoi(envoiInfos(s));
}

void VisiteurRealiseSocket::visite(Polygone * p)
{
	envoi(envoiInfos(p));
}

void VisiteurRealiseSocket::visite(Groupe * g)
{
	envoi(envoiInfos(g));
}

void VisiteurRealiseSocket::envoi(const string & texte)
{
	try
	{
		ConnectionSocket * cs = ConnectionSocket::getInstance();
		cs->connecter(getIP(), getPort());
		cs->envoyer(texte);
		cs->deconnecter();
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}
