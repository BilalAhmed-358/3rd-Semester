#include<iostream>
#include "DSA.h"
#include <stdio.h>
#include <string.h>
#include<cstdlib>
using namespace std;

DSA::DSA(){
	data=NULL;
}
DSA::DSA(int n)
{
	size=n;
	data=new int[size];
	memset(this->data, 0, sizeof(int)*size);
}
DSA::DSA(const DSA &rhs)
{
	this->size= rhs.size;
	this->data= new int[size];
	//memcpy(this->data,rhs.data,(sizeof(int)*rhs.getsize()));
}
DSA::~DSA(){
	if(data!=0)
	{
		cout<<"Delete"<<endl;
		delete[] data;
		data=0;
		size=0;
	}
}
DSA::resize(int nSize)
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
//DSA::getsize() const
//{
//	return size;
//}
DSA::DSA & operator =(DSA &rhs)
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
DSA:: &operator[](unsigned int i)
{
	return *(data+i);
}
DSA::const int&operator[](unsigned int i)
{
	return *(data+i);
}
void DSA::insertion(int n,int a)
{
	if(n<0||n>size)
	{
		cout<<"overlimit"<<endl;
		exit(1);
	}
	else 
		data[n]=a;
}
void DSA::searching(int n)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(data[i]==n)
		{
			cout<<"found at "<<i+1<<endl;
		}
	}	
}












