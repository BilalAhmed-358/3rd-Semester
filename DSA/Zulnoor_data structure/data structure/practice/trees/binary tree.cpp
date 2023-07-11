#include<iostream>
#include <fstream>
#include<queue>
using namespace std;

class node{
	public:
		int key;
		node *left;
		node *right;
		node(int d):left(0),right(0)
		{
			key=d;
		}
		friend class Binarytree;
};
class Binarytree{
	public:
		int node_count;
		int sum;
		node *root;
		node *sub_root;
		Binarytree():root(0)
		{		}
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
		void display(node *root)
		{
   			if(!root)
   				return;
   		
		   	display(root->left);
     		cout<<root->key<<" ";
      		display(root->right);	
		}
		void dis(node *root , int space)
		{
			if(root == NULL)
			return;
			space += 10;
			dis(root->left , space);
			for(int i = 0 ; i<space ; i++)
			cout<<" ";
			cout<<root->key<<' '<<endl;
			dis(root->right , space);
		}
};
int main()
{
	Binarytree t;
	//insert elements by yourself
	t.dis(t.root,0);
	cout<<"elements of tree in inorder notation are: "<<endl;
	t.display(t.root);
}
