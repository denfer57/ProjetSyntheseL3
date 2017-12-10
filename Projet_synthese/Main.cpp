#include <iostream>
#include <string>

#include "Erreur.h"
#include "Couleur.h"
#include "Point.h"
#include "Cercle.h"
#include "Segment.h"
#include "Polygone.h"
#include "Groupe.h"

#include "VisiteurRealiseSocket.h"

#include "ConnectionSocket.h"

Forme * faitDessin();
void testDessin(Forme *);

void main()
{
	Forme * dessin = faitDessin();
	testDessin(dessin);
}

Forme * faitDessin() {
	Cercle * c = new Cercle(Point(300, 300), 50.5, Couleur::Red);
	return c;
}

void testDessin(Forme * dessin) {
	cout << "Veuillez patientez, affichage du dessin..." << endl;
	VisiteurRealiseSocket * visiteurRealiseSocket = new VisiteurRealiseSocket("127.0.0.1", 8091);
//essin->visite(visiteurRealiseSocket);
}



