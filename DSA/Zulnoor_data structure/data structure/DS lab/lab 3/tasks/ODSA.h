#ifndef ODSA_h
#define ODSA_h
#include <iostream>
#include "OSDA.h"
using namespace std;
class ODSA:public DSA
{
	private:
		int size;
		int *data;
	public:
		ODSA();
		ODSA(int);
		ODSA(const ODSA&);
		~ODSA();
		void resize(int);
		int getsize();
//		DSA &operator = (DSA &);
//		int &operator[](int);
		virtual void insertion(int);
		virtual int searching(int);
		
};
#endif
