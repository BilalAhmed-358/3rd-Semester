#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
class maze
{
	int row;
	int col;
	int **data;
	public:
		//default constructor
		maze():data(0),row(0),col(0){
			//function calling for finding paths of maze
			paths();
		}
		//parameterized constructor
		maze(int r,int c)
		{
			this->row=r;
			this->col=c;
			data=new int*[row];
			for(int i=0;i<row;i++)
			{
				*(data+i)=new int[col];
				for(int j=0;j<col;j++)
				{
					*(*(data+i)+j)=0;
				}
			}
			//function calling for finding paths of maze
			paths();
		}
		//destructor
		~maze()
		{
			if(data!=0)
			{
				for(int i=row;i>=0;i--)
				{
					if(*(data+i)=0)
					{
						delete[]*(data+i);
					}
				}
				delete[] data;
				data=0;
			}
		}
		//copy constructor
		maze(const maze &rhs)
		{
			this->row=rhs.row;
			this->col=rhs.col;
			data=new int *[row];
			for(int i=0;i<row;i++)
			{
				*(data+i)=new int [col];
				memcpy(*(data+i),*(rhs.data+i),col);
			 }
		}
		//assignment operator overloading
		maze operator=(const maze &rhs)
		{
			//checking for sizes equality of both objects
			if(this != &rhs)
			{
				this->row=rhs.row;
				this->col=rhs.col;
				if(data!=0)
				{
					for(int i=row;i>=0;i--)
					{
						if(*(data+i)=0)
						{
							delete[]*(data+i);
						}
					}
					delete[] this->data;
					data=0;
					data=new int*[row];
					for(int i=0;i<row;i++)
					{
						*(data+i)=new int[col];
						for(int i=0;i<row;i++)
						{
							*(data+i)=new int [col];
							memcpy(*(data+i),*(rhs.data+i),col);
						}
					}
				}
			}
		}
		//function to find paths
		int paths()
		{
			int r,x=0;
			char c;
			int count=0;
			//opening a file for reading
			fstream inp("inputP2.txt");
			if(!inp)
			{
				cout<<"file not found"<<endl;
				exit(1);
			}
			//loop to read number of rows and coloumns of maze stored in a file
			for(int i=0;i<1;i++)             
			{
				for(int j=0;j<2;j++)
				{
					inp>>r;
					x++;
					if(x==1)
					{
						row=r;
					}
					if(x==2)
					{
						col=r;
					}
				}
			}
			cout<<row<<" "<<col<<endl;
			//assigning of memory to data
			//size of rows
			data=new int*[row];
			for(int i=0;i<row;i++)
			{
				//size of columns to *data
				*(data+i)=new int[col];
				for(int j=0;j<col;j++)
				{
					//initializing data[i][j] to 0
					*(*(data+i)+j)=0;
				}
			}			
			//reading elements of file 
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{	
					//storing elements of file to data[i][j]
					//char by char
					inp>>c;
					//assigning to int data[i][j]
					//by sub ascii of 0
					*(*(data+i)+j)=c-48;
				}
			}
			//closing file
			inp.close();
			//printing elements data
			cout<<"elements of maze: "<<endl;
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					cout<<*(*(data+i)+j);
				}
				cout<<endl;
			}
			//checking if enterance or exit of maze is blocked
			if(*(*(data+0)+0)==1||*(*(data+(row-1))+(col-1))==1)
			{
				//if yes printing no path
				cout<<"no path"<<endl;
				//opening file in writing mode
				ofstream out("outputP2.txt");
				//writing in file
				out<<"no path"<<endl;
				//exiting progrm
				exit(1);
			}
			//if not blocked
			else
			{
				//loop to assign values
				for(int i=0;i<col;i++)
				{
					//to row 1
					//if value of col i+1 of row 1 is not blocked
					if(*(*(data+0)+i)!=1)
					{
						//assign -1 to it
						*(*(data+0)+i)=-1;
					}
					else
					{
						//else break from loop 
						//if we reach blocked path
						break;
					}
				}
				//loop to assign values
				for(int i=0;i<row;i++)
				{
					//to col 1
					//if value of row i+1 of col 1 is not blocked
					if(*(*(data+i)+0)!=1)
					{
						//assign -1 to it
						*(*(data+i)+0)=-1;
					}
					else
					//else break from loop 
						//if we reach blocked path
						break;
				}
				//loop to find paths
				for(int i=1;i<row;i++)
				{
					for(int j=1;j<col;j++)
					{
						//if blocked
						if(*(*(data+i)+j)==1)
						{
							//skip that index
							continue;
						}
						//else
						//if we the left index is not blocked
						if(*(*(data+i)+(j-1))!=1)
						{
							//increment the index
							*(*(data+i)+j)=*(*(data+i)+j)+*(*(data+i)+(j-1));
						}
						//if we the upper index is not blocked
						if(*(*(data+(i-1))+(j))!=1)
						{
							//increment the index
							*(*(data+i)+j)=*(*(data+i)+j)+*(*(data+(i-1))+(j));
						}
					}
				}
				//loop exit
				//checking if 
				//last index of maze has value assigned to it other than 0
				//if last index is less than 0
				if(*(*(data+(row-1))+(col-1))<0)
				{
					//assign it value to int count
					//by using absolute function
					//to make negative value positive
					count=abs(*(*(data+(row-1))+(col-1)));
					//printing number of paths
					cout<<count<<" path(s)";
				}
				//else if it is not assigned
				else
				{
					//assign 0 to count
					count=0;
					//print no path
					cout<<"no path";
				}
			}
			//opening file in output mode
			ofstream out("outputP2.txt");
			//checking if int count has paths assigned to it
			if(count!=0)
			{
				//storing number of paths in file
				out<<count;
			}
			//if count is 0
			else
			{
				//writing no path in file
				out<<"no path";
			}	
			//closing file
			out.close();
			//end of function
		}
};
//main
int main()
{
	//object of class maze
	maze m;
}
