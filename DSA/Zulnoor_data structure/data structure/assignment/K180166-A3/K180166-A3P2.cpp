#include<iostream>
#include <fstream>
#include<queue>
using namespace std;

class node{
	public:
		int val;
		node *left;
		node *right;
		node(int d):left(0),right(0)
		{
			val=d;
		}
		friend class Binarytree;
};
class Binarytree{
	public:
		int node_count;
		int sum;
		node *root;
		node *sub_root;
		queue <node*> q;
		queue <node*> p;
		Binarytree():root(0),sub_root(0)
		{		}
		//function to insert nodes in a binary tree
		void insert(int val)
		{
			if(root == NULL)
			{
				root = new node(val);
				return;
			}
			queue< node* > q1;
			node *Root = root;
			q1.push(Root);			
			while(! q1.empty() )	
			{
				Root = q1.front();
				q1.pop();
				if(! Root->left )
				{
					Root->left = new node(val);
					break;
				}
				else
				q1.push( Root->left );
				if(! Root->right )
				{
					Root->right = new node(val);
					break;
				}
				else
				q1.push( Root->right );					
			}	
		}
		//function to read an input file and send data to an insert function to create binary tree
		void file_read()
		{
			int data;
			int count=1;
			fstream inp("input2.txt");
			inp>>node_count;
			inp>>sum;
			cout<<"number of nodes in tree: "<<node_count<<endl;
			cout<<"sum to be calculated: "<<sum<<endl;
			while(!inp.eof()&&count<=node_count)
			{
				inp>>data;
				insert(data);
				count++;
			}
			inp.close();
		}
		//function to display binary tree
		//and 
		//sub binary sub tree
		//in inorder traversal
		void display(node *root)
		{
   			if(root==NULL)
   				return;
   		
		   	display(root->left);
     		cout<<root->val<<" ";
      		display(root->right);	
		}
		//function to create a new node for bst
		node* get_node(int d)
		{
			node* new_node=new node(d);
			return new_node;
		}
		//insert function to create a binary sub tree
		node* insert_bst(node* sub_root,int d)
		{
			if(sub_root==NULL)
				sub_root=get_node(d);
			else if(d>sub_root->val)
			{
				sub_root->right=insert_bst(sub_root->right,d);
			}
			else if(d<sub_root->val)
			{
				sub_root->left=insert_bst(sub_root->left,d);
			}
		}
		//function to send nodes in insert function of binary sub tree 
		//whose sum is equal to the sum to be calculated
		void form_bst(int array[])
		{
			int array_sum=0;
			int count=0;
			int x=0;
			for(int i=0;i<node_count/2;i++)
			{
				if(array_sum==sum)
				{
					x++;
					break;
				}
				array_sum+=array[i]+array[2*i+1]+array[2*i+2];
				count++;
				if(count>1)
				{
					array_sum-=array[i];
				}			
			}
			if(x)
			{
				sub_root=insert_bst(sub_root,array[0]);
				for(int i=0;i<count;i++)
				{
					sub_root=insert_bst(sub_root,array[2*i+1]);
					sub_root=insert_bst(sub_root,array[2*i+2]);
				}
			}
		}
		//function to store elements of binary tree into a queue and array
		void insert_into_queue(node *root)
		{
			int *array{ new int[node_count]{} };
			int i=0;
			q.push(root);
			array[i]=root->val;
			while(!q.empty())
			{
				node *current=q.front();
				if(current->left!=NULL)
				{
					q.push(current->left);
					array[2*i+1]=current->left->val;
				}
					
				if(current->right!=NULL)
				{
					q.push(current->right);
					array[2*i+2]=current->right->val;
				}
				i++;	
				q.pop();		
			}
			form_bst(array);
		}
		//function to store binary search tree nodes into a file using a queue
		void output_filing(node *sub_root)
		{
			ofstream out("output2.txt");
			if(sub_root==NULL)
			{
				out<<"no sub tree"<<endl;
				out.close();
				return;
			}
			p.push(sub_root);
			out<<sub_root->val<<endl;
			while(!p.empty())
			{
				node *current=p.front();
				if(current->left!=NULL)
				{
					p.push(current->left);
					out<<current->left->val<<endl;
				}
					
				if(current->right!=NULL)
				{
					p.push(current->right);
					out<<current->right->val<<endl;
				}		
				p.pop();
			}
			out.close();
		}
};
int main()
{
	Binarytree t;
	t.file_read();
	cout<<endl<<"elements of tree in inorder notation are: "<<endl;
	t.display(t.root);
	t.insert_into_queue(t.root);
 	cout<<endl<<"elements of sub tree in inorder notation are: "<<endl;
	if(t.sub_root->val==NULL)
	{
		cout<<t.sub_root->val<<"no sub tree"<<endl;
	}
	else
	{
		t.display(t.sub_root);
	}
	t.output_filing(t.sub_root);
}
