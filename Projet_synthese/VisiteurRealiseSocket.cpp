#include "VisiteurRealiseSocket.h"

VisiteurRealiseSocket::VisiteurRealiseSocket(const string & IP, int port): _adresseServeur(IP), _portServeurDessin(port) { }

int VisiteurRealiseSocket::getPort()
{
	return _portServeurDessin;
}

const string VisiteurRealiseSocket::getIP()
{
	return _adresseServeur;
}

void VisiteurRealiseSocket::setIP(const string & IP)
{
	_adresseServeur = IP;
}

void VisiteurRealiseSocket::setPort(int port)
{
	_portServeurDessin = port;
}


