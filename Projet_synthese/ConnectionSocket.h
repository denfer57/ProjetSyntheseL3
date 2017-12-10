#pragma once
#include <string>
#include <WinSock2.h>

using namespace std;

class ConnectionSocket
{
private :
	static ConnectionSocket * instanceUnique;
	SOCKET _socket;
	bool _estConnecte;
	ConnectionSocket();
	virtual ~ConnectionSocket();
public:
	static ConnectionSocket * getInstance();
	
	void connecter(const string &IP, int port);
	void deconnecter();
	void envoyer(const string &texte);
};

