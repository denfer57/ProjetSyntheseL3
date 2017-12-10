#include <iostream>
#include <string>
#include "Erreur.h"
#include "ConnectionSocket.h"

void main()
{
	try
	{
		string adresseServeur = "127.0.0.1";
		int portServeurDessin = 8091;

	}
	catch (Erreur e)
	{
		cerr << e << endl;
	}

}


