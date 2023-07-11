#ifndef student_h
#define student_h
#include<iostream>
#include<fstream>
using namespace std;
class Student
{
	protected:
		string name;
		int sem;
		double GPA;
	public:
		input_data();
		Extrect_Highest();
};
#endif
