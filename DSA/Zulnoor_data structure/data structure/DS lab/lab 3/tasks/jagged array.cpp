#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a,b,x;
	cout<<"enter size of 1st dimension: ";
	cin>>a;
	int c[a];
	vector <vector <int> >vec;
	for(int i=0;i<a;i++)
	{
		vector<int>t;
		cout<<"enter size of 2nd dimension: ";
		cin>>b;
		c[i]=b;
		cout<<"enter elements:"<<endl;
		for(int i=0;i<b;i++)
		{
			cin>>x;
			t.push_back(x);
		}
		vec.push_back(t);
	}
	system("cls");
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<c[i];j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
