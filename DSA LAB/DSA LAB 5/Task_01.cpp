#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data, Node *ptr)
    {
        this->data = data;
        this->next = ptr;
    }
    friend class List;
};

class List
{
public:
    Node *head;

    List() : head()
    {
        head = NULL;
    }
    List(int n)
    {
        head = new Node;
        head->data = n;
        head->next = NULL;
    }
    void Print()
    {
       Node *temp = head;
    cout << "Data: " << temp->data << endl;
    while (temp->next != NULL)
    {
        temp = temp->next;
        cout << "Data: " << temp->data << endl;
    }
    cout << endl;
    }
};

int main()
{
    List L1(9);
    L1.Print();
}