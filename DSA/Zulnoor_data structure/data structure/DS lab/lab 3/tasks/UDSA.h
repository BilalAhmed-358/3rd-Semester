#ifndef UDSA_h
#define UDSA_h
#include <iostream>
#include "USDA.h"
using namespace std;
class UDSA:public DSA
{
	private:
		int size;
		int *data;
	public:
		UDSA();
		UDSA(int);
		UDSA(const UDSA&);
		~UDSA();
		void resize(int);
		int getsize();
//		DSA &operator = (DSA &);
//		int &operator[](int);
		void insertion(int);
		int searching(int);
		
};
#endif
