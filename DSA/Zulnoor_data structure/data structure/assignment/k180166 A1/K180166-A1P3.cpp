#include<iostream>
#include<fstream>
#include <string.h>
#include<cstdlib>

using namespace std;
class unique
{
	 private:
	 	char *data;
	 	int s; 	
	public:
		//default constructor
		unique()
		{
			//assigning null to char data
			data=NULL;
			//and 0 to int s
			s=0;
			//function calling
			wordfind();	
		}
		//parameterized constructor
    	unique(int n)
		{	
			//assigning value to int s
			s=n;
			//assigning memory to data of size s
			data= new char[s];
			//initializing data to null
			memset(this->data, 0, sizeof(char)*s);
			//function calling
			wordfind();			
		}
		//copy constructor
	   unique(const unique & rhs)
	   {		
			this->s= rhs.s;
			this->data= new char[s];
			memcpy(this->data,rhs.data,(sizeof(char)*rhs.getSize()));
		}
		//destructor
       ~unique()
	   {
	    	if(data !=0)
	    	{
			
		    	delete [] data;
		    	data=0;
		    	s=0;
		   }
    	}
    	//resize fuction
    	void resize(int nsize)
		{	
    		if (s != nsize )  
			{
			 int * temp= new int[s];
			 	
			    for(int i=0; i<s ; i++)
				{	
			    	temp[i]= *(data+i);
			    }
			    delete[] data;
			    data=0;
			    data = new char[nsize];
			    memset(this->data, 0, sizeof(char)*nsize);
  				for(int i=0; i<s ; i++)
				{	
			    	*(data+i)=temp[i];
			    }
			    s= nsize;
			    delete [] temp;
			    temp=0;
			} 		
    	}
	   //getsize function
	 	unsigned int getSize() const
	  	{
	    	return s;
	  	}
		//assignment operator overloading
		unique& operator=( unique & rhs)
     	{
        	if (this  != &rhs)
        	{
        		int s=rhs.getSize(); 
        		this->s=s;
        		this->data= new char[s];
        		memcpy(this->data,rhs.data, sizeof(rhs.data));
        	}
       		 return (*this);
     	}
     	//function to manipulate string
		void wordfind()
		{
			int c=0;
			string str;	
			//opening file in reading mode
			ifstream inp("inputP3.txt");
			if(!inp)
			{
				cout<<"not open"<<endl;
				exit(1);
			}
			//reading contents of file in string str
			getline(inp,str);
			//closing file
			inp.close();
			//calculating length of str
			//and storing in int s
			s=str.length();
			//printing length and string on console
			cout<<s<<endl;
			cout<<str<<endl;
			//assigning memory to *data of size s+1
			data=new char[s+1];
			//copying contents of str in data
			//using strcpy function
			strcpy(data, str.c_str());
			//loop to manipulate string
			for(int i=0;i<s;i++)
			{
				for(int j=0;j<s;j++)
				{
					//to check if data[i] is
					// '-' or ' '
					if(*(data+i)=='-'||*(data+i)==' ')
					{
						//if yes
						//break from loop
						break;
					}
					//if not
					//check if data[i] is equals to data[j] or data[j]+32
					if(*(data+i)==*(data+j)||*(data+i)==(*(data+j)+32))
					{
						//if yes increment int c by 1
						c++;
					}
					//checking if int c>1
					if(c>1)
					{
						//if yes
						//change value of data[j] to '-'
						*(data+j)='-';
						//change int c to 1 
						c=1;
					}
				}
				//end of loop j
				//assign 0 to int c
				c=0;
			}
			//end of loop i
			//loop to print string str after manipulation
			for(int i=0;i<s;i++)
			{
				cout<<*(data+i);
			}
			//opening file in writing mode
			ofstream out("outputP3.txt");
			//loop to write contents of data in file
			for(int i=0;i<s;i++)
			{
				out<<*(data+i);
			}
			//writing endl||end line at the end of string
			out<<endl;
			//closing a file
			out.close();
		}
		//end of function
	};
int main()
{
	//object of class
	unique u;
}
