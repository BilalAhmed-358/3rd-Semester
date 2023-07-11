#include<iostream>
#include "node.h"
#include "dll.h"
using namespace std;
int main()
{
	dll d;
	d.insert_at_beg(10);
	d.insert_at_beg(15);
	d.insert_at_end(18);
	d.insert_at_end(20);
	d.display();
	int n,num;
	cout<<"enter node number to enter number"<<endl;
	cout<<"after ";
	cin>>n;
	cout<<"inserting node after node num "<<n<<endl;
	d.insert_after(22,n);
	d.display();
//	cout<<"before: ";
//	cin>>n;
//	cout<<"inserting node before node num "<<n<<endl;
//	d.insert_before(13,n);
//	d.display();
//	cout<<"enter a number you want to search in the list: ";
//	cin>>num;
//	d.search(num);
//	cout<<endl<<"deleting 1st node"<<endl;
//	d.delete_1st();
//	cout<<endl<<"deleting last node"<<endl;
//	d.delete_last();
	cout<<endl<<"enter node to delete: ";
	cin>>num;
	d.delete_node_num(num);
	d.display();
}
