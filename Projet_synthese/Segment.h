#pragma once

#include "Forme.h"

class Segment : public Forme
{
private:
	Point _a;
	Point _b;
public:
	string toString() const;
	Segment(Point &a, Point &b);
	Segment(const Point & a, const Point & b, const Couleur & couleur);

	const Point & Segment::getA() const { return _a; }
	const Point & Segment::getB() const { return _b; }

	void setA(const Point &a);
	void setB(const Point &b);
	void visite(Visiteur * v);

	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);
	double calculAire();

	Segment * clone() const;
};