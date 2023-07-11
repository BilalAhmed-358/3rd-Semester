#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList();
    LinkedList(int n)
    {
        head = new Node;
        head->data = n;
        head->next = NULL;
    }
    void Insert_at_head(int n)
    {
        Node *temp=new Node;
        temp->data=n;
        temp->next=head;
        head=temp;
        
        
    }
    void Insert_at_tail(int n)
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
    void Print_List()
    {
        Node *temp=head;
        cout<<temp->data<<endl;
        while (temp->next!=NULL)
        {
            temp=temp->next;
            cout<<temp->data<<endl;
        }
        
    }
};

int main()
{
    LinkedList L1(1);
    L1.Insert_at_tail(2);
    L1.Insert_at_tail(3);
    L1.Insert_at_tail(4);
    L1.Insert_at_tail(5);
    L1.Insert_at_tail(6);
    L1.Insert_at_tail(7);
    L1.Insert_at_tail(8);
    L1.Insert_at_tail(9);
    L1.Insert_at_tail(10);
    L1.Insert_at_tail(20);
    L1.Insert_at_head(12);
    L1.Print_List();
}
