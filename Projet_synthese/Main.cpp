#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string>
#include <cmath>
#include<winsock2.h>

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
void testCouleur();
void testCercle();
void testSegment();
void testPolygone();
void testGroupe();

int main()
{
	//bugs :
	//translation, homothétie, aire -> polygone
	Forme * dessin = faitDessin();
	//testDessin(dessin);
	testCouleur();
	testCercle();
	testSegment();
	testPolygone();
	testGroupe();
	system("Pause");
	return (0);
}

Forme * faitDessin() {
	Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Yellow);

	Segment * s = new Segment(Point(300, 300), Point(300, 400), Couleur("#0000FF"));

	Polygone * p = new Polygone(Couleur::Cyan);
	Point p1 = Point(80, 100);
	Point p2 = Point(130, 100);
	Point p3 = Point(105, 50);
	p->ajoutePoint(p1);
	p->ajoutePoint(p2);
	p->ajoutePoint(p3);

	Groupe * g = new Groupe();

	g->ajouteForme(c);
	g->ajouteForme(s);
	g->ajouteForme(p);

	return g;
}

void testDessin(Forme * dessin) {
	cout << "Veuillez patientez, affichage du dessin..." << endl;
	VisiteurRealiseSocket * visiteurRealiseSocket = new VisiteurRealiseSocket("127.0.0.1", 8091);
	dessin->visite(visiteurRealiseSocket);
}

void testCercle() {
	Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Yellow);
	cout << c->toString() << "\n";
	cout << "Aire de c : " << c->calculAire() << "\n";
	cout << "Couleur : " << c->getCouleur() << "\n";

	cout << "Translation... " << "\n";
	c->translation(100, 100);
	cout << c->toString() << "\n";

	double coeffient = 2;
	c->homothetie(Point(300, 300), 2);
	cout << "Zoom c * " << coeffient << "\n";
	cout << c->toString() << "\n";
}

void testSegment(){
	Segment * s = new Segment(Point(300, 300), Point(300, 400), Couleur("#0000FF"));
	cout << s->toString() << "\n";
	cout << "Aire de s : " << s->calculAire() << "\n";
	cout << "Couleur : " << s->getCouleur() << "\n";

	cout << "Translation..." << "\n";
	s->translation(300, 300);
	cout << s->toString() << "\n";

	double angle = 180;
	s->rotation(Point(300, 300), angle);
	cout << "Rotation s de " << angle << " degre \n";
	cout << s->toString() << "\n";

	double coeffient = 2;
	s->homothetie(Point(300, 300), coeffient);
	cout << "Zoom s * " << coeffient << "\n";
	cout << s->toString() << "\n";
}

void testPolygone() {
	Polygone * p = new Polygone(Couleur::Cyan);
	Point p1 = Point(80, 100);
	Point p2 = Point(130, 100);
	Point p3 = Point(105, 50);
	p->ajoutePoint(p1);
	p->ajoutePoint(p2);
	p->ajoutePoint(p3);

	cout << p->toString() << "\n";
	cout << "Aire de p : " << p->calculAire() << "\n";
	cout << "Couleur : " << p->getCouleur() << "\n";

	cout << "Translation..." << "\n";
	p->translation(300, 300);
	cout << p->toString() << "\n";

	double angle = 180;
	p->rotation(Point(300, 300), angle);
	cout << "Rotation p de " << angle << " degre \n";
	cout << p->toString() << "\n";

	double coeffient = 2;
	p->homothetie(Point(300, 300), coeffient);
	cout << "Zoom p * " << coeffient << "\n";
	cout << p->toString() << "\n";
}

void testGroupe() {
	Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Yellow);

	Segment * s = new Segment(Point(300, 300), Point(300, 400), Couleur("#0000FF"));

	Polygone * p = new Polygone(Couleur::Cyan);
    Point p1 = Point(80, 100);
	Point p2 = Point(130, 100);
	Point p3 = Point(105, 50);
	p->ajoutePoint(p1);
	p->ajoutePoint(p2);
	p->ajoutePoint(p3);

	Groupe * g = new Groupe();

	g->ajouteForme(c);
	g->ajouteForme(s);
	g->ajouteForme(p);

	cout << g->toString() << "\n";
	cout << "Aire de g : " << g->calculAire() << "\n";
}

void testCouleur()
{
	try
	{
		Couleur rouge(0xFF, 0x0, 0x0);
		Couleur vert(0, 255, 0);
		Couleur bleu(0, 0, 255);
		Couleur cyan(0x99, 0xFF, 0xFF);
		Couleur jaunevert("#CCFF00");

		cout << "Rouge : " << rouge << endl;
		cout << "Vert : " << vert << endl;
		cout << "Bleu : " << bleu << endl;
		cout << "Bleu clair : " << cyan << endl;
		cout << "Jaune-Vert : " << jaunevert << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}



