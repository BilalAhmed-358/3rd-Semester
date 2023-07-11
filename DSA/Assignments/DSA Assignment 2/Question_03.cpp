#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int time;
    int quota;
    Node *next;
    Node()
    {
        next = NULL;
        time = 0;
        quota = 0;
        name = ' ';
    }
    friend class CircularLinkedList;
};

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
    }
    void Insert_at_tail(string name, int time, int quota)
    {
        if (head == NULL)
        {
            Node *temp = new Node;
            temp->name = name;
            temp->time = time;
            temp->quota = quota;
            // cout<<temp->name;
            temp->next = temp;
            head = temp;
        }
        else
        {
            Node *temp = new Node;
            Node *newnode = new Node;
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newnode->name = name;
            newnode->time = time;
            newnode->quota = quota;
            temp->next = newnode;
            newnode->next = head;
        }
    }
    void PrintList()
    {
        if (head == NULL)
        {
            cout << "The list is empty.\n";
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            do
            {
                if (temp->time > 0)
                {
                    cout << temp->name << endl;
                    temp->time = temp->time - temp->quota;
                }
                temp = temp->next;
            } while (temp != head);
        }
    }
    void Sequence()
    {
        int max = -99999;
        if (head == NULL)
        {
            cout << "The list is empty.\n";
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            do
            {
                if (max <= (temp->time / temp->quota))
                {
                    max = (temp->time / temp->quota);
                }
                temp = temp->next;
            } while (temp != head);
        }
        // cout << "max is " << max << endl;
        for (int i = 0; i < max; i++)
        {
            PrintList();
        }
        
    }
};

int main()
{
    int n = 0;
    cin >> n;
    int time = 0, quota = 0;
    string name;
    CircularLinkedList L1;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> time;
        cin >> quota;
        L1.Insert_at_tail(name, time, quota);
    }
    L1.Sequence();
}