#include<iostream>
#include <string.h>				 // For string handling
#include <cstdlib>               // Header Files 
#include<conio.h>              	 // For getch() function 
#include<fstream>			  	 // For file handling
#include <queue>				 // Using built-in Queue
#include<bits/stdc++.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <stdlib.h>     		 //for using the function sleep
#include<windows.h>              // Necessary when treating consoles  

using namespace std;

void gotoxy (int x, int y)      // Function for displaying entities accordingly
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
    }
     
class node{
	public:
		
		string data;
		node *left;
		node *right;
		int height;
		
		node(string d):left(0),right(0)
		{
			height=1;
			data=d;
		}
				
};

class sentiment
{
	public:
		
		node *positiveroot,*negativeroot; 	// Nodes to create balanced AVL trees for positive and negative words
		
		string userinput;					// String entered by user	
		
		string words[1000]={};				// Words extracted from user input
		
		int wordcount=0;					// Count for the number of words entered by the user
		
		int positive=0;						// Count for the number of positive words entered by the user
		
		int negative=0;						// Count for the number of negative words entered by the user
		
		int notflag=0;						// Flag set if not is in the input string 
		
		int noneflag=0;						// Flag set if none is in the input string 
		
		int noflag=0;						// Flag set if no is in the input string 
		
		int dontflag=0;						// Flag set if dont || don't is in the input string 
		
		int didntflag=0;					// Flag set if didnt || didn't is in the input string 
		
		int wontflag=0;						// Flag set if wont || won't is in the input string 
		
		int stat=0; 
		
		int len;
		
		int flag=0;
		
		double polarity;
		
		queue<string> postv;
		
		queue<string> negtv;
			

		sentiment():positiveroot(0),negativeroot(0)
		{
			
		}

		
		int max(int a,int b)
		{
			
			return (a>b) ? a : b;
			
		}

		
		int height(node *temp)
		{
			
			if(temp==NULL)
				return 0;
			
			return temp->height;	
		
		}
		
		
		node *rightrotate(node *y)
		{
			
			node *x=y->left;
			
			node *t2=x->right;
			
			x->right=y;
			
			y->left=t2;
			
			y->height=max(height(y->left),height(y->right)) + 1;
			
			x->height=max(height(x->left),height(x->right)) + 1;
			
			return x;
		
		}
		

		node *leftrotate(node *x)
		{
			
			node *y=x->right;
			
			node *t2=y->left;
			
			y->left=x;
			
			x->right=t2;
			
			x->height=max(height(x->left),height(x->right)) + 1;
			
			y->height=max(height(y->left),height(y->right)) + 1;
			
			return y;
			
		}
		

		int getbalance(node *temp)
		{
			
			if(temp==NULL)
				return 0;
			
			return height(temp->left)-height(temp->right);	
		
		}
		
		
		node *insert(node *n,string d)
		{
			
			if(n==NULL)
				return new node(d);
				
			if(d<n->data)
				n->left=insert(n->left,d);	
			else if(d>=n->data)
				n->right=insert(n->right,d);
			
				
			n->height=1+max(height(n->left),height(n->right));
			
			int balance	= getbalance(n);
			
			if(balance>1 && d<n->left->data)
				return rightrotate(n);
			
			if(balance<-1 && d>=n->right->data)
				return leftrotate(n);
				
			if(balance>1 && d>=n->left->data)
			{
				
				n->left=leftrotate(n->left);
				
				return rightrotate(n);
			
			}			
			
			if(balance<-1 && d<n->right->data)
			{
				
				n->right=rightrotate(n->right);
				
				return leftrotate(n);
			
			}
			
			return n;
		
		}
		
		
		node *negtree()								// Creates balanced AVL tree for negative words
		{
			
			fstream neg("Negative.txt");
			
			string str;
			
			while(!neg.eof())
			{
				
				getline(neg,str);
				
				negativeroot=insert(negativeroot,str);
			
			}
			
			neg.close();
		
		}
		

		node *postree()								// Creates balanced AVL tree for positive words
		{
			
			fstream pos("Positive.txt");
			
			string str;
			
			if(!pos.is_open())
			{
				
				cout<<"File Not Opened"<<endl;
				
				exit(0);
			}
			
			while(!pos.eof())
			{
				
				getline(pos,str);
				
				positiveroot=insert(positiveroot,str);
			
			}
			
			pos.close();
		
		}
		

