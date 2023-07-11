#include <iostream>
#include "student.h"
using namespace std;

    	Student::Student(string roll, string n, float cg)
		{
			 Rno=roll;
			 name=n;
		     cgpa=cg;
		}
		Student::getdata()
		{
			cout<<"ROLL NO : "<<Rno<<endl;
			cout<<"NAME : "<<name<<endl;
			cout<<"CGPA : "<<cgpa<<endl;
		}

