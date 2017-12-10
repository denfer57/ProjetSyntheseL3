#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

#pragma once
template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}



class Point
{
	double x, y;
public:
	inline explicit Point(const double & x = 0, const double & y = 0);

	/**
	* DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	*
	* */
	inline Point(const char * s);
	inline const Point operator + (const Point & u) const;
	inline const Point operator * (const double & a) const;
	/**
	* - unaire (c'est-à- dire opposé d'un vecteur)
	* */
	inline const Point operator - () const;

	operator string() const;

};

inline const Point operator *(const double & a, const Point & u) { return u*a; }

//------------ implémentation des fonctions inline ----------------------

inline  Point::
Point(const double & x, const double & y) : x(x), y(y) {}

inline Point::Point(const char * s)
{
}

inline const Point Point::operator + (const Point & u) const
{
	return Point(x + u.x, y + u.y);
}

inline const Point Point::operator * (const double & a) const
{
	return Point(x*a, y*a);
}

inline const Point Point::operator - () const
{
	return Point(-x, -y);
}

