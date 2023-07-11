#include <iostream>
#include <string>
using namespace std;
typedef struct
{
    string serialnumber;
    string collection;
} definition;
class Node
{
    string val;
    Node *right_val;
    Node *left_val;

public:
    Node(string val)
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
    definition *def;
    Node *Insert_Node(Node *root, string val)
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
    void Print_strings(int n)
    {
        for (int i = 0; i < n; i++)
        {

            cout << def[i].collection << endl;
            cout << def[i].serialnumber << endl;
        }
    }
    void Inorder(Node *root, int n)
    {
        string temp;
        if (root == NULL)
        {
            return;
        }
        Inorder(root->left_val, n);
        //cout << root->val << endl;
        temp = root->val;
        finder(temp, n);
        Inorder(root->right_val, n);
    }
    void numberify(definition *sample)
    {
        string temp;
        temp = sample->collection;
        sample->serialnumber = temp.substr(0, temp.find(" "));
        //cout << "After numberify" << sample->serialnumber << endl;
    }
    void finder(string sent, int n)
    {
        string temp;
        temp+=sent;
        int check = 0;
        for (int i = 0; i < n; i++)
        {
            check = def[i].collection.find(sent);
            if (check != string ::npos)
            {
                temp+=" ";
                temp+=def[i].serialnumber;
            }
        }
        cout<<temp;
        cout<<endl;
    }
};

int main()
{
    Node *Btree_root = NULL;
    Tree Tree1;
    int n = 0, no_of_strings = 0;
    string temp;
    fflush(stdin);
    //cout << "Enter the number of strings you want in the binary tree\n";
    cin >> n;
    //cout << "Enter the values in the binary tree\n";
    fflush(stdin);
    getline(cin, temp);
    Btree_root = Tree1.Insert_Node(Btree_root, temp);
    for (int i = 0; i < n - 1; i++)
    {
        temp = "";
        fflush(stdin);
        getline(cin, temp);
        Tree1.Insert_Node(Btree_root, temp);
    }
    //cout << "Enter number of strings\n";
    fflush(stdin);
    cin >> no_of_strings;
    //cout << "Enter strings\n";

    Tree1.def = new definition[no_of_strings];
    for (int i = 0; i < no_of_strings; i++)
    {
        fflush(stdin);
        getline(cin, Tree1.def[i].collection);
        Tree1.numberify(&Tree1.def[i]);
    }
    //Tree1.Print_strings(no_of_strings);
    Tree1.Inorder(Btree_root, no_of_strings);
}
