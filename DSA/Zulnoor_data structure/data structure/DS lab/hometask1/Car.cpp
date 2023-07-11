#include<iostream>
using namespace std;
class car{
	string model;
	int Year;
	string country;
	
	public:
		car(){
		}
		car(string n,int m,string c)
		{
			model=n;
			Year=m;
			country=c;
		}
		car(const car &obj)
		{
			model = obj.model;
			Year= obj.Year;
			country= obj.country;
		}
		void display()
		{
			cout<<endl<<"Model: "<<model<<endl<<"Manufacture Year: "<<Year<<endl<<"Country: "<<country<<endl;
		}
		~car()
		{
			cout<<endl<<"class destructor called"<<endl;
		}
};
int main()
{
	car c1("Cultus",2013,"Pakistan");
	car c2 = c1;
	c1.display();
	cout<<endl<<"Copy COnstructor"<<endl;
	c2.display();
}
