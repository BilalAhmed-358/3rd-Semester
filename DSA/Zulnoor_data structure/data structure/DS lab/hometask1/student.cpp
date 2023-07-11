#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

		Student::input_data()
		{
			fstream f1("student.txt",fstream::app);
			cout<<"enter name: ";
			cin>>name;
			cout<<"enter semester: ";
			cin>>sem;
			cout<<"enter GPA: ";
			cin>>GPA;
			f1.write((char*)this,sizeof(*this));
			f1.close();
		}
		Student::Extrect_Highest()
		{
			double high=0;
			fstream inp;
			inp.open("student.txt");
			inp.read((char*)this,sizeof(*this));			
			while(inp)
			{
				if(high < GPA)
				{
					high =  GPA;
				}
				inp.read((char*)this,sizeof(*this));
			}
			inp.close();
			fstream pr;
			pr.open("student.txt");
			pr.read((char*)this,sizeof(*this));			
			while(pr)
			{
				if(GPA == high)
				{
					cout<<"Name: "<<name<<endl;
			 		cout<<"Semester: "<<sem<<endl;
					cout<<"GPA: "<<GPA<<endl;
					break;
				}
				pr.read((char*)this,sizeof(*this));
			}
			pr.close();
		}


