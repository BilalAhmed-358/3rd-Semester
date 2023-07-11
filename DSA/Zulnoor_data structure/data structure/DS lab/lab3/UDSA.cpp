#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "UDSA.h"
using namespace std;


UDSA::UDSA():DSA(){

}
UDSA::UDSA(int x):DSA(x){

}

//UDSA::UDSA(const UDSA&):DSA(UDSA){
//	
//}

UDSA::~UDSA(){

}

void UDSA::insert(int x,int y){
if(x < 0 || x >= size){
cout<<"Out of Bounds\n";
}
else{
Data[x]= y;
sortit();
}
}
void UDSA::sortit(){
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

void UDSA::search(int x){
bool flag = false;
for(int i =0;i<size;i++){
if(x >= Data[i]){
if (x == Data[i]){
cout<<"Item "<<x<<" found at "<<i<<" index of UDSA\n";
flag = true;
}
}

}
if(!flag){
cout<<"Item "<<x<<" not found in UDSA\n";
}

}

