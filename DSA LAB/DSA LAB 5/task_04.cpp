#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
    int data;
    Node *next;
    int key;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->key = 0;
    }
    Node(int data, int key, Node *ptr)
    {
        this->data = data;
        this->key = key;
        this->next = ptr;
    }
    friend class List;
};

class List
{
public:
    Node *head;

    List();
    List(int);
    void Print();
    void Insert_at_end(int n);
    void Insert_at_Front(int n);
    void insertNodeAfter(int key_after, int n);
};
List::List(int n)
{
    head = new Node;
    head->data = n;
    head->next = NULL;
    head->key++;
}
List::List()
{
    head = NULL;
}
void List::Print()
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
void List::Insert_at_end(int n)
{
    Node *newnode = new Node;
    newnode->data = n;
    newnode->next = NULL;
    if (head != NULL)
    {

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->key = (temp->key) + 1;
    }
    else
    {
        head = newnode;
        head->key = 1;
    }
}
void List::Insert_at_Front(int n)
{
    Node *newnode = new Node;
    Node *temp = head;

    newnode->data = n;
    newnode->next = head;
    newnode->key = 1;

    while (temp != NULL)
    {
        // cout << "\nKey increment ran 02.\n";
        temp->key++;
        temp = temp->next;
    }
    head = newnode;
}
void List::insertNodeAfter(int key_after, int n)
{
    Node *temp = head;
    Node *newnode = new Node;
    while (temp != NULL && temp->key != key_after)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    else
    {
        newnode->data = n;
        newnode->next = temp->next;
        newnode->key = (temp->key)+1;
        temp->next = newnode;
        temp = temp->next->next;
        // temp = temp->next;
        while (temp != NULL)
        {
            temp->key = temp->key + 1;
            temp = temp->next;
        }
    }
}

int main()
{
    List l1;
    l1.Insert_at_Front(2);
    l1.Insert_at_Front(1);
    l1.Insert_at_end(3);
    l1.Insert_at_end(4);
    l1.Insert_at_end(5);
    l1.Insert_at_end(6);
    l1.Insert_at_end(7);
    l1.Insert_at_end(8);
    l1.Insert_at_end(9);
    l1.Insert_at_end(10);
    l1.insertNodeAfter(9, 10);
    l1.Print();
}
