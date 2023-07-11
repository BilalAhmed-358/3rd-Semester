#include<iostream>
#include<fstream>
#include <queue>
using namespace std;

template<class T>
class node;
template<class T>
class Tree;

template<class T>
class node{

    public:
    T data;
    int frequency;
    node<T> *left;
    node<T> *right;

    public:

    node(T data)
    {
        this->data = data;
        frequency = 1;
        left = right =   NULL;
    }
    
    void insert(T value)
    {
        if(data == value)
        {
            frequency++;
            return;
        }

        if(value < data)
        {
            if(left == NULL)
            left = new node<T>(value) ;
            else
            left->insert(value);                
            
        } else if(value > data)
        {
            if(right == NULL)
            right = new node<T>(value) ;
            else
            right->insert(value);                
            
        }
    }
	bool Search(T x)
    {
		if(left != NULL)
        left->Search(x);
		
		if(data==x)
        {
        	return true;
		}
		
        if(right != NULL)
        right->Search(x);
        
    }
    void traverseInOrder()
    {
        if(left != NULL)
        left->traverseInOrder();

        cout<<data<<" ";

        if(right != NULL)
        right->traverseInOrder();
    }
    void traversePostOrder()
    {
        if(left != NULL)
        left->traversePostOrder();
		
		if(right != NULL)
        right->traversePostOrder();
        
        cout<<data<<" ";
    }
    void traversePreOrder()
    {
    	cout<<data<<" ";
    	
        if(left != NULL)
        left->traversePreOrder();
		
		if(right != NULL)
        right->traversePreOrder();
    }
     node * minValueTreeNode( node* Node) 
	{ 
    	 node* current = Node; 
  
    
    	while (current && current->left != NULL) 
        	current = current->left; 
  
    	return current; 
	} 

	 node* nodedelete( node* root, T key) 
	{  
    	if (root == NULL) return root; 

	    if (key < root->data) 
    	    root->left = nodedelete(root->left, key); 
  
    	else if (key > root->data) 
        	root->right = nodedelete(root->right, key); 
    	else
   	 	{ 
        	if (root->left == NULL) 
        	{ 
            	node *temp = root->right; 
            	delete(root); 
            	return temp; 
        	}	 
        	else if (root->right == NULL) 
        	{ 
             	node *temp = root->left; 
            	delete(root); 
            	return temp; 
        	} 
         	node* temp = minValueTreeNode(root->right); 
        	root->data = temp->data; 
        	root->right = nodedelete(root->right, temp->data); 
    	} 
    	return root; 
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
	int bfs(node *root)
	{
		queue<node *>q;
		q.push(root);
		cout<<"breadth firt traversal: "<<endl;
		while(!q.empty())
		{
			node *current=q.front();
			cout<<current->data<<" ";
			if(current->left!=NULL) q.push(current->left);
			if(current->right!=NULL) q.push(current->right);
			q.pop();
		}
	}
	int bfsearch(node *root,T d)
	{
		int flag=0;
		queue<node *>q;
		q.push(root);
		while(!q.empty())
		{
			node *current=q.front();
			if(current->data==d)
			{
				cout<<"data "<<d<<" found in the tree"<<endl;
				flag++;
				break;
			}
			if(current->left!=NULL) q.push(current->left);
			if(current->right!=NULL) q.push(current->right);
			q.pop();
		}
		if(!flag)
			cout<<"data "<<d<<" not foundd in the tree"<<endl;
	}
};


template<class T>
class Tree{

    private:
    node<T> *root;

    public:
    Tree()
    {
        root = NULL;
    }

    void insert(T data)
    {
        if(root == NULL)
        root = new node<T>(data);
        else
        root->insert(data);
    }
    void traverseInOrder()
    {
        root->traverseInOrder();
    }
    void traversePostOrder()
    {
        root->traversePostOrder();
    }
    void traversePreOrder()
    {
        root->traversePreOrder();
    }
    void NodeSearch(T x)
    {
        if(root==NULL)
        	cout<<"no tree"<<endl;
        else
		{	
			int c=0;
			c=root->Search(x);
			if(c)
				cout<<x<<" found"<<endl;
			else
				cout<<x<<" not found"<<endl;	
    	}
    }
    void deletenode(T x)
    {
    	if(root==NULL)
        	cout<<"no tree"<<endl;
        else
		{	
			root->nodedelete(root,x);
		}
	}
	void leaveNode()
    {
    	int c=0;
		if(root==NULL)
        	cout<<"no tree"<<endl;
        else
		{	
			c=root->leaves(root);
			cout<<"number of leaf nodes in tree are: "<<c<<endl;
		}
	}
	void tree_height()
	{
		int h=0;
		h=root->height(root);
		cout<<"height of tree is: "<<h<<endl;
	}
	void breadth_first()
	{
		root->bfs(root);
	}
	void breadth_first_search(T d)
	{
		root->bfsearch(root,d);
	}
};

template<class T>
void AnalysisData(Tree<T> &chatData , Tree<T> &predData)
{
 // This function will make analysis
}

int main()
{

    Tree<int> *tree = new Tree<int>();
//5,4,8,6,7,10,2,18,14,15
    tree->insert(5);
    tree->insert(4);
    tree->insert(8);
    tree->insert(6);
    tree->insert(7);
    tree->insert(10);
    tree->insert(14);
    tree->insert(15);
    tree->insert(2);
    tree->insert(18);
    cout<<endl<<"IN-Order traversal:"<<endl;
    tree->traverseInOrder();
    cout<<endl<<"POST-Order traversal:"<<endl;
    tree->traversePostOrder();
    cout<<endl<<"PRE-Order traversal:"<<endl;
    tree->traversePreOrder();
    cout<<endl;
    tree->NodeSearch(14);
    cout<<endl;
    tree->tree_height();
    tree->deletenode(10);
    cout<<endl;
    cout<<"node having value 10 deleted";
    cout<<endl<<"IN-Order traversal:"<<endl;
    tree->traverseInOrder();
    cout<<endl;
    tree->leaveNode();
    cout<<endl;
    tree->tree_height();
    tree->breadth_first();
    int d;
    cout<<endl<<"enter data you want to search in tree: ";
    cin>>d;
    tree->breadth_first_search(d);
}
