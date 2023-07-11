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
    void Insert_at_end(int n)
    {
        Node *newnode = new Node;
        newnode->data = n;
        newnode->next = NULL;
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void Insert_at_Front(int n)
    {
        Node *newnode= new Node;
        newnode->data=n;
        newnode->next=head;
        head=newnode;
    }
};

int main()
{
    List L1(9);
    cout<<"Calling print func after adding head\n";
    L1.Print();
    cout<<"Calling print func after adding an element at the front\n";
    L1.Insert_at_Front(1);
    L1.Print();
}