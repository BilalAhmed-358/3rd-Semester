#include<iostream>
#include<cmath>
#include "quad.h"
using namespace std;

int main()
{
	Quad q1(3,-6,5);
	Quad q2(3.4,-2.3,6.2);
	q1.getroots();
	cout<<endl;
	q2.getroots();
}
