#include "Cercle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Segment.h"

class Visiteur
{
public:
	virtual void visite(Cercle * c) = 0;
	virtual void visite(Polygone * p) = 0;
	virtual void visite(Groupe * g) = 0;
	virtual void visite(Segment * s) = 0;
};