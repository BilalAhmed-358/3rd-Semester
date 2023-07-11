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
    void Insert_at_head(int Exponent, int Coefficient, char Base)
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

    void PrintList()
    {
        if (head != NULL)
        {
            Node *temp = new Node;
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
                    cout << temp->Coefficient << temp->Base << temp->Exponent << "+";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
};

int main()
{
    List l1;
    l1.Insert_at_head(0, 3, ' ');
    l1.Insert_at_head(3, 2, 'X');
    l1.Insert_at_head(4, 4, 'X');
    l1.Insert_at_head(5, 2, 'X');
    l1.Insert_at_head(6, 2, 'X');
    l1.Insert_at_head(8, 3, 'X');
    l1.PrintList();
    List l2;
    l2.Insert_at_head(2, 0, 'X');
    l2.Insert_at_head(4, 0, 'X');
    l2.Insert_at_head(8, 2, 'X');
    l2.PrintList();
    cout << "Adding both lists we get\n";
}