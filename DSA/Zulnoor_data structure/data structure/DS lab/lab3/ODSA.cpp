#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "ODSA.h"
using namespace std;


ODSA::ODSA():DSA(){

}
ODSA::ODSA(int x):DSA(x){

}

//ODSA::ODSA(const ODSA&):DSA(ODSA){
//	
//}

ODSA::~ODSA(){

}

void ODSA::insert(int x,int y){
if(x < 0 || x >= size){
cout<<"Out of Bounds\n";
}
else{
Data[x]= y;
sortit();
}
}
void ODSA::sortit(){
int temp;
for(int i = 0;i<size-1;i++){
for(int j = 0;j<size-1-i;j++){
if(Data[j] > Data[j+1]){
temp = Data[j];
Data[j] = Data[j+1];
Data[j+1] = temp;
}
}
}
}

void ODSA::search(int x){
bool flag = false;
for(int i =0;i<size;i++){
if(x >= Data[i]){
if (x == Data[i]){
cout<<"Item "<<x<<" found at "<<i<<" index of ODSA\n";
flag = true;
}
}

}
if(!flag){
cout<<"Item "<<x<<" not found in ODSA\n";
}

}

