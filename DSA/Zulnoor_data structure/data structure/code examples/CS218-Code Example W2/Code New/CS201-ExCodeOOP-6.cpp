/***************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Multiple inheritance (virtual inheritance case)                 *
* Dated: September 12, 2007                                                *
* Version: 1.2   ctor/dtor                                                 *                                                 
* Last modified: September 23, 2007                                        *
****************************************************************************/

#include<iostream>

using namespace std;

class Base1{
     private:
        int b1;
     public: 
         Base1():b1(0){cout<< "Constructor of Base"<<endl;}
         ~Base1(){cout<< "Destructor of Base"<<endl;}
};



class Derived1: virtual public Base1{
      private:
        int d1;
     public: 
         Derived1():d1(0){cout<< "Constructor of Derived1"<<endl;}
         ~Derived1(){cout<< "Destructor of Derived1"<<endl;}
         
    
};

class Derived2: virtual public Base1{
      private:
        int d2;
     public: 
         Derived2():d2(0){cout<< "Constructor of Derived2"<<endl;}
         ~Derived2(){cout<< "Destructor of Derived2"<<endl;}
      
      
      
      
};

class Derived: virtual public Derived1, virtual public Derived2{
      private:
        int d;
     public: 
         Derived():d(0){cout<< "Constructor of Derived"<<endl;}
         ~Derived(){cout<< "Destructor of Derived"<<endl;}
      
      
      
      
};



int main()
{
    cout<< "Derived One"<<endl;
	Derived *d= new Derived();
	cout<< sizeof(*d) << endl;
    delete d;
        
    	// Objective: make the derived 1 and 2 virtual inheritance to keep only one copy of base memory
	
    system("pause");
    return 0;
     
}
