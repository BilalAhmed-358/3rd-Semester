#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		node *right;
		node *left;
		int v;
		node(int x):right(0),left(0)
		{
			v=x;
		}
};
class tree{
	public:
		node *root;
		void insert(node *root,int x)
		{
			if(!root)
				root=new node(x);
			queue<node *>q;
			q.push(root);
			while(!q.empty())
			{
				node *current=q.front();
				if(current->left==NULL)
				{
					current->left=new node(x);
				} 
				else
				{
					q.push(current->left);
				}
				if(current->right==NULL)
				{
					current->right=new node(x);
				} 
				else
				{
					q.push(current->right);	
				}
				q.pop();
			}
		}
		void display(node *root)
		{
			display(root->left);
			cout<<root->v<<" ";
			display(root->right);
		}
		int height(node* root) 
		{
			if (root == NULL)  
	        return 0;  
		    else
		    {  
		        int lheight = height(root->left);  
		        int rheight = height(root->right);  
		      
		        if (lheight > rheight)  
		            return(lheight + 1);  
		        else return(rheight + 1);  
		    }  
		}
		int leaves(node* root)
		{
			if(root==NULL)
				return 0;
			if(root->left==NULL && root->right==NULL)
				return 1;
			else
			{
				return leaves(root->right)+leaves(root->left);
			}	
		}
		void value(int d)
		{
			if(d<2)
				return;
			double x=d;
			int c=d/x;
			cout<<x<<" "<<c<<endl;
			for(int i=0;i<c;i++)
			{
				insert(root,x);
			}
			x=d/2;
			value(x);
		}	
};
int main()
{
	tree t;
	int x;
	cin>>x;
	t.value(x);
//	t.insert(t.root,x);
	cout<<endl;
	t.display(t.root);
	cout<<"height of tree: "<<t.height(t.root)<<endl;
	cout<<"number of leaves: "<<t.leaves(t.root)<<endl;
}
