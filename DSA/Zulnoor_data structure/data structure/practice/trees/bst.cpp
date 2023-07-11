#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
		node(int d):left(0),right(0)
		{
			data=d;
		}
		friend class bst;
};
class bst{
	public:
		node *root;
		bst():root(0)
		{
			
		}
		node *insert(node *root,int d)
		{
			if(root==NULL)
			{
				root=new node(d);
				return root;
			}
			else if(d>root->data)
				root->right=insert(root->right,d);
			else if(d<root->data)
				root->left=insert(root->left,d);
			else
				return root;		
		}
		
		void display(node *root)
		{
			if(root==NULL)
				return;
		 	display(root->left);
		 	cout<<root->data<<" ";
			display(root->right);
		}
};
int main()
{
	node *root=NULL;
	bst t;
	root = t.insert(root, 8);
	root = t.insert(root, 10);  
    root = t.insert(root, 20);  
    root = t.insert(root, 11);  
    root = t.insert(root, 3);  
    root = t.insert(root, 42);  
    root = t.insert(root, 25);
	root = t.insert(root, 5);
	cout<<endl;
	t.display(root); 
}
