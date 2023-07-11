#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string sent;
    Node *next;
    Node *prev;
    Node()
    {
        this->sent = " ";
    }
    Node(string sent)
    {
        this->sent = sent;
    }
    void change_val(string sent)
    {
        this->sent = sent;
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
    void Insert_at_head(string sent)
    {
        if (head != NULL)
        {
            Node *temp = new Node;
            Node *temp2 = new Node;
            temp2 = head;
            temp->sent = sent;
            head = temp;
            temp->next = temp2;
        }
        else
        {

            Node *temp = new Node;
            temp->sent = sent;
            temp->next = NULL;
            head = temp;
        }
    }
    void Insert_at_tail(string sent)
    {
        if (head != NULL)
        {
            Node *temp = new Node;
            Node *temp2 = new Node;
            temp->sent = sent;
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
            temp->sent = sent;
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
                cout << temp->sent << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
    void Delete(string str)
    {
        Node *temp = new Node;
        Node *del = new Node;
        temp = head;
        while (temp->next->sent != str)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        del->next + NULL;
        del->prev = NULL;
        del->sent = "";
        delete del;
    }
    void SeparateWords(string str)
    {
        string word;
        stringstream iss(str);

        while (iss >> word)
            Insert_at_tail(word);
    }
    void Arrange()
    {
        Node *temp1 = new Node;
        Node *temp2 = new Node;
        Node *X = new Node;
        string st1;
        string st2;
        temp1 = head;
        int checker = 1;
        for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
        {

            for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
            {
//                if ((temp1->sent[0] >= 65 && temp1->sent[0] < 90) && (temp2->sent[0] >= 97 && temp2->sent[0] < 112))
//                {
//                    st1 = temp1->sent;
//                    st1[0] = st1[0] + 32;
//                    if (st1[0] > temp2->sent[0])
//                        swap(temp1, temp2);
//                }
//                if ((temp2->sent[0] >= 65 && temp2->sent[0] < 90) && (temp1->sent[0] >= 97 && temp1->sent[0] < 112))
//                {
//                    st1 = temp2->sent;
//                    st1[0] = st1[0] + 32;
//                    if (st1[0] > temp1->sent[0])
//                        swap(temp1, temp2);
//                }
//                else 
				if (temp1->sent[0] > temp2->sent[0])
                {
                	if()
                	swap(temp1, temp2);
				}
				    
            }
        }
    }
    char lower_string(string str)
    {
        if (str[0] >= 'A' && str[0] <= 'Z')
        {
            str[0] = str[0] + 32;
        }
        return str[0];
    }
    void swap(Node *ptr1, Node *ptr2)
    {
        Node *temp = new Node;
        temp->sent = ptr2->sent;
        ptr2->sent = ptr1->sent;
        ptr1->sent = temp->sent;
    }
    void Duplicate_Remove()
    {
        Node *temp1 = new Node;
        Node *temp2 = new Node;
        for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
        {

            for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
            {
                if (temp1->sent == temp2->sent)
                    Delete(temp2->sent);
            }
        }
    }
};

int main()
{
    string sentence;
    getline(cin, sentence);
    List L1;
    L1.SeparateWords(sentence);
    // L1.PrintList();
    L1.Duplicate_Remove();
    L1.Arrange();
    L1.PrintList();
}
