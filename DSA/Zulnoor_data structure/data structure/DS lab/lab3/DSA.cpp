#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "DSA.h"
using namespace std;


DSA::DSA(){
Data=NULL;
}
DSA::DSA(int n){
size=n;
Data= new int[size];
memset(this->Data, 0, sizeof(int)*size);
for(int i =0;i<size;i++){
Data[i]=0;
}
 }
DSA::DSA(const DSA & rhs){
this->size= rhs.size;
this->Data= new int[size];
memcpy(Data,rhs.Data,(sizeof(int)*rhs.getSize()));
}
DSA::~DSA()
{
if(Data !=0)
{
cout<<"bye--"<<endl;
delete [] Data;
Data=0;
size=0; 
}
}

int DSA:: getSize() const {
return size;
}

DSA& DSA::operator=( DSA & rhs){
if (this != &rhs){
int s=rhs.getSize();
this->size=s;
this->Data= new int[s];
memcpy(Data,rhs.Data, sizeof(rhs.Data));
}
return (*this);
}
//lval
int& DSA::operator[](int i){
return *(Data+i);}
//rval
//const int& DSA::operator[](int i) const {
//return *(Data+i);}
void DSA::insert(int x, int y){
if(x < 0 || x >= size){
cout<<"Out of Bounds\n";
}
else{
Data[x]= y;
}
}
void DSA::search(int x){
bool flag = false;
for(int i =0;i<size;i++){
if(Data[i]==x){
cout<<"Item found at "<<i<<" index\n";
flag = true;
}

}
if(!flag){
cout<<"Not found\n";
}
}

