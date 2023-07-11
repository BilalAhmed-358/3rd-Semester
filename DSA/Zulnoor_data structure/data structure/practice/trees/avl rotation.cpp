#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *left;
		node *right;
		int height;
		node(int d):left(0),right(0)
		{
			height=1;
			data=d;
		}
};
class avltree
{
	public:
		node *root;
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
		
		node *insert(node *n,int d)
		{
			if(n==NULL)
				return new node(d);
			
			if(d<n->data)
				n->left=insert(n->left,d);	
			else if(d>=n->data)
				n->right=insert(n->right,d);
//			else
//				return n;
				
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
		
		void preorder(node *root)
		{
			if(root!=NULL)
			{
				cout<<root->data<<" ";
				preorder(root->left);
				preorder(root->right);	
			}
			
		}
};


int main()
{
	avltree avl;
	node *root=NULL;
	root = avl.insert(root, 10);  
    root = avl.insert(root, 20);  
    root = avl.insert(root, 30);  
    root = avl.insert(root, 40);  
    root = avl.insert(root, 50);  
    root = avl.insert(root, 25); 
    
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    avl.preorder(root);  
      
    return 0; 
}
