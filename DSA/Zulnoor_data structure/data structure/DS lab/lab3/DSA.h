#ifndef DSA_H
#define DSA_H
#pragma once
#include<iostream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
using namespace std;


class DSA
{
protected:
int *Data;
int size;
public:
DSA();
DSA(int);
DSA(const DSA&);
int getSize() const;
DSA& operator=(DSA&);
int& operator[](int);
~DSA();
void insert(int,int);
void search(int);

};
#endif
