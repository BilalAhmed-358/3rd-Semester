#include <iostream>

using namespace std;
class Node
{
    public:

   int data; 
   Node *right; 
   Node *left;

  
   Node()
   {
       right=NULL;
       left=NULL;
   }
   
   Node(int key)
   {
       right=NULL;
       left=NULL;
       data=key;
   }
};
class BST

{
  Node *head;
  public:
  
  BST()
  {
      head=NULL;
  }
  
  BST(int key)
  {
      head=new Node;
      head->data=key;
  }
  	void Preorder(Node* root)
		{
			cout<<root->data<<" ";
			Preorder(root->left);
			Preorder(root->right);
			
		}
		void Inorder(Node* root)
		{
			Inorder(root->left);
			cout<<root->data<< " ";
			Inorder(root->right);
		}
		void Postorder(Node *root)
		{
			Postorder(root->left);
			Postorder(root->right);
			cout<<root->data;
		}
  Node* insert(Node *n,int key)
  {
      if(n==NULL)
      {
          n=new Node(key);
          return n;
      }
      
      if(n->data<key)
      {
          n->right=insert(n->right,key);
      }
      
      else if(n->data>key){
          n->left=insert(n->left,key);
      }
      return n;
      
  }
  
  void print(Node *n)
  {
      if(n!=NULL){
          print(n->left);
          cout<<n->data<<" ";
          print(n->right);
      }
  }
  Node* gethead(){
      return head;
  }
};

int main()
{
    
    BST ob1(8);
    ob1.insert(ob1.gethead(),3);
    ob1.insert(ob1.gethead(),5);
    ob1.insert(ob1.gethead(),7);
    ob1.print(ob1.gethead());
    return 0;
}
