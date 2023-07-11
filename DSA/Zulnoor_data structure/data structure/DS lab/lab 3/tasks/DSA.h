#ifndef DSA_h
#define DSA_h
#include <iostream>
using namespace std;
class DSA
{
	private:
		int size;
		int *data;
	public:
		DSA();
		DSA(int);
		DSA(const DSA&);
		~DSA();
		int resize(int);
		//int getsize();
		DSA &operator = (DSA &);
		int &operator[](int);
		void insertion(int[]);
		int searching(int);
		
};
#endif
