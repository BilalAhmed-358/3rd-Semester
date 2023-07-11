/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: DynamicSafe2DArray (Examples)                                     *
* Dated: September 18, 2007                                                *
* Version: 1.0                                                             *                                                 
* Last modified: September 27, 2007                                        *
****************************************************************************/

#include<iostream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;

class DynamicSafe2DArray{
	
	 private:
	 	int *Data;
	 	int nRow;
	 	int nCol;
	 	
	 	
	public:
		DynamicSafe2DArray(){
			
			Data=NULL;
			nRow=0;
			nCol=0;
			
			
		}
	
    	DynamicSafe2DArray(int r, int c){
			
			int size=r *c;
			Data= new int[size];
			memset(this->Data, 0, sizeof(int)*size);
					
			
		}
		
		
	   DynamicSafe2DArray(const DynamicSafe2DArray & rhs){
			
			 this->nRow= rhs.nRow;
			 this->nCol= rhs.nCol;
			 int size= rhs.nRow * rhs.nCol;
			 this->Data = new int[size];
			 memcpy(this->Data,rhs.Data,(sizeof(int)*size));
			
		}
		
       ~DynamicSafe2DArray()
	   {
	    	if(Data !=0)
	    	{
			
		    	delete [] Data;
		    	Data=0;
		    	nRow=nCol=0;
		   }
		
    	}
    	
    	
	DynamicSafe2DArray& operator=( DynamicSafe2DArray & rhs)
    {
         if (this  != &rhs)
        {
               
        this->nCol= rhs.nCol;
        this->nRow= rhs.nRow;
        int size = this->nCol * this ->nRow;
        Data= new int[size];
        memcpy(this->Data,rhs.Data, sizeof(rhs.Data));
        }
        return (*this);
         
    }

     int getRow()const {
 	
    	return nRow;
     }
 
     int getCol() const{
 	
 	  return nCol;
    }

	//lval
	 int& operator()( int i, int j){ 
	 
	  long offset= (i*nCol)+j;
	  return Data[offset];} 
	 //rval
     const int& operator()( int i, int j) const {	 
	  long offset= (i*nCol)+j;
	  return Data[offset];} 
};


         



int main()
{
  
  DynamicSafe2DArray DSA1(2,3); 
  
   int i=0, j=0;
   int r=DSA1.getRow();
   int c= DSA1.getCol();

  cout << r  <<  endl;
  cout << r  <<  endl;

  for(i=0; i < r; i++)
  {
  	for(i=0; i < c ; i++)
  	{
  		
  		cout << DSA1(i,j)<< "  " <<endl;
  		
  	}
  	
  	
  	
  	
  }
  
  
  

return 0;


}

