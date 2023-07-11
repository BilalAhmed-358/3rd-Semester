#include <iostream>
using namespace std;
const int T_S = 10;
class HashTableEntry
{
	public:
		int k;
		int v;
		HashTableEntry(int key,int val)
		{
			k=key;
			v=val;
		}
};
class HashMapTable{
	private:
		HashTableEntry **t;
	public:
		HashMapTable()
		{
			t=new HashTableEntry *[T_S];
			for(int i=0;i<T_S;i++)
			{
				t[i]=NULL;
			}
		}
		
		int hashfunc(int k)
		{
			return k%T_S;
		}
		
		void insert(int k,int v)
		{
			int h=hashfunc(k);
			while(t[h]!=NULL)
			{
				h=hashfunc(k+1);
			}
			t[h]=new HashTableEntry(k,v);
		}
		int searchkey(int k)
		{
			int h=hashfunc(k);
			while(t[h]!=NULL && t[h]->k!=k)
			{
				h=hashfunc(k+1);
			}
			if(t[h]==NULL)
				return -1;
			else
				return t[h]->v;
		}
		void remove(int k)
		{
			int h=hashfunc(k);
			while(t[h]!=NULL)
			{
				if(t[h]->k==k)
					break;
				h=hashfunc(k+1);
			}
			if(t[h]==NULL)
			{
				cout<<"No value found at key "<<k<<endl;
				return;
			}
			else
			{
				delete t[h];
			}
			cout<<"Element deleted"<<endl;
		}
		
		void disp()
		{
			for(int i=0;i<T_S;i++)
			{
				if(t[i]==NULL)
					continue;
				else
				{
					cout<<"KEY: "<<t[i]->k<<" ";
					cout<<"VALUE: "<<t[i]->v<<endl;
				}
			}
		}
		
		~HashMapTable()
		{
			for(int i=0;i<T_S;i++)
			{
				if(t[i]!=NULL)
					delete t[i];
			}
			delete[] t;
		}
};

int main()
{
	HashMapTable hash;
	int k;
	int v;
	int c;
	while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Display hashtable"<<endl;
	  cout<<"5.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.searchkey(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.searchkey(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.remove(k);
         break;
         case 4:
         	cout<<"elements of hash table are"<<endl;
			hash.disp();
			break;
         case 5:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}
