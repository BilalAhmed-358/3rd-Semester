#ifndef student_h
#define student_h
#include<iostream>

using namespace std;
class Student{
	protected:
		string Rno;
		string name;
		float cgpa;
		
		public:
		Student(string, string, float);
		setdata();
		getdata();
};
#endif
