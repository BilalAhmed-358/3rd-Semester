#include<iostream>
#include<cmath>
#include "student.h"
using namespace std;

int main()
{
	Student s1;
	Student s2;
	Student s3;
	s1.input_data();
	cout<<endl;
	s2.input_data();
	cout<<endl;
	s3.input_data();
	cout<<endl;
	s1.Extrect_Highest();
}

