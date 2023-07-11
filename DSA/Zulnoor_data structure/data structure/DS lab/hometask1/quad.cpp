#include<iostream>
#include "quad.h"
using namespace std;

Quad::Quad(double x,double y,double z)
{
	a=x;
	b=y;
	c=z;
	
	cout<<"coefficients are: "<<a<<" "<<b<<" "<<c<<endl;
}

Quad::getroots()
{
	double discriminant,imaginary,real;
	discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    
    else if (discriminant == 0) {
        cout << "Roots are real and same." << endl;
        x1 = (-b + sqrt(discriminant)) / (2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }
    else {
        real = -b/(2*a);
        imaginary =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << real << "+" << imaginary << "i" << endl;
        cout << "x2 = " << real << "-" << imaginary << "i" << endl;
    }
    return 0;
}

