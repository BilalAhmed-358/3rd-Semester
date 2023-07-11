#ifndef UDSA_H
#define UDSA_H
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "DSA.h"
using namespace std;


class UDSA : public DSA
{

public:
UDSA();
UDSA(int);
UDSA(const DSA&);
~UDSA();
void search(int);
void insert(int,int);
void sortit();
protected:
};
#endif
