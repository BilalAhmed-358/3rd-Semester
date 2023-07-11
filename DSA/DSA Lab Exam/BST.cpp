#include <iostream>
#include<math.h>
using namespace std;
class Node
{
    int val;
    Node *right_val;
    Node *left_val;

public:
    Node(int val)
    {
        this->val = val;
        this->right_val = NULL;
        this->left_val = NULL;
    }
    friend class Tree;
};
class Tree
{

public:
    Node *Insert_Node(Node *root, int val)
    {
        if (root == NULL)
        {
            return new Node(val);
        }
        if (val < root->val)
        {
            root->left_val = Insert_Node(root->left_val, val);
        }
        else
        {
            root->right_val = Insert_Node(root->right_val, val);
        }
        return root;
    }
    void Inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        Inorder(root->left_val);
        cout << root->val << " ";
        Inorder(root->right_val);
    }
    Node *Find_Pre(Node *root)
    {
        while (root->left_val != NULL)
            root = root->left_val;
        return root;
    }
    Node *Delete(Node *root, int val)
    {
        if (root == NULL)
        {
            return root;
        }
        else if (val < root->val)
        {
            root->left_val = Delete(root->left_val, val);
        }
        else if (val > root->val)
        {
            root->right_val = Delete(root->right_val, val);
        }
        else
        {
            if (root->left_val == NULL && root->right_val == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left_val == NULL)
            {
                Node *temp = root;
                root = root->right_val;
                delete temp;
            }
            else if (root->right_val == NULL)
            {
                Node *temp = root;
                root = root->left_val;
                delete temp;
            }
            else
            {
                Node *temp = Find_Pre(root->right_val);
                root->val = temp->val;
                root->right_val = Delete(root->right_val, temp->val);
            }
        }
        return root;
    }
	void Traverse_left(Node* Btree_root,int level)
	{	
		int val;
		if(level ==0)
		return;
		else if(level==1)
		{
			cout<<Btree_root->val<<endl;
		}
		Traverse_left(Btree_root->left_val, level-1);
		
	}
	void Traverse_right(Node* Btree_root,int level)
	{	
		int val;
		if(level ==0)
		return;
		else if(level==1)
		{
			cout<<Btree_root->val<<endl;
		}
		Traverse_left(Btree_root->right_val, level-1);
		
	}
};
int main()
{
    Node *Btree_root = NULL;
    Tree Tree1;
    Btree_root = Tree1.Insert_Node(Btree_root, 34);
    Tree1.Insert_Node(Btree_root,29);
    Tree1.Insert_Node(Btree_root,21);
    Tree1.Insert_Node(Btree_root,31);
    Tree1.Insert_Node(Btree_root,28);
    Tree1.Insert_Node(Btree_root,30);
    Tree1.Insert_Node(Btree_root,65);
    Tree1.Insert_Node(Btree_root,43);
    Tree1.Insert_Node(Btree_root,87);
    Tree1.Insert_Node(Btree_root,56);
	Tree1.Inorder(Btree_root);
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"Level "<<i+1<<endl;
		Tree1.Traverse_left(Btree_root,i+1);
		Tree1.Traverse_right(Btree_root,i+1);
		
	}
    return 0;
}