#include <iostream>
#include <fstream>
using namespace std;

class node
{
	public:
		int val;
		node *right;
		node *left;
		node():right(0),left(0)
		{
		}
		friend class BST;
};
class BST{
	public:
		node *root;
		int decreasing=0;
		int decreasing_values[10]={};
		int increasing=0;
		int increasing_values[10]={};
		BST():root(0)
		{
		}
		//function to read input file and form a binary search tree
		void file_read()
		{
			int data;
			fstream inp("input1.txt");
			while(!inp.eof())
			{
				inp>>data;
				//call insert function
				root=insert(root,data);
			}
			inp.close();
		}
		//function to create a node
		node* get_node(int d)
		{
			node* new_node=new node();
			new_node->val=d;
			return new_node;
		}
		//insert function to create binary search tree
		node* insert(node* root,int d)
		{
			if(root==NULL)
				root=get_node(d);
			else if(d>=root->val)
			{
				root->right=insert(root->right,d);
			}
			else if(d<root->val)
			{
				root->left=insert(root->left,d);
			}
		}
		//function to display binary search tree in inorder traversal
		void display(node *root)
		{
   			if (root != NULL) 
			{
      			display(root->left);
     			cout<<root->val<<" ";
      			display(root->right);
   			}
		}
		//function to count the largest sequence having nodes in increasing order
		void increasing_sequence(node *root)
		{
			node *current1;
			node *current2;
			
			int count=0;
			int i;
			//loop to count the number of nodes in a sequence
			for(current1=root;current1!=NULL;current1=current1->left)
			{
				count=0;
				for(current2=current1;current2!=NULL;current2=current2->right)
				{
					count++;
				}
				if(count>increasing)
				{
					increasing=count;
					//loop to store data of nodes in an array
					for(current2=current1,i=0;current2!=NULL;current2=current2->right,i++)
					{
						increasing_values[i]=current2->val;
					}
				}
			}
		}
		//function to count the largest sequence having nodes in decreasing order
		void decreasing_sequence(node *root)
		{
			node *current1;
			node *current2;
			
			int count=0;
			int i;
			//loop to count the number of nodes in a sequence
			for(current1=root;current1!=NULL;current1=current1->right)
			{	
				count=0;
				for(current2=current1;current2!=NULL;current2=current2->left)
				{
					count++;
				}
				
				if(count>decreasing)
				{
					decreasing=count;
					//loop to store data of nodes in an array
					for(current2=current1,i=0;current2!=NULL;current2=current2->left,i++)
					{
						decreasing_values[i]=current2->val;
					}
				}
			}
		}
		//function to call the functions to calculate increase and decreasing sequence count
		void find_longest_sequence(node *root)
		{
			if(!root)
				return;
			increasing_sequence(root);
			decreasing_sequence(root);
			//calling the function itself by sending left node of root
			find_longest_sequence(root->left);
			//calling the function itself by sending right node of root
			find_longest_sequence(root->right);
		}
		//function to display the longest sequence in the tree
		//and storing it in an output file
		void display_longest_sequence()
		{
			ofstream out("output1.txt");
			if(decreasing>increasing)
			{
				cout<<"decreasing_count: "<<decreasing<<endl;
				out<<decreasing<<endl;
				cout<<"decreasing_sequence_values"<<endl;
				for(int i=0;i<decreasing;i++)
				{
					cout<<decreasing_values[i];
					if(decreasing_values[i+1]!=0)
					{
						cout<<",";
					}
					out<<decreasing_values[i];
					if(decreasing_values[i+1]!=0)
					{
						out<<",";
					}
				}
			}
			else
			{
				cout<<"increasing_count: "<<increasing<<endl;
				out<<increasing<<endl;
				cout<<"increasing_sequence_values"<<endl;
				for(int i=0;i<increasing;i++)
				{
					cout<<increasing_values[i];
					if(increasing_values[i+1]!=0)
					{
						cout<<",";
					}
					out<<increasing_values[i];
					if(increasing_values[i+1]!=0)
					{
						out<<",";
					}
				}
			}
		}
};
int main()
{
	BST t;
	t.file_read();
	cout<<"elements of tree in inorder notation are: "<<endl;
	t.display(t.root);
	cout<<endl;
	t.find_longest_sequence(t.root);
	t.display_longest_sequence();
}
