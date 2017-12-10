#include "Segment.h"
#include "Visiteur.h"

Segment::Segment(Point & a, Point & b) : _a(a), _b(b){ }

const Point & Segment::getA()
{
	// TODO: insérer une instruction return ici
	return _a;
}

const Point & Segment::getB()
{
	// TODO: insérer une instruction return ici
	return _b;
}

void Segment::setA(const Point & a)
{
	_a = a;
}

void Segment::setB(const Point & b)
{
	_b = b;
}

void Segment::visite(Visiteur *v)
{
	v->visite(this);
}