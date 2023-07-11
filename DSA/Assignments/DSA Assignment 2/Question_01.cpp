#include <iostream>
using namespace std;

class Node
{
public:
    int Coefficient;
    int Exponent;
    char Base;
    Node *next;
    Node()
    {
        this->Coefficient = 0;
        this->Exponent = 0;
        this->Base = ' ';
    }
    Node(int Coefficient, int Exponent, char Base)
    {
        this->Exponent = Exponent;
        this->Coefficient = Coefficient;
        this->Base = Base;
    }
    void change_val(int Coefficient, int Exponent, char Base)
    {
        this->Exponent = Exponent;
        this->Coefficient = Coefficient;
        this->Base = Base;
    }
    friend class List;
};

class List
{
public:
    Node *head;
    List()
    {
        this->head = NULL;
    }
    void Insert_at_head(int Coefficient, char Base, int Exponent)
    {
        if (head != NULL)
        {
            Node *temp = new Node;
            Node *temp2 = new Node;
            temp2 = head;
            temp->Exponent = Exponent;
            temp->Coefficient = Coefficient;
            temp->Base = Base;
            head = temp;
            temp->next = temp2;
        }
        else
        {

            Node *temp = new Node;
            temp->Exponent = Exponent;
            temp->Coefficient = Coefficient;
            temp->Base = Base;
            temp->next = NULL;
            head = temp;
        }
    }
    void Insert_at_tail(int Coefficient, char Base, int Exponent)
    {
        if (head != NULL)
        {
            Node *temp = new Node;
            Node *temp2 = new Node;
            temp->Exponent = Exponent;
            temp->Coefficient = Coefficient;
            temp->Base = Base;
            temp->next = NULL;
            temp2 = head;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
        else
        {

            Node *temp = new Node;
            temp->Exponent = Exponent;
            temp->Coefficient = Coefficient;
            temp->Base = Base;
            temp->next = NULL;
            head = temp;
        }
    }
    void PrintList()
    {
        if (head != NULL)
        {
            int count = 0;

            Node *temp = new Node;
            temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            cout << count << endl;

            temp = head;
            while (temp != NULL)
            {
                if (temp->Base == ' ' && temp->Exponent == 0)
                {
                    cout << temp->Coefficient;
                }
                else if (temp->Coefficient == 0)
                {
                    cout << temp->Base << temp->Exponent << "+";
                }
                else
                    cout << temp->Coefficient << " " << temp->Base << " " << temp->Exponent << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
    void Add(List const L1, List const L2)
    {

        Node *temp1 = new Node;
        Node *temp2 = new Node;
        temp1 = L1.head;
        temp2 = L2.head;
        while (temp1 != NULL && temp2 != NULL)
        {
            if ((temp1->Exponent == temp2->Exponent) && (temp1->Base == temp2->Base))
            {
                // cout << "condition 01 ran\n";
                Insert_at_tail(temp1->Coefficient + temp2->Coefficient, temp1->Base, temp1->Exponent);
                // cout << temp1->Coefficient + temp2->Coefficient << temp1->Base << temp1->Exponent << endl;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if ((temp1->Exponent < temp2->Exponent) && (temp1->Base == temp2->Base))
            {
                // cout << "condition 02 ran\n";
                Insert_at_tail(temp1->Coefficient, temp1->Base, temp1->Exponent);
                // cout << temp1->Coefficient << temp1->Base << temp1->Exponent << endl;
                temp1 = temp1->next;
            }
            else if ((temp1->Exponent > temp2->Exponent) && (temp1->Base == temp2->Base))
            {
                // cout << "condition 03 ran\n";
                Insert_at_tail(temp2->Coefficient, temp2->Base, temp2->Exponent);
                // cout << temp2->Coefficient << temp2->Base << temp2->Exponent << endl;
                temp2 = temp2->next;
            }
            else if (temp1->Base != temp2->Base)
            {
                // cout << "condition 04 ran\n";
                break;
            }
        }
        while (temp2 != NULL)
        {
            Insert_at_tail(temp2->Coefficient, temp2->Base, temp2->Exponent);
            // cout << temp2->Coefficient << temp2->Base << temp2->Exponent << endl;
            temp2 = temp2->next;
        }
        while (temp1 != NULL)
        {
            Insert_at_tail(temp1->Coefficient, temp1->Base, temp1->Exponent);
            // cout << temp1->Coefficient << temp1->Base << temp1->Exponent << endl;
            temp1 = temp1->next;
        }
    }
    void Arrange()
    {
        Node *temp1 = new Node;
        Node *temp2 = new Node;
        Node *X = new Node;
        temp1 = head;
        while (temp1 != NULL)
        {
            temp2 = temp1->next;
            while (temp2 != NULL)
            {
                if ((temp1->Exponent > temp2->Exponent) || (temp1->Base > temp2->Base))
                {
                    Swap(temp1, temp2);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
    void Swap(Node *temp1, Node *temp2)
    {
        Node *X = new Node;
        X->Coefficient = temp2->Coefficient;
        X->Base = temp2->Base;
        X->Exponent = temp2->Exponent;
        //X->next=temp2->next;

        temp2->Coefficient = temp1->Coefficient;
        temp2->Base = temp1->Base;
        temp2->Exponent = temp1->Exponent;
        //temp2->next=temp1->next;

        temp1->Coefficient = X->Coefficient;
        temp1->Base = X->Base;
        temp1->Exponent = X->Exponent;
        //temp1->next=X->next;
    }
};

int main()
{
    int num = 0, coeff = 0, exp = 0;
    char base = ' ';
    List l1;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> coeff;
        cin >> base;
        cin >> exp;
        l1.Insert_at_tail(coeff, base, exp);
    }
    l1.Arrange();
    List l2;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> coeff;
        cin >> base;
        cin >> exp;
        l2.Insert_at_tail(coeff, base, exp);
    }
    l2.Arrange();
    // cout << "List 1 is\n";
    // l1.PrintList();
    // cout << "List 2 is\n";
    // l2.PrintList();
    List L3;
    L3.Add(l1, l2);
    L3.Arrange();
    L3.PrintList();
}