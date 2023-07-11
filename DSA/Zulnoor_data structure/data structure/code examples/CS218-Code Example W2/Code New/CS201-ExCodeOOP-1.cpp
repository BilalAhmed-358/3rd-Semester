/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Multi-Level Inheritance                                         *
* Dated: September 18, 2007                                                *
* Version: 1.2    Inheritance & Virtual Functions                          *                                                 
* Last modified: September 28, 2007                                        *
****************************************************************************/




#include<iostream>

using namespace std;

class Base{
	
	private: int b;
	
	public:
	Base(){ cout<< "Base class constructor called" << endl; }
	~Base(){ cout<< "Base class destructor called" << endl;	}
	// three different virtual functions 
	virtual void fun1() {cout << " Virtual Fun1 in Base class" << endl;}
	virtual void fun2() {cout << " Virtual Fun2 in Base class" << endl;}
	virtual void fun3() {cout << " Virtual Fun3 in Base class" << endl;}

};


class Derieved1 : public Base {
	
	private: int d1;
	
	public:
	Derieved1(){ cout<< "Derieved class constructor called" << endl; }
	~Derieved1(){ cout<< "Derieved class destructor called" << endl; }
	
	// two functions of base class implementted in Derived1 
//   virtual fun1() {cout << " Virtual Fun1 in Derived1 class" << endl;}
	      virtual void fun2() {cout << " Virtual Fun2 in Derived1 class" << endl;}
	       virtual void fun3() {cout << " Virtual Fun3 in Derived1 class" << endl;}
};


class Derieved2 : public Derieved1 {
	
	private: int d2;
	
	public:
	Derieved2(){ cout<< "Derieved class constructor called" << endl; }
	~Derieved2(){ cout<< "Derieved class destructor called" << endl; }
	
	// one functions of base class implementted in Derived1 
    //   virtual fun1() {cout << " Virtual Fun1 in Derived2 class" << endl;}
	//   fun2() {cout << " Virtual Fun2 in Derived2 class" << endl;}
	       void fun3() {cout << " Virtual Fun3 in Derived2 class" << endl;}
};



// driver program 

int main(){
	
	Base b;
	Derieved1 d1;
	Derieved2 d2;
	b.fun1(); // call base class fun1
	d1.fun1(); // call base class as not available in derived 1
	d1.fun2(); // call derived class fun2 
	d1.fun3();
	d2.fun3();
	
	
	return 0;
	
	
	
}
