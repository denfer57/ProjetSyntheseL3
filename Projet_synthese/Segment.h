#pragma once

#include "Forme.h"

class Segment : public Forme
{
private:
	Point _a;
	Point _b;

public:
	Segment(Point &a, Point &b);

	const Point & getA();
	const Point & getB();

	void setA(const Point &a);
	void setB(const Point &b);

	void translation(double translationX, double translationY);
	void homothetie(const Point & p, double rapport);
	void rotation(const Point & p, double angle);
	double calculAire();

	void visite(Visiteur * v);
};