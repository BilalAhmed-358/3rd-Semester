#include<iostream>
#include "UDSA.h"
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;

UDSA::UDSA(){
	data=NULL;
}
UDSA::UDSA(int n)
{
	size=n;
	data=new int[size];
	memset(this->data, 0, sizeof(int)*size);
}
UDSA::UDSA(const UDSA &rhs)
{
	this->size= rhs.size;
	this->data= new int[size];
	memcpy(this->data,rhs.data,(sizeof(int)*rhs.getsize());
}
UDSA::~UDSA(){
	if(data!=0)
	{
		cout<<"Delete"<<endl;
		delete[] data;
		data=0;
		size=0;
	}
}
UDSA::resize(int nSize)
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
UDSA::getsize() const{
	return size;
}
UDSA::UDSA &operator=(UDSA &rhs)
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
UDSA:: &operator[](unsigned int i)
{
	return *(data+i);
}
UDSA::const int&operator[](unsigned int i)
{
	return *(data+i);
}
void UDSA::insertion(int n,int a)
{
	for(int i=0;i<size;i++)
	{
		data[i]=a[i];
	}
}
void UDSA::searching(int n)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(data[i]==n)
		{
			cout<<"value "<<n<<" found at "<<i+1<<" of UDSA"<<endl;
		}
	}	
}



















