#include <iostream>
#include <math.h>
#include <cmath>
#include <queue>
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
    void LevelMinimum(Node *root)
    {
        if (root == NULL)
            return;

        queue<Node *> que;

        que.push(root);

        que.push(NULL);
        int lvl = 0;
        int minimum = 99999;
        int maximum = 99999;
        while (!que.empty())
        {

            Node *nod = que.front();
            que.pop();

            if (nod == NULL)
            {
                if (lvl == 0)
                {

                    cout << minimum << " " << minimum << endl;
                }
                else
                    cout << minimum << " " << maximum << endl;

                if (que.empty())
                    break;

                que.push(NULL);
                lvl++;
                minimum = 999999;
                maximum = -99999;
                continue;
            }

            if (maximum < nod->val)
                maximum = nod->val;

            if (minimum > nod->val)
                minimum = nod->val;

            if (nod->left_val != NULL)
                que.push(nod->left_val);

            if (nod->right_val != NULL)
                que.push(nod->right_val);
        }
    }
};
int main()
{
    Node *Btree_root = NULL;
    Tree Tree1;
    int n = 0, temp = 0;
    cin >> n;
    cin >> temp;
    Btree_root = Tree1.Insert_Node(Btree_root, temp);
    for (int i = 0; i < n - 1; i++)
    {
        temp = 0;
        cin >> temp;
        Tree1.Insert_Node(Btree_root, temp);
    }
    Tree1.LevelMinimum(Btree_root);

    return 0;
}
