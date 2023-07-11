/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Explaining DynamicSafeArray (Example Class)  Double Pointer     *
* Dated: September 20, 2004                                                *
* Version: 1.0                                                             *                                                  
* Last modified: September 29, 2004                                        *
****************************************************************************/

class IndexOutOfBoundsException {};

template <class T>
class DynamicSafe2DArray
{
	private:
   	  T** data;
      int row, col;

   public:
	  
	  DynamicSafe2DArray(): data(0), row(0), col(0) {}
     
	  DynamicSafe2DArray(int row, int col)
      {
      	this->row = row;
         this->col = col;
         data = new T*[row];
         for (int i=0; i<row; i++)
         {
         	*(data+i) = new T[col];
            for (int j=0; j<col; j++)
            	*(*(data+i)+j) = 0;
         }
      }

      DynamicSafe2DArray(const DynamicSafe2DArray& rhs)
      {
         row = rhs.row;
         col = rhs.col;

         data = new T*[row];
         for (int i=0; i<row; i++)
         {
         	*(data+i) = new T[col];
            memcpy(*(data+i),*(rhs.data+i), sizeof(T)*col);
         }
      }

      DynamicSafe2DArray& operator=(const DynamicSafe2DArray& rhs)
      {
      if( this != &rhs)
      {
      
         for (int i=row-1; i>0; i++)
         	delete[] *(data+i);
			delete[] data;

         row = rhs.row;
         col = rhs.col;

         data = new T*[row];
         for (int i=0; i<row; i++)
         {
         	*(data+i) = new T[col];
            memcpy(*(data+i),*(rhs.data+i), sizeof(T)*col);
         }
       }
         return *this;
      }

   	T& operator()(int rowIndex, int colIndex)
      {
      	if (rowIndex < 0 || colIndex < 0 || rowIndex >= row || colIndex >= col)
         	throw IndexOutOfBoundsException();
         else
         	return *(*(data+rowIndex)+colIndex);
      }
      
      int getRow() {return row;}
      int getCol() {return col;}

      ~DynamicSafe2DArray()
      {
      	if (data != 0)
         {
         	for (int i=row-1; i>=0; i--)
            {
            	if (*(data+i) != 0)
               	delete [] *(data+i);
               *(data+i) = 0;
            }
            delete [] data;
         }
         data = 0;
      }
};

int main(){
	
	
	
	
	
	
	
	
	return 0;
}

