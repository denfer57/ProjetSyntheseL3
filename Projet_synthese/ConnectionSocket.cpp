#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

#include "Erreur.h"
#include "ConnectionSocket.h"

ConnectionSocket * ConnectionSocket::instanceUnique = NULL;

ConnectionSocket * ConnectionSocket::getInstance()
{
	if (instanceUnique == NULL)
		instanceUnique = new ConnectionSocket();
	return instanceUnique;
}

ConnectionSocket::~ConnectionSocket()
{
	//libère la lib winsock
	WSACleanup();
}

ConnectionSocket::ConnectionSocket() : _estConnecte(false)
{
	// Initialisation de WinSock
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		throw Erreur("Echec lors de l'initialisation de WinSock.");
}

void ConnectionSocket::connecter(const string & IP, int port)
{
	if (_estConnecte == true)
		deconnecter();
	// Définition du protocole
	int familleAdresses = AF_INET;	// IPv4
	int typeSocket = SOCK_STREAM;	// mode connecté TCP
	int protocole = IPPROTO_TCP;	// protocole
	// Création du socket
	_socket = socket(familleAdresses, typeSocket, protocole);
	if (_socket == INVALID_SOCKET)
		throw Erreur("Echec lors de la création du socket.");

	// Spécifie les informations de connexion au socket
	SOCKADDR_IN sockAddr;
	sockAddr.sin_family = familleAdresses;
	sockAddr.sin_addr.s_addr = inet_addr(IP.c_str());// inet_addr() convertit de l'ASCII en entier
	sockAddr.sin_port = htons((short)port);//htons() assure que le port est bien inscrit dans le format du réseau

	// Connexion du socket
	int res = connect(_socket, (sockaddr*)&sockAddr, sizeof(sockaddr));
	if (res == SOCKET_ERROR)
		throw Erreur("Echec lors de la connexion au serveur.");

	_estConnecte = true;
}

void ConnectionSocket::deconnecter()
{
	//coupure de la socket
	if (shutdown(_socket, SD_BOTH) == SOCKET_ERROR)
		throw Erreur("Erreur lors de la coupure de la socket");
	//fermeture de la socket
	if (closesocket(_socket))
		throw Erreur("Erreur lors de la fermeture de la socket");

	_estConnecte = false;
}

void ConnectionSocket::envoyer(const string & texte)
{
	int res = send(_socket, texte.c_str(), texte.length(), 0);
	if (res == SOCKET_ERROR)
		throw Erreur("Erreur de l'envoi du texte");
}
