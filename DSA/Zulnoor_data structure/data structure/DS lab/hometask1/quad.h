#ifndef quad_h
#define quad_h
#include<iostream>
#include<cmath>

using namespace std;

class Quad
{
	protected:
	double a,b,c,x1,x2;
	public:
		
		Quad(double,double,double);
		getroots();
};
#endif
