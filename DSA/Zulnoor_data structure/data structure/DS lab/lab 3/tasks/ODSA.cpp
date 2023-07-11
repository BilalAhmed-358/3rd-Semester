#include<iostream>
#include "ODSA.h"
#include <stdio.h>
#include <string.h>
#include<cstdlib>
using namespace std;

DSA::DSA(){
	data=NULL;
}
ODSA::ODSA(int n)
{
	size=n;
	data=new int[size];
	memset(this->data, 0, sizeof(int)*size);
}
ODSA::ODSA(const ODSA &rhs)
{
	this->size= rhs.size;
	this->data= new int[size];
	memcpy(this->data,rhs.data,(sizeof(int)*rhs.getsize());
}
ODSA::~ODSA(){
	if(data!=0)
	{
		cout<<"Delete"<<endl;
		delete[] data;
		data=0;
		size=0;
	}
}
ODSA::resize(int nSize)
{
	if (size != nSize )
	{
		int * temp= new int[size];
		for(int i=0; i<size ; i++)
		{
			temp[i]= *(data+i);
		}
		delete[] data;
		data=0;
		data = new int[nSize];
		memset(this->data, 0, sizeof(int)*nSize);
		for(int i=0; i<size ; i++)
		{
			*(data+i)=temp[i];
		}
		size= nSize;
		delete [] temp;
		temp=0;
}
ODSA::getsize() const{
	return size;
}
ODSA::ODSA &operator=(ODSA &rhs)
{
	if (this != &rhs)
	{
		int s=rhs.getsize();
		this->size=s;
		this->data= new int[s];
		memcpy(this->data,rhs.data, sizeof(rhs.data));
	}
	return (*this);
}
ODSA:: &operator[](unsigned int i)
{
	return *(data+i);
}
ODSA::const int&operator[](unsigned int i)
{
	return *(data+i);
}
void ODSA::insertion(int a[])
{
	for(int i=0;i<size;i++)
	{
		data[i]=a[i];
	}
}
void ODSA::searching(int n)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(data[i]==n)
		{
			cout<<"value "<<n<<" found at "<<i+1<<" of ODSA"<<endl;
		}
	}	
}



















