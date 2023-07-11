#include<iostream>
using namespace std;
class grade
{
	int** stud = new int*[3];
	public:
		void setgrade()
		{
			for(int i=0;i<3;i++)
			{
				cout<<"enter section "<<i<<" grades"<<endl;
				fflush(stdin);
				fflush(stdin);
				stud[i] = new int[3];
				cout<<"enter number of grades "<<endl;
				for(int j=0;j<3;j++)
				{
					cin>>stud[i][j];
				}
			}
		}
		void getgrade()
		{
			for(int i=0;i<3;i++)
			{
				cout<<"section: "<<i<<endl;
				cout<<"number of grades "<<endl;
				for(int i=0;i<3;i++)
				{
					
					cout<<*stud[i]<<"  ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	grade g1;
	string a;
	g1.setgrade();
	g1.getgrade();
}
