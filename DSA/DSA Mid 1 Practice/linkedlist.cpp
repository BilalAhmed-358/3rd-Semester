#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class Linkedlist
{
    node *head;

public:
    Linkedlist();
    Linkedlist(int);
    Linkedlist(const Linkedlist &);
    Linkedlist &operator=(const Linkedlist &);
    void insert_head(int data);
    void insert_tail(int data);
    void delete_tail();
    void delete_head();
    void delete_node_no(int index);
    void insert(int index, int data);
    int search(int data) const;
    void sort();
    void reverse_list();
    int get_size() const;
    void print();
    ~Linkedlist();
};
void Linkedlist::sort()
{
    node *temp = head, *temp1 = head->next;
    int d;
    for (int i = 0; i < get_size(); i++)
    {
        temp = head;
        temp1 = head->next;
        for (int j = 0; j < get_size() - 1 - i; j++)
        {
            if (temp->data > temp1->data)
            {
                d = temp->data;
                temp->data = temp1->data;
                temp1->data = d;
            }
            temp = temp1;
            temp1 = temp->next;
        }
    }
}
Linkedlist::Linkedlist()
{
    head = NULL;
}
Linkedlist::Linkedlist(int d)
{
    head = new node;
    head->data = d;
    head->next = NULL;
}
void Linkedlist::print()
{
    node *temp = head;
    cout << temp->data << endl;
    while (temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << endl;
    }
}
Linkedlist::Linkedlist(const Linkedlist &rhs)
{
    if (rhs.head != NULL)
    {
        node *temp = rhs.head;
        node *temp1 = NULL;
        temp1 = new node;
        head = temp1;
        temp1->data = temp->data;
        temp1->next = NULL;
        if (temp->next != NULL)
        {

            while (temp->next != NULL)
            {
                temp = temp->next;
                temp1->next = new node;
                temp1 = temp1->next;
                temp1->data = temp->data;
                temp1->next = NULL;
            }
        }
    }
    else
    {
        head = NULL;
    }
}
Linkedlist::~Linkedlist()
{
    if (head != NULL)
    {
        node *temp = head;
        int i = 1;
        while (head->next != NULL)
        {
            temp = head;
            head = head->next;
            i++;
            delete temp;
        }
        delete head;
        cout << endl
             << "Deleting " << i << " items\n";
    }
    head = NULL;
}
Linkedlist &Linkedlist::operator=(const Linkedlist &rhs)
{
    if (this != &rhs && rhs.head != NULL)
    {
        this->~Linkedlist();
        node *temp = rhs.head;
        node *temp1 = new node;
        head = temp1;
        temp1->data = temp->data;
        temp1->next = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
            temp1->next = new node;
            temp1 = temp1->next;
            temp1->data = temp->data;
            temp1->next = NULL;
        }
    }
    return *this;
}
void Linkedlist::insert_head(int d)
{
    node *temp = new node;
    temp->data = d;
    temp->next = head;
    head = temp;
}

void Linkedlist::insert_tail(int d)
{
    node *newnode = new node;
    newnode->data = d;
    newnode->next = NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void Linkedlist::delete_head()
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void Linkedlist::delete_tail()
{
    node *temp = head;
    node *to_delete_next = NULL;
    while (temp->next != NULL)
    {
        to_delete_next = temp;
        temp = temp->next;
        if (temp->next == NULL)
        {
            to_delete_next->next = NULL;
        }
    }
    delete temp;
}

void Linkedlist::delete_node_no(int index)
{
    if (index <= get_size() && index > 0)
    {
        node *temp = head, *temp1;
        for (int i = 1; i < index; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        delete temp;
    }
    else
    {
        cout << "\nNode doesnot exist\n";
    }
}
int Linkedlist::get_size() const
{
    int i = 0;
    if (head != NULL)
    {
        node *temp = head;
        i++;
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
    }
    return i;
}

void Linkedlist::insert(int index, int d)
{
    if (index <= get_size() + 1 && index > 0)
    {
        node *temp = head, *temp1;
        for (int i = 1; i < index; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        node *new_node = new node;
        new_node->data = d;
        new_node->next = temp1->next;
        temp1->next = new_node;
    }
    else
    {
        cout << "\nNode out of bound\n";
    }
}
void Linkedlist::reverse_list()
{
    if (head != NULL)
    {
        node *temp = head, *temp1;
        if (temp->next != NULL)
        {
            head = temp->next;
            temp->next = NULL;
            while (head->next != NULL)
            {
                temp1 = head;
                head = head->next;
                temp1->next = temp;
                temp = temp1;
            }
            head->next = temp;
        }
    }
}
int Linkedlist::search(int d) const
{
    node *temp = head;
    int i = 1;
    while (temp->next != NULL)
    {
        if (temp->data == d)
        {
            return i;
        }
        temp = temp->next;
        ++i;
    }
    cout << "\nNot found";
    return 0;
}
int main()
{
    Linkedlist ob1(3);
    ob1.insert_head(6);
    ob1.insert_tail(92);
    ob1.insert_head(3);
    ob1.insert_head(7);
    ob1.insert_head(9);
    ob1.insert(3, 87);
    ob1.print();
    ob1.reverse_list();
    cout << "\nNEW list\n";
    ob1.print();
    ob1.reverse_list();
    cout << "\nNEW list\n";
    ob1.sort();
    ob1.print();
    cout << "\nfound at index:" << ob1.search(87) << endl;
    Linkedlist ob2;
    ob2 = ob1;
    cout << "\nOB2\n";
    ob2.print();
}