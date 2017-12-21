#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
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

