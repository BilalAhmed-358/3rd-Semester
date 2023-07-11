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
		{
		}
//		void file_read()
//		{
//			int data;
//			int count=1;
//			fstream inp("input2.txt");
//			inp>>node_count;
//			inp>>sum;
//			cout<<"number of nodes in tree: "<<node_count<<endl;
//			cout<<"sum to be calculated: "<<sum<<endl;
//			while(!inp.eof()&&count<=node_count)
//			{
//				inp>>data;
//				root=insert(root,data);
//				count++;
//			}
//			inp.close();
//		}
		void insert(node* root,int d)
		{
			queue<node *>q;
			q.push(root);
			
			while(!q.empty())
			{
				root=q.front();
				q.pop();
				
				if(!root->left)
				{
					root->left=new node(d);
					cout<<d<<" ";
					break;
				}
				else
					q.push(root->left);
					
				if(!root->right)
				{
					root->right=new node(d);
					cout<<d<<" ";
					break;
				}
				else
					q.push(root->right);	
			}
		}
		void display(node *root)
		{
   			if(!root)
   				return;
   		
		   	display(root->left);
     		cout<<root->key<<endl;
      		display(root->right);	
		}
};
int main()
{
	Binarytree t;
	//t.file_read();
	node *root=NULL;
	t.insert(t.root,7);
	t.insert(t.root,9);
	t.insert(t.root,2);
	cout<<"elements of tree in inorder notation are: "<<endl;
	t.display(t.root);
}
