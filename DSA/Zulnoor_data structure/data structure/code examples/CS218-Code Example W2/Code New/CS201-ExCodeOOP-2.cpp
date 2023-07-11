/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Multi-Level Inheritance                                         *
* Dated: September 18, 2007                                                *
* Version: 1.2    access modifier & Inheritance                            *                                                 
* Last modified: September 28, 2007                                        *
****************************************************************************/


#include<iostream>

using namespace std;

class Base{
	
	private: 
	  int privateB;  //private data member 
	protected:
	  int protectedB; // protected data member 
	public:
	  int publicB; //public data member 
	
	public:
	Base(){ cout<< "Base class constructor called" << endl; }
	~Base(){ cout<< "Base class destructor called" << endl;	}
	 
	 void setPrivateB(int n) { privateB=n;}
	 int getPrivateB(void) { return privateB;}
	 
	 void setProtectedB(int n) { protectedB=n;}
	 int getProtectedB(void) { return protectedB;}
	

};


/* change the inheritance to private and protected to see the effects */

//class Derieved1 : private Base {
//class Derieved1 : protected Base {

class Derieved : public Base {
	
	private: 
	  int privateD;  //private data member 
	protected:
	  int protectedD; // protected data member 
	public:
	  int publicD; //public data member 
	
	public:
	Derieved(){ cout<< "Derieved class constructor called" << endl; }
	~Derieved(){ cout<< "Derieved class destructor called" << endl; }
	
	void setPrivateD(int n) { privateD=n;}
	 int getPrivateD(void) { return privateD;}
	 
	 void setProtectedD(int n) { protectedD=n;}
	 int getProtectedD(void) { return protectedD;}
	

};

// driver program 

int main(){
	
	Base b;
	Derieved d;
	
	b.publicB=2;
	b.setPrivateB(3);
	b.setProtectedB(4);
	
	d.publicD=2;
	d.setPrivateD(3);
	d.setProtectedD(4);

	return 0;
	
	
	
}


