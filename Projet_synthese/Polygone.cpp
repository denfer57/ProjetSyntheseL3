#include "Polygone.h"
#include "Visiteur.h"

Polygone::Polygone(){ }

Polygone::Polygone(vector<Point> points) : listesPoints(points){ }

void Polygone::visite(Visiteur *v)
{
	v->visite(this);
}
