#include "Cercle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Segment.h"
#include "Point.h"

class Visiteur
{
public:
	virtual void visite(Cercle * c) = 0;
	virtual void visite(Polygone * p) = 0;
	virtual void visite(Groupe * g) = 0;
	virtual void visite(Segment * s) = 0;
	virtual void visite(Point * p) = 0;
};