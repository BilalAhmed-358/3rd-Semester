#include <iostream>
using namespace std;
class student
{
	string ID;
	int batch;
	string disc;
	int gradyear;
	string courses[3];
	public:
		student(){
		}
		student(string id,int b,string dis,int grad)
		{
			ID=id;
			batch=b;
			disc=dis;
			gradyear=grad;
			cout<<"Enter your courses below: "<<endl;
			for(int i=0;i<3;i++)
			{
				cin>>courses[i];
			}
		}
		void getData()
		{
			cout<<ID<<endl<<batch<<endl<<disc<<endl<<gradyear<<endl<<"courses"<<endl;
			for(int i=0;i<3;i++)
			{
				cout<<courses[i];
				cout<<" ";
			}
		}
};

int main()
{
	student s1("18K-0166",2018,"BS-CS",2022);
	student s2("17K-2234",2017,"BS-CS",2021);
	student s3("16K-2434",2017,"BS-CS",2020);
	
	student *stud = new student[3] {s1,s2,s3};
	for(int i=0;i<3;i++)
	{
		stud[i].getData();
		cout<<endl<<endl;
	}
	 
}
