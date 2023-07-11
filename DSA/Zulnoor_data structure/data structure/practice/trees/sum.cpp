#include<iostream>
#include<queue>
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
		int count=0;
		queue<int>q;
		bst():root(0)
		{
			
		}
		node *insert(node *root,int d)
		{
			if(root==NULL)
			{
				root=new node(d);
			}
			else if(d>root->data)
				root->right=insert(root->right,d);
			else if(d<root->data)
				root->left=insert(root->left,d);
			else
				return root;			
		}
		
		void array_make()
		{
			int array[count]={};
			arraya(array);
		}
		
		void display(node *root)
		{
			if(root==NULL)
				return;
		 	display(root->left);
		 	cout<<root->data<<" ";
		 	count++;
			display(root->right);
		}
		
		void queu(node *root)
		{
			if(root==NULL)
				return;
			queu(root->left);	
			q.push(root->data);
			queu(root->right);	
		}
		
		void arraya(int a[])
		{
			int i=0;
			while(!q.empty())
			{
				int x=q.front();
				a[i++]=x;
				q.pop();
			}
			pairs(a);
			triplets(a);
		}
		void pairs(int a[])
		{
			int sum;
			int c=0;
			cout<<"enter value of sum you want to find in tree: ";
			cin>>sum;
			for(int i=0;i<count;i++)
			{
				if(a[i]>sum)
				{
					break;
				}
				for(int j=i+1;j<count;j++)
				{
					if(a[j]>sum)
					{
						break;
					}
					if(sum==a[i]+a[j])
					{
						cout<<"sum "<<sum<<" found"<<endl;
						cout<<"nodes are "<<a[i]<<" and "<<a[j]<<endl;
						c++;
						break;
					}	
				}
			}
			if(!c)
				cout<<"nodes having sum "<<sum<<" not found in tree"<<endl; 
		}
		
		void triplets(int a[])
		{
			int sum;
			int c=0;
			cout<<"enter value of sum you want to find in tree: ";
			cin>>sum;
			for(int i=0;i<count;i++)
			{
				if(a[i]>sum)
				{
					break;
				}
				for(int j=i+1;j<count;j++)
				{
					if(a[j]>sum)
					{
						break;
					}
					for(int k=j+1;k<count;k++)
					{
						if(a[k]>sum)
						{
							break;
						}
						if(sum==a[i]+a[j]+a[k])
						{
							cout<<"sum "<<sum<<" found"<<endl;
							cout<<"nodes are "<<a[i]<<" , "<<a[j]<<" and "<<a[k]<<endl;
							c++;
							break;
						}	
					}
				}
			}
			if(!c)
				cout<<"nodes having sum "<<sum<<" not found in tree"<<endl; 
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
	cout<<endl;
	t.queu(root);
	t.array_make();
}
