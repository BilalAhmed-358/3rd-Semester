#include<bits/stdc++.h>
using namespace std;
class binarytree
{
	public:
		
		char data;
		int frequency;
		binarytree *root;
		binarytree *right;
		binarytree *left;
		binarytree()
		{
			root = 0;
			right = 0;
			left = 0;
		}
	    void insertnode(char,int);
	    void HuffmanCodes(char[],int[],int);
	    void display(binarytree*,string);
};
void binarytree::insertnode(char x,int y)
{
	if(root == 0)
	{
		binarytree *newnode = new binarytree();
		newnode->data = x;
		newnode->frequency = y;
		root = newnode;
	}
	else
	{
		binarytree *newnode = new binarytree();
		newnode->data = x;
		newnode->frequency = y;
		binarytree *hawanode = new binarytree();
		hawanode->data = '0';
		hawanode->frequency = root->frequency + newnode->frequency;
		if(newnode->frequency > root->frequency)
		{
			hawanode->right = newnode;
			hawanode->left = root;
		}
		else
		{
			hawanode->right = root;
			hawanode->left = newnode;
		}
		root = hawanode;
	}
}
void binarytree::HuffmanCodes(char arr[],int fre[],int size)
{
	for(int i=0;i<size;i++)
	{
		insertnode(arr[i],fre[i]);
	}
}
void binarytree::display(binarytree *root,string str)
{
	if(!root)
	{
		return;
	}
	if(root->data != '0')
	{
		cout<<root->data<<" : "<<str<<endl;
	}
	display(root->left,str+'0');
	display(root->right,str+'1');
}
int main()
{
    char arr[] = {'a','b','c','d','e','f' };
    int freq[] = {5,9,12,13,16,45};
    int size = sizeof(arr) / sizeof(arr[0]);
    binarytree b;
	b.HuffmanCodes(arr, freq, size);
	b.display(b.root,"");
    return 0;
}
