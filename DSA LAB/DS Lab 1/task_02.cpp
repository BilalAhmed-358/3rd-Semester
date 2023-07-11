#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int main(char *input[],char *output[])
{

  fstream myfile;
  myfile.open (input,ios::binary);
  cout<<"This is working\n";
  myfile.close();
}

