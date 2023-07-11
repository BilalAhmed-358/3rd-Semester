#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{

    int coff;
    char base;
    int expo;
    int count;
    Node *next;

public:
    Node()
    {
        next = NULL;
        count = 0;
    }
    friend class Poly;
};
class Poly
{
public:
    void Insert(int coff, char base, int expo, Node *&head)
    {
        if (head == NULL)
        {
            Node *node = new Node;
            node->coff = coff;
            node->base = base;
            node->expo = expo;
            node->next = NULL;
            head = node;
            head->count++;
        }
        else
        {
            Node *node = new Node;
            node->coff = coff;
            node->base = base;
            node->expo = expo;
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node->next = NULL;
            temp->next = node;
            head->count++;
        }
    }
    void Print(Node *&head)
    {
        Node *temp = head;
        cout << head->count << endl;
        while (temp != NULL)
        {
            cout << temp->coff << " " << temp->base << " " << temp->expo << endl;
            temp = temp->next;
        }
    }
    int Add(Node *&head1, Node *&head2, Node *&head3)
    {
        Node *temp1 = head1;
        Node *temp2 = head2;
        Node *temp3 = head3;
        int count = 0;
        if (temp1 == NULL || temp2 == NULL)
        {
            exit(0);
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->expo == temp2->expo && temp1->base == temp2->base)
            {
                Insert((temp1->coff) + (temp2->coff), temp1->base, temp1->expo, head3);
                temp1 = temp1->next;
                temp2 = temp2->next;
                count++;
            }
            else if (temp1->expo < temp2->expo)
            {
                Insert(temp1->coff, temp1->base, temp1->expo, head3);
                temp1 = temp1->next;
                count++;
            }
            else
            {
                Insert(temp2->coff, temp2->base, temp2->expo, head3);
                count++;
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            Insert(temp1->coff, temp1->base, temp1->expo, head3);
            count++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            Insert(temp2->coff, temp2->base, temp2->expo, head3);
            count++;
            temp2 = temp2->next;
        }
        return count;
    }
    void Sort(Node *&head, int m)
    {
        Node *temp1 = head;
        Node *temp2 = head->next;
        int d;
        for (int i = 0; i < m; i++)
        {
            temp1 = head;
            temp2 = head->next;
            for (int j = 0; j < m - 1 - i; j++)
            {
                if (temp1->expo > temp2->expo || temp1->base > temp2->base)
                {

                    swap(temp1->coff, temp2->coff);
                    swap(temp1->base, temp2->base);
                    swap(temp1->expo, temp2->expo);
                }
                temp1 = temp2;
                temp2 = temp1->next;
            }
        }
    }
};
int main()
{
    Node *EQ1 = NULL, *EQ2 = NULL, *EQ3 = NULL;
    Poly EQS;
    int m1, m2, m3;
    cin >> m1;
    int coff, expo;
    char base;
    for (int i = 0; i < m1; i++)
    {
        cin >> coff >> base >> expo;
        EQS.Insert(coff, base, expo, EQ1);
    }
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        cin >> coff >> base >> expo;
        EQS.Insert(coff, base, expo, EQ2);
    }
    EQS.Sort(EQ1, m1);
    EQS.Sort(EQ2, m2);
    m3 = EQS.Add(EQ1, EQ2, EQ3);
    EQS.Sort(EQ3, m3);
    EQS.Print(EQ3);
}