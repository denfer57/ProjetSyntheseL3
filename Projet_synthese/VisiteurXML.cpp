#include "VisiteurXML.h"

string VisiteurXML::chercheForme(Forme * f)
{
	//on cherche la forme que c'est 
	Cercle *c = dynamic_cast<Cercle*>(f);
	Segment *s = dynamic_cast<Segment*>(f);
	Polygone *p = dynamic_cast<Polygone*>(f);
	Groupe *g = dynamic_cast<Groupe*>(f);

	if (c != NULL)
		return envoiInfos(c);
	else if (s != NULL)
		return envoiInfos(s);
	else if (p != NULL)
		return envoiInfos(p);
	else if (g != NULL)
		return envoiInfos(g);
}

string VisiteurXML::envoiInfos(Cercle * c)
{
	ostringstream oss;
	oss << "Cercle / " << c->getCouleur() << " / " <<	
		c->getMilieu() << " / " << c->getRayon();
	return oss.str();
}

string VisiteurXML::envoiInfos(Segment * s)
{
	ostringstream oss;
	oss << "Segment / " << s->getCouleur() << " / " <<
		s->getA() << " / " << s->getB();
	return string(oss.str());
}

string VisiteurXML::envoiInfos(Polygone * p)
{
	ostringstream oss;
	oss << "Polygone / "  << p->getCouleur();
	return string(oss.str());
}

string VisiteurXML::envoiInfos(Groupe * g)
{
	ostringstream oss;
	oss << "Groupe / " << g->getCouleur();
	return string(oss.str());
}