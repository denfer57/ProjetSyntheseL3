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
	system("Pause");
}

Forme * faitDessin() {
	//Cercle OK, Segment OK
	//Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Cyan);
	Segment * s = new Segment(Point(300, 300), Point(300, 400), Couleur("#0000FF"));
	return s;
}

void testDessin(Forme * dessin) {
	cout << "Veuillez patientez, affichage du dessin..." << endl;
	VisiteurRealiseSocket * visiteurRealiseSocket = new VisiteurRealiseSocket("127.0.0.1", 8091);
	dessin->visite(visiteurRealiseSocket);
}



