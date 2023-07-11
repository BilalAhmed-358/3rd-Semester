
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
    void Del_last_node();
    void Del_any_node(int del_key);
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
        newnode->key = (temp->key) + 1;
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
void List::Del_last_node()
{
    Node *temp = new Node;
    Node *del = new Node;
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    del = temp->next;
    temp->next = NULL;
    del->data = 0;
    del->key = 0;
    del->next = NULL;
    delete del;
}
void List ::Del_any_node(int del_key)
{
    Node *temp = new Node;
    Node *del = new Node;
    temp = head;
    if (del_key == 1)
    {
        del = head;
        head = temp->next;
        del->data = 0;
        del->key = 0;
        del->next = NULL;
        delete del;
        temp=head;
        while (temp != NULL)
        {
            temp->key = (temp->key) - 1;
            temp = temp->next;
        }
        return;
    }

    while (temp->next->key != del_key)
    {
        temp = temp->next;
    }
    del = temp->next;
    temp->next = temp->next->next;
    temp = temp->next;
    while (temp != NULL)
    {
        temp->key = (temp->key) - 1;
        temp = temp->next;
    }

    del->data = 0;
    del->key = 0;
    del->next = NULL;
    delete del;
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
    cout<<"Deleting the first node\n";
    l1.Del_any_node(1);
    l1.Print();
    cout<<"Deleting the fifth node\n";
    l1.Del_any_node(5);
    l1.Print();
}
