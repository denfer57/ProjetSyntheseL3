#include <iostream>
#include <string>
#include <cmath>
#include< winsock2.h>
#include <fstream>

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
void testSauvegarde();
void testChargement();

int main()
{
	Forme * dessin = faitDessin();
	testDessin(dessin);
	//testCouleur();
	//testCercle();
	//testSegment();
	//testPolygone();
	//testGroupe();
	//testSauvegarde();
	//testChargement();
	system("Pause");
	return (0);
}

Forme * faitDessin() {
	/*Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Yellow);

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
	g->ajouteForme(p);*/

	Polygone * T1 = new Polygone(Couleur::Green);
	Point p1T1 = Point(1, 0);
	Point p2T1= Point(4, -2);
	Point p3T1 = Point(4, 2);
	T1->ajoutePoint(p1T1);
	T1->ajoutePoint(p2T1);
	T1->ajoutePoint(p3T1);
	cout << T1->toString() << "\n";

	Cercle * C1 = new Cercle(Point(7, 0), 2, Couleur::Yellow);
	cout << C1->toString() << "\n";

	Polygone * R1 = new Polygone(Couleur::Blue);
	Point p1R1 = Point(11, -1);
	Point p2R1 = Point(15, -1);
	Point p3R1 = Point(15, 1);
	Point p4R1 = Point(11, 1);
	R1->ajoutePoint(p1R1);
	R1->ajoutePoint(p2R1);
	R1->ajoutePoint(p3R1);
	R1->ajoutePoint(p4R1);
	cout << R1->toString() << "\n";

	Polygone * T2 = new Polygone(Couleur::Green);
	Point p1T2 = Point(6, -1);
	Point p2T2 = Point(8, 0);
	Point p3T2 = Point(6, 1);
	T2->ajoutePoint(p1T2);
	T2->ajoutePoint(p2T2);
	T2->ajoutePoint(p3T2);
	cout << T2->toString() << "\n";

	Cercle * C2 = new Cercle(Point(17, 0), 1, Couleur::Yellow);
	cout << C2->toString() << "\n";

	Groupe * G1 = new Groupe(Couleur::Red);
	G1->ajouteForme(T1);
	G1->ajouteForme(C1);
	G1->ajouteForme(R1);
	G1->ajouteForme(T2);
	G1->ajouteForme(C2);
	cout << G1->toString() << "\n";

	G1->translation(-4, 0);
	cout << G1->toString() << "\n";
	//G1->rotation(Point(0, 0), 45);
	cout << G1->toString() << "\n";
	cout << "Aire de G1 : " << G1->calculAire() << "\n";
	G1->homothetie(Point(-10,-10),15);
	
	cout << "Sauvegarde dans le fichier 'majoliefigure2.txt' ...\n";
	ofstream ofs("majoliefigure2.txt", ostream::out | ostream::trunc);

	if (ofs) {
		G1->sauvegarder(ofs);
		ofs.close();
	}
	else Erreur("Erreur lors de l'ouverture du fichier");

	cout << "Chargement du fichier 'majoliefigure2.txt' ...\n";
	ifstream ifs("majoliefigure2.txt", ostream::in);

	if (ifs) {
		string ligne;
		while (getline(ifs, ligne))
		{
			cout << ligne << endl;
		}
		ifs.close();
	}
	else Erreur("Impossible d'ouvrir le fichier !");

	return G1;
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

void testSauvegarde()
{
    cout << "Sauvegarde dans le fichier 'sauvegarde.txt' ...\n";
    ofstream ofs("sauvegarde.txt", ostream::out | ostream::trunc);

	if (ofs) {
		Cercle * c = new Cercle(Point(300, 300), 30, Couleur::Yellow);

		Segment * s = new Segment(Point(300, 300), Point(300, 400), Couleur("#0000FF"));

		Polygone * p = new Polygone(Couleur::Cyan);
		Point p1 = Point(80, 100);
		Point p2 = Point(130, 100);
		Point p3 = Point(105, 50);
		p->ajoutePoint(p1);
		p->ajoutePoint(p2);
		p->ajoutePoint(p3);
		c->sauvegarder(ofs);
		s->sauvegarder(ofs);
		p->sauvegarder(ofs);
		ofs.close();
	}
	else
		Erreur("Impossible d'ouvrir le fichier !");
}

void testChargement()
{
	cout << "Chargement du fichier 'sauvegarde.txt' ...\n";
	ifstream ifs("sauvegarde.txt", ostream::in);
	
	if (ifs) {
		string ligne;
		while (getline(ifs, ligne))
		{
			cout << ligne << endl; 
		}
		ifs.close();
	}
	else Erreur("Impossible d'ouvrir le fichier !");
}


