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
	//Cercle OK, Segment OK, Polygone OK
	//Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Yellow);
	//Segment * s = new Segment(Point(300, 300), Point(300, 400), Couleur("#0000FF"));
	Polygone * p = new Polygone(Couleur::Cyan);
	p->ajoutePoint(Point(80, 100));
	p->ajoutePoint(Point(130, 100));
	p->ajoutePoint(Point(105, 50)); 
	return p;
}

void testDessin(Forme * dessin) {
	cout << "Veuillez patientez, affichage du dessin..." << endl;
	VisiteurRealiseSocket * visiteurRealiseSocket = new VisiteurRealiseSocket("127.0.0.1", 8091);
	dessin->visite(visiteurRealiseSocket);
}



