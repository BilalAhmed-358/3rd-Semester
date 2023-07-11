#include <iostream>
#include<fstream>
using namespace std;
class puzzle
{
	int row;
	int col;
	char **data;
	public:
		//default constructor
		puzzle():data(0),row(0),col(0){
			//function calling		
			word_puzzle();
		}
		//parameterized constructor
		puzzle(int r,int c)
		{
			this->row=r;
			this->col=c;
			data=new char*[row];
			for(int i=0;i<row;i++)
			{
				*(data+i)=new char[col];
				for(int j=0;j<col;j++)
				{
					*(*(data+i)+j)=0;
				}
			}
			//function calling
			word_puzzle();
		}
		//destructor
		~puzzle()
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
		puzzle(const puzzle &rhs)
		{
			this->row=rhs.row;
			this->col=rhs.col;
			data=new char *[row];
			for(int i=0;i<row;i++)
			{
				*(data+i)=new char [col];
				memcpy(*(data+i),*(rhs.data+i),col);
			}
		}
		//assignment operator overloading
		puzzle operator=(const puzzle &rhs)
		{
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
					data=new char*[row];
					for(int i=0;i<row;i++)
					{
						*(data+i)=new char[col];
						for(int i=0;i<row;i++)
						{
							*(data+i)=new char [col];
							memcpy(*(data+i),*(rhs.data+i),col);
						}
					}
				}
			}
		}
		//function definition
		int word_puzzle()
		{
			int rc,cc;
			int count=1;
			int c,x=0,y,r; 
			//opening file in read mode
			ifstream inp("input.txt");
			if(!inp)
			{
				cout<<"no file";
				exit(1);
			}
			//loop to read number of rows and coloumns of puzzle from file
			for(int i=0;i<1;i++)            
			{
				for(int j=0;j<2;j++)
				{
					//reading int
					inp>>r;
					//incrementing int x
					x++;
					//checking if
					//x is 1
					if(x==1)
					{
						//assign value of int r to row
						row=r;
					}
					//if x is 2
					if(x==2)
					{
						//assign value of int r to col
						col=r;
					}
				}
			}
			//end of loop
			//printing rows and cols on console
			cout<<row<<"/"<<col<<endl;
			//assigning memory to data of size row
			data=new char*[row];
			//loop to assign memory to each row
			for(int i=0;i<row;i++)
			{
				//assigning memory to row i of size col
				*(data+i)=new char[col];
				//loop to initialize dtata[i][j] with 0
				for(int j=0;j<col;j++)
				{
					*(*(data+i)+j)=0;
				}
			}
			//end of loop
			//loop to read contents of puzzle
			for(int i=0;i<row;i++)          
			{
				for(int j=0;j<col;j++)
				{
					//inputting value to data[i][j]
					inp>>*(*(data+i)+j);
				}
			}
			//end of loop
			//loop to print puzzle on console
			for(int i=0;i<row;i++)             
			{
				for(int j=0;j<col;j++)
				{
					cout<<*(*(data+i)+j);
				}
				cout<<endl;
			}
			//end of loop
			//reading number of words to be searched from file
			inp>>c;
			cout<<c;
			//declaring array of string of size c
			string words[c+1];
			//loop to read
			for(int i=0;i<c+1;i++)
			{
				//words from file
				getline(inp,words[i]);
			}
			//end of loop
			//closing file
			inp.close();
			//loop to print words on console
			for(int i=0;i<c+1;i++)
			{
				cout<<words[i]<<endl;
			}
			x=0;
			//loop to search words from puzzle
			//loop i of size of word array
			for(int i=1;i<=c+1;i++)
			{
				//loop j of size of size of rows
				for(int j=0;j<row;j++)
				{
					//loop k of size of cols
					for(int k=0;k<col;k++)
					{
						//to check if char at 1st index of words[i] array
						//is equals to char at data[j][k] position
						if(words[i][0]==*(*(data+j)+k))
						{
							//if yes assign
							//value of row index to int rc
							rc=j;
							//and value of col index to int cc
							cc=k;
							//loop to search words again
							//from 2nd index to last
							for(int l=1;l<words[i].length();l++)
							{
								//to check if char at lth index of words[i] array
								//is equals to char at data[j][++k] position
								//i.e next col
								if(words[i][l]==*(*(data+j)+(++k)))
								{
									//increment k by 1
									++k;
									//increment count by one
									count++;
								}
								//to check if char at lth index of words[i] array
								//is equals to char at data[j][--k] position
								//i.e previous col
								if(words[i][l]==*(*(data+j)+(--k)))
								{
									//decrememnt k by 1
									--k;
									//increment count by 1
									count++;
								}
								//to check if char at lth index of words[i] array
								//is equals to char at data[++j][k] position
								//i.e next row
								if(words[i][l]==*(*(data+(++j))+k))
								{
									//increment j by 1
									++j;
									//increment count by 1
									count++;
								}
								//to check if char at lth index of words[i] array
								//is equals to char at data[--j][k] position
								//i.e previous row
								if(words[i][l]==*(*(data+(--j))+k))
								{
									//decrememnt j by 1
									--j;
									//increment count by 1
									count++;
								}
							}
							//end of loop
							//to check if
							//count is equals to
							//length of word searched
							//if yes
							if(count==words[k].length())
							{
								//print word and row and col to console
								cout<<words[k]<<" "<<rc<<" "<<cc<<endl;
								//increment int x by 1
								x++;
								//opening file in append mode for writing
								ofstream out("outputP1.txt",ios::app);
								//writing row and col to file
								out<<rc<<cc<<endl;
								//closing file
								out.close();
							}
							//assign value of rc to j
							//i.e restore value of j back to original one
							j=rc;
							//assign value of cc to k
							//i.e restore value of k back to original one  
							k=cc;
							//reassign count to 1
							count=1;
						}
						//to check if
						//x is greater than 0
						//i.e word has been found
						if(x>0)
						{
							//if yes break from loop k
							break;
						}
					}	
					//to check if
					//x is greater than 0
					//i.e word has been found
					if(x>0)
					{
						//if yes break from loop j
						break;
					}	
				}
				//to check if x is 0
				//i.e word not found
				if(!x)
				{
					//print char n to console
					cout<<"n"<<endl;
					//open file in append mode
					ofstream out("outputP1.txt",ios::app);
					//write char n in file
					out<<"n"<<endl;
					//close file
					out.close();
				}
				//end of loop i
			 }
			 //end of function 
		}
};
int main()
{
	//object of class
	puzzle p;
}
