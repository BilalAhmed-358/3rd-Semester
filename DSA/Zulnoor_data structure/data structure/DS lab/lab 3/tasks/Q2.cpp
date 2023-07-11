#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int size=0,b,c=0;
	cout<<"How Many rows : ";
	cin>>b;
	vector< vector<int> > vec;
	for(int i=0;i<b;i++)
	{
		vector<int> x;
		cout<<"Enter Row "<<i+1<<" Size: ";
		cin>>size;
		cout<<"Enter the row elements : "<<endl;
		for(int j=0;j<size;j++)
		{
			cin>>c;
			x.push_back(c);
		
		}
		vec.push_back(x);
	}
	cout<<endl<<"Printing the data"<<endl<<endl;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			cout<< vec[i][j]<<" ";	
		}	
		cout<<endl;	
	}

	return 0;
}
