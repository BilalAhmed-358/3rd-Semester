
#include <iostream>
#include <stdio.h>
#include<string.h>
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
    void Update_node(int update_key, int value);
    void Arrange_linked_list();

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
void List:: Update_node(int update_key, int value)
{
    Node* temp=new Node;
    temp=head;
    while (temp->key!=update_key)
    {
        temp=temp->next;
    }
    temp->data=value;
    
}
void List:: Arrange_linked_list()
{
    Node *temp=new Node;
    temp=head;
    int count=0, odd_count=0,even_count=0,temp_count_1=0,temp_count_2=0;
    while (temp!=NULL)//Determining the total number of elements in the List Plus the number of odd and even elements
    {
        if ((temp->data)%2==0)
        {
            even_count++;
        }
        else
            odd_count++;
        temp=temp->next;
        count++;
        
    }
    int array[11]={0};
    int *even_array= new int [even_count];//Array for storing even values
    memset(even_array,0,even_count*sizeof(int));
    int *odd_array= new int [odd_count];//Array for storing odd values
    memset(odd_array,0,odd_count*sizeof(int));
    temp=head;
    for (int i = 0; i < count; i++)
    {
      
        array[i]=temp->data;
        temp=temp->next;
    }

    
    for (int i = 0,temp_count=0; i < count; i++)//Putting values in the array of even elements
    {
        if (array[i]%2==0)
        {
            even_array[temp_count]=array[i];
            temp_count++;
        }
        
    }
    
    
    for (int i = 0,temp_count=0; i < count; i++)//Putting the values in the array of odd
    {
        if (array[i]%2!=0)
        {
            odd_array[temp_count]=array[i];
            temp_count++;
        }
        
    }

    temp=head;
    
    for (int i = 0,temp_count_1=0,temp_count_2=0; i < count; i++)
    {   
        if (i<even_count)
        {   
            temp->data=even_array[temp_count_1];
            temp_count_1++;
            temp=temp->next;
        }
        else
        {
            temp->data=odd_array[temp_count_2];
            temp_count_2++;
            temp=temp->next;
        } 
    }
    
}
int main()
{
    List l1;
    l1.Insert_at_Front(17);
    l1.Insert_at_end(15);
    l1.Insert_at_end(8);
    l1.Insert_at_end(12);
    l1.Insert_at_end(10);
    l1.Insert_at_end(5);
    l1.Insert_at_end(4);
    l1.Insert_at_end(1);
    l1.Insert_at_end(7);
    l1.Insert_at_end(6);
    l1.Print();
    l1.Arrange_linked_list();
    cout<<"After arranging the list becomes\n";
    l1.Print();
    
}
