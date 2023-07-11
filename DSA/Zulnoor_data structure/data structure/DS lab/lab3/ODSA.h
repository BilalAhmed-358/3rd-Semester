#ifndef ODSA_H
#define ODSA_H
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "DSA.h"
using namespace std;


class ODSA : public DSA
{

public:
ODSA();
ODSA(int);
ODSA(const DSA&);
~ODSA();
void search(int);
void insert(int,int);
void sortit();
protected:
};
#endif
