#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
const int T_S = 200;
class HashTableEntry
{
public:
    int k;
    string v;
    HashTableEntry(int k, string v)
    {
        this->k = k;
        this->v = v;
    }
};
class HashMapTable
{
private:
    int count;
    HashTableEntry **t;

public:
    HashMapTable()
    {
        t = new HashTableEntry *[T_S];
        for (int i = 0; i < T_S; i++)
        {
            t[i] = NULL;
        }
        count = 0;
    }
    int HashFunc(int k)
    {
        return k % 79;
    }
    void Insert(int k, string v)
    {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k)
        {
            h = HashFunc(h + 1);
        }
        if (t[h] != NULL)
            delete t[h];
        t[h] = new HashTableEntry(k, v);
        count++;
    }
    int IsEmpty()
    {
        if (count == 0)
        {
            cout << "The Hashtable is empty.\n";
            return 1;
        }
        else
        {
            cout << "The Hastable is not empty\n";
            return 0;
        }
    }
    void Print()
    {
        if (count == 0)
        {
            cout << "The table is empty.\n";
            return;
        }
        for (int i = 0; i < T_S; i++)
        {
            if (t[i] != NULL)
                cout << t[i]->v << endl;
        }
    }
    string SearchKey(int k)
    {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k)
        {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
        {
            cout << "No entry exists for the given key\n";
            return "";
        }
        else
            return t[h]->v;
    }
    void Remove(int k)
    {
        int h = HashFunc(k);
        while (t[h] != NULL)
        {
            if (t[h]->k == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
        {
            cout << "No Element found at key " << k << endl;
            return;
        }
        else
        {
            delete t[h];
            t[h] = NULL;
            count--;
        }
        cout << "Element Deleted" << endl;
    }
    int Number_of_elements()
    {
        cout << "The number of elements in the hash table are " << count << "." << endl;
    }
    ~HashMapTable()
    {
        for (int i = 0; i < T_S; i++)
        {
            if (t[i] != NULL)
                delete t[i];
            delete[] t;
        }
    }
};
int main()
{
    HashMapTable hashTab;
    cout << "Determinig whether the contact book is Empty or not.\n";
    hashTab.IsEmpty();
    cout << "Determining the size of the hashbook.\n";
    hashTab.Number_of_elements();
    cout << "Size after inserting some elements\n";
    hashTab.Insert(1083, "Bilal Ahmed");
    hashTab.Insert(1857, "Wamiq Akram");
    hashTab.Insert(1090, "Zulnoor Siddiqui");
    hashTab.Insert(1292, "Talha");
    hashTab.Insert(1456, "Muaaz");
    hashTab.Insert(2045, "Amin");
    cout << "Determining the size of the hashbook after the insertion of some elements.\n";
    hashTab.Number_of_elements();
    cout<<"Elements in the hastable are\n";
    hashTab.Print();
    string s1 = hashTab.SearchKey(1083);
    if (s1!="")
    {
        cout << "Element found!" << endl;
        cout << s1<<endl;
    }
    cout<<"Deleting the element with key 1083 i.e. Bilal Ahmed.\n";
    hashTab.Remove(1083);
    cout<<"The number of elements after deletion\n";
    hashTab.Number_of_elements();
    cout<<"The hashtable after deletion of the element.\n";
    hashTab.Print();
}
