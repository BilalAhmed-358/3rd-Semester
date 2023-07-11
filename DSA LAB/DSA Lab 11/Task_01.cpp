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
    int v;
    HashTableEntry(int k, int v)
    {
        this->k = k;
        this->v = v;
    }
};
class HashMapTable
{
private:
    static int count;
    HashTableEntry **t;

public:
    HashMapTable()
    {
        count=0;
        t = new HashTableEntry *[T_S];
        for (int i = 0; i < T_S; i++)
        {
            t[i] = NULL;
        }
    }
    int HashFunc(int k)
    {
        return k % 79;
    }
    void Insert(int k, int v)
    {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k)
        {
            h = HashFunc(h + 1);
        }
        if (t[h] != NULL)
            delete t[h];
        t[h] = new HashTableEntry(k, v);
    }
    void Print()
    {
        if(count==0)
        {
            cout<<"The table is empty\n";
        }
        for (int i = 0; i < T_S; i++)
        {
            if (t[i] != NULL)
                cout << t[i]->v << endl;
        }
    }
    int SearchKey(int k)
    {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k)
        {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
            return -1;
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
        }
        cout << "Element Deleted" << endl;
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
    hashTab.Print();
    cout << "Inserting elements in the hashtable\n";
    hashTab.Insert(10, 20);
    hashTab.Insert(20, 40);
    hashTab.Insert(30, 60);
    hashTab.Insert(40, 80);
    cout << "Printing the hashtable\n";
    hashTab.Print();
    cout << "Deleting 40 from the hashtable\n";
    hashTab.Remove(20);
    cout << "Reprinting the hashtable again" << endl;
    hashTab.Print();
}