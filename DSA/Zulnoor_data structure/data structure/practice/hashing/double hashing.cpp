 #include <iostream>
using namespace std;
const int T_S = 13;
const int prime = 7;
class doublehash
{
	int *htable;
	int current;
	public:
		bool isfull()
		{
			return(current==T_S);
		}
		bool isempty()
		{
			return(current==0);
		}
		int hash1(int k)
		{
			return (k%T_S);
		}
		int hash2(int k)
		{
			return (prime - (k%prime));
		}
		doublehash()
		{
			htable = new int [T_S];
			current=0;
			for(int i=0;i<T_S;i++)
			{
				htable[i]=-1;
			}
		}
		void insert(int k)
		{
			if(isfull())
			{
				cout<<"can not add element "<<k<<" hash table is full"<<endl;
				return;
			}
			
			int index = hash1(k);
			
			if(htable[index]!=-1)
			{
				int index2 = hash2(k);
				int i=1;
				while(1)
				{
					int ninddex = (index + i * index2) % T_S;
					
					if(htable[ninddex]==-1)
					{
						htable[ninddex] = k;
						break;
					}
					
					i++;
				}
			}
			else
			{
				htable[index] = k;
			}
			current++;
		}
		void search(int k)
		{	
			int flag=0;
			if(isempty())
			{
				cout<<"hash table is empty"<<endl;
				return;
			}
			
			int index = hash1(k);
			
			if(htable[index]!=k)
			{
				int index2 = hash2(k);
				int i=1;
				while(1)
				{
					int ninddex = (index + i * index2) % T_S;
					
					if(htable[ninddex]==k)
					{
						cout<<k<<" found at index "<<ninddex<<endl;
						break;
					}
					if(i>T_S)
					{
						cout<<"element "<<k<<" not found in hash table"<<endl;
						return;
					}
					i++;
				}
			}
			else
			{
				cout<<k<<" found at index "<<index<<endl;
			}
			flag++;
			if(flag>=T_S)
			{
				cout<<"element "<<k<<" not found in hash table"<<endl;
				return;
			}
		}
		void display()
		{
			cout<<"elements in hashtable are"<<endl;
			for(int i=0;i<T_S;i++)
			{
				if (htable[i] != -1) 
                cout << i << " --> "
                     << htable[i] << endl; 
            else
                cout << i << " --> "
                     <<"no data" << endl; 
			}
		}
};

int main()
{
	doublehash d;
	d.insert(14);
	d.insert(5);
	d.insert(7);
	d.insert(9);
	d.insert(13);
	d.display();
	d.search(13);
	//d.search();
	d.search(22);
}