		void preorder(node *root)
		{
			
			if(root!=NULL)
			
			{
				
				cout<<root->data<<" ";
				
				preorder(root->left);
				
				preorder(root->right);	
			
			}
			
		}
		
		
		void wordbreak()						// Breaks words by " " || "." || "," which can used in searching
		{
			
			len=userinput.length();
			
			if(userinput[len-1]!='.')
			{
				
				userinput[len]='.';
				
				len++;	
			
			}
			
			int x=0;
			
			for(int i=0;i<len;i++)
			{
				
				if(userinput[i]==' ')
				{
					
					x++;
					
					wordcount++;
					
					continue;
				
				}
				
				if(userinput[i]=='.'||userinput[i]==',')
				{
						
					x++;
					
					wordcount++;
					
					continue;
				}
				
				words[x]+=userinput[i];
			
			}
		
		}
		
		
		void search(node *root,string temp,int n) 			// Function used for searching the extracted words
		{
			
			if(root==NULL)
				return;
			
			search(root->left,temp,n);
			
			if(root->data==temp)
			{
				
				if(n==1)
				{
					
					if(notflag==1)
					{
						
						negative++;
						
						string t="not ";
						
						t+=temp;
						
						negtv.push(t);
						
						notflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(noflag==1)
					{
						
						negative++;
						
						string t="no ";
						
						t+=temp;
						
						negtv.push(t);
						
						noflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(noneflag==1)
					{
						
						negative++;
						
						string t="none ";
						
						t+=temp;
						
						negtv.push(t);
						
						noneflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(wontflag==1)
					{
						
						negative++;
						
						string t="won't ";
						
						t+=temp;
						
						negtv.push(t);
						
						wontflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(dontflag==1)
					{
						
						negative++;
						
						string t="don't ";
						
						t+=temp;
						
						negtv.push(t);
						
						dontflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(didntflag==1)
					{
						
						negative++;
						
						string t="didn't ";
						
						t+=temp;
						
						negtv.push(t);
						
						didntflag=0;
						
						flag++;
						
						return;
					
					}
					
					else
					{
						
						positive++;
						
						postv.push(temp);
						
						flag++;
						
						return;
					
					}
				
				}
				
				if(n==2)
				{
					
					if(notflag==1)
					{
						
						positive++;
						
						string t="not ";
						
						t+=temp;
						
						postv.push(t);
						
						notflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(noflag==1)
					{
						
						positive++;
						
						string t="no ";
						
						t+=temp;
						
						postv.push(t);
						
						noflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(noneflag==1)
					{
						
						positive++;
						
						string t="none ";
						
						t+=temp;
						
						postv.push(t);
						
						noneflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(wontflag==1)
					{
						
						positive++;
						
						string t="won't ";
						
						t+=temp;
						
						postv.push(t);
						
						wontflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(dontflag==1)
					{
						
						positive++;
						
						string t="don't ";
						
						t+=temp;
						
						postv.push(t);
						
						dontflag=0;
						
						flag++;
						
						return;
					
					}
					
					else if(didntflag==1)
					{
						
						positive++;
						
						string t="didn't ";
						
						t+=temp;
						
						postv.push(t);
						
						didntflag=0;
						
						flag++;
						
						return;
					
					}
					
					else
					{
						
						negative++;
						
						negtv.push(temp);
						
						flag++;
						
						return;
					
					}
				
				}
			
			}
			
			search(root->right,temp,n);
		
		}
		
		
		void word_search()                          // Searching throught input words to increment values of various flags
		{
			
			for(int i=0;i<wordcount;i++)
			{
				
				if(words[i]=="not")
				{
					
					notflag++;
					
					continue;
				
				}
				
				if(words[i]=="no")
				{
					
					noflag++;
					
					continue;
				
				}
				
				if(words[i]=="none")
				{
					
					noneflag++;
					
					continue;
				
				}
				
				if(words[i]=="wont"||words[i]=="won't")
				{
					
					wontflag++;
					
					continue;
				
				}
				
				if(words[i]=="dont"||words[i]=="don't")
				{
					
					dontflag++;
					
					continue;
				
				}
				
				if(words[i]=="didnt"||words[i]=="didn't")
				{
					
					didntflag++;
					
					continue;
					
				}
				
				flag=0;
				
				search(positiveroot,words[i],1);
				
				if(!flag)	
					search(negativeroot,words[i],2);
				else
					continue;	
					
			}
		
		}
		
		
		void result(int choice)
		{
			
			if(choice==1)
				result_user();
				
			if(choice==2)
				result_file();	
			
			for(int i=0;i<wordcount;i++)
			{
				
				words[i].clear();
					
			}
			
			sleep(5);
			
			system("cls");
		
		}
		
		int result_user()
		{
			system("cls");
			
			ofstream out;
			
			out.open("Output.txt",ios_base::app);
			
			cout<<"******************************************************************************************************";
			
			gotoxy(40,1);
			
			cout<<"ANALYSIS REPORT"<<endl;
			
			cout<<"******************************************************************************************************"<<endl;
			
			out<<"******************************************************************************************************"<<endl;
			
			cout<<"Analysed Review: "<<endl<<userinput<<endl;
			
			out<<"Analysed Review: "<<endl<<userinput<<endl;
			
			if(!postv.empty())
			{
				
				cout<<endl<<"Positive Words:"<<endl;
				
				out<<endl<<"Positive Words:"<<endl;
				
				while(!postv.empty())
				{
					
					cout<<postv.front()<<endl;
					
					out<<postv.front()<<endl;
					
					postv.pop();
				
				}
			
			}
			
			if(!negtv.empty())
			{
				
				cout<<endl<<"Negative Words:"<<endl;
				
				out<<endl<<"Negative Words:"<<endl;
				
				while(!negtv.empty())
				{
					
					cout<<negtv.front()<<endl;
					
					out<<negtv.front()<<endl;
					
					negtv.pop();
				
				}
			
			}
			
			cout<<endl;
			
			out<<endl;
			
			double total=positive+negative;
			
			cout<<"Positive Sentiments: "<<positive<<endl;
			
			out<<"Positive Sentiments: "<<positive<<endl;
			
			cout<<"Negative Sentiments: "<<negative<<endl;
			
			out<<"Negative Sentiments: "<<negative<<endl;
			
			cout<<"Total Sentimental References: "<<total<<endl;
			
			out<<"Total Sentimental References: "<<total<<endl;
			
			polarity=positive/total;
			
			cout<<endl<<"Polarity: "<<polarity<<endl<<endl;
			
			out<<endl<<"Polarity: "<<polarity<<endl<<endl;
			
			if(positive == negative)
			{
				cout<<endl<<"Sentiment possessed is NEUTRAL "<<endl<<endl;
			
				out<<endl<<"Sentiment possessed is NEUTRAL "<<endl<<endl;
			}
			
			else if(polarity > 0)
			{
				cout<<endl<<"Sentiment possessed is POSITIVE "<<endl<<endl;
			
				out<<endl<<"Sentiment possessed is POSITIVE "<<endl<<endl;
			}
			
			else if(polarity <= 0)
			{
				cout<<endl<<"Sentiment possessed is NEGATIVE "<<endl<<endl;
			
				out<<endl<<"Sentiment possessed is NEGATIVE "<<endl<<endl;
			}
		}
		
		void result_file()
		{
			
			cout<<"Analysed Review: "<<endl<<userinput<<endl;
			
			if(!postv.empty())
			{
				
				cout<<endl<<"Positive Words:"<<endl;
				
				while(!postv.empty())
				{
					
					cout<<postv.front()<<endl;;
					
					postv.pop();
				
				}
			
			}
			
			if(!negtv.empty())
			{
				
				cout<<endl<<"Negative Words:"<<endl;
				
				while(!negtv.empty())
				{
					
					cout<<negtv.front()<<endl;;
					
					negtv.pop();
				
				}
			
			}
			
			cout<<endl;
			
			double total=positive+negative;
			
			cout<<"Positive Sentiments: "<<positive<<endl;
			
			cout<<"Negative Sentiments: "<<negative<<endl;
			
			cout<<"Total Sentimental References: "<<total<<endl;
			
			polarity=positive/total;
			
			cout<<endl<<"Polarity: "<<polarity<<endl<<endl;
			
			if(positive == negative)
			{
				cout<<endl<<"Sentiment possessed is NEUTRAL "<<endl<<endl;
			
			}
			
			else if(polarity > 0)
			{
				cout<<endl<<"Sentiment possessed is POSITIVE "<<endl<<endl;
			
			}
			
			else if(polarity <= 0)
			{
				cout<<endl<<"Sentiment possessed is NEGATIVE "<<endl<<endl;
			
			}
			
			cout<<"******************************************************************************************************"<<endl;
		}
		void upperToLowerCase()
		{
			transform(userinput.begin(),userinput.end(),userinput.begin(),::tolower);
		}
		
		void user_input(int choice)
		{
			
			system("cls");
			
			cout<<"Enter customer's review for analysis:"<<endl;
			
			fflush(stdin);
			
			getline(cin,userinput);
			
			ofstream out;
			
			out.open("Input.txt",ios_base::app);
			
			upperToLowerCase();
			
			out<<userinput<<endl;
	
			wordbreak();
			
			word_search();
			
			result(choice);
			
			out.close();
		}
		
		
		void file_input(int choice)
		{
			system("cls");
			
			fstream inp("Input.txt");
			
			cout<<"******************************************************************************************************"<<endl;
			
			gotoxy(40,1);
			
			cout<<"ANALYSIS REPORT"<<endl;
			
			cout<<"******************************************************************************************************"<<endl;
			
			while(!inp.eof())
			{
				
				stat++;
				
				positive=0;
				
				negative=0;
				
				//userinput.clear();
				
				getline(inp,userinput);
				
				if(userinput=="\n"||userinput=="\0")
					return;
				
				upperToLowerCase();
	
				wordbreak();
				
				word_search();
				
				result(choice);
				
			}	
			
			inp.close();
				
		}	
		
};

void menu()
{
		sentiment sen;
	
		sen.negtree();
		
		sen.postree();
		
		int choice;
		cout<<"******************************************************************************************************";
		gotoxy(20,1);
		cout<<"WELCOME TO AIRLINE CUSTOMERS' REVIEW'S SENTIMENT ANALYSER"<<endl;
		cout<<"******************************************************************************************************"<<endl;
		gotoxy(40,4);
		cout<<"***CHOICES***";
		gotoxy(20,6);
		cout<<"1) Place customer's review for sentiment analysis";
		gotoxy(20,8);
		cout<<"2) Place multiple customer's review for sentiment analysis from file"<<endl;
		gotoxy(20,10);
		cout<<"3) Exit"<<endl;
		gotoxy(40,12);
		cout<<"Option:";
		gotoxy(48,14);
		cin>>choice;
	
	switch(choice)
	{
		
		case 1:
			
			sen.user_input(choice);
			
			break;
		
		case 2:
			
			sen.file_input(choice);
			
			break;

		case 3:
			
			exit(0);
			
			break;
		default:
			
			cout<<"Wrong Choice"<<endl;
			
			exit(0);		
	}
	
	menu();

}


int main()
{
	cout<<"******************************************************************************************************";
	gotoxy(20,1);
	cout<<"WELCOME TO AIRLINE CUSTOMERS' REVIEW'S SENTIMENT ANALYSER"<<endl;
	cout<<"******************************************************************************************************"<<endl;
	gotoxy(40,4);
	cout<<"***DISCLAIMER***";
	gotoxy(17,6);
	cout<<"$ This project is the implementation of 'JOURNAL OF INFORMATION,";
	gotoxy(17,7);
	cout<<" KNOWLEDGE AND RESEARCH IN COMPUTER ENGINEERING (ISSN 0975 ? 6760,";
	gotoxy(17,8);
	cout<<" GIF: 01.1135, SIF: 02.502)' ";
	
	gotoxy(17,10);
	cout<<"$ Minqing Hu and Bing Liu. 'Mining and Summarizing Customer Reviews.'"; 
	gotoxy(17,11);
    cout<<"Proceedings of the ACM SIGKDD International Conference on Knowledge";
    gotoxy(17,12);
    cout<<"Discovery and Data Mining (KDD-2004), Aug 22-25, 2004, Seattle,";
    gotoxy(17,13);
    cout<<"Washington, USA";
    
    gotoxy(17,15);
	cout<<"$ Bing Liu, Minqing Hu and Junsheng Cheng. 'Opinion Observer: Analyzing"; 
	gotoxy(17,16);
    cout<<"and Comparing Opinions on the Web.' Proceedings of the 14th ";
    gotoxy(17,17);
    cout<<"International World Wide Web conference (WWW-2005), May 10-14,";
    gotoxy(17,18);
    cout<<"2005, Chiba, Japan.";
    
    sleep(8); 
	 
	system ("cls");
	menu();
	      
	return 0; 

}
