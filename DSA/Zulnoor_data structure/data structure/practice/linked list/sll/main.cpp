#include<iostream>
#include "sll.h"
#include "node.h"
using namespace std;
int main()
{
sll L1;
L1.input_at_start(5);
L1.input_at_start(4);
L1.input_after(3,2);
L1.input_at_end(1);
L1.input_at_end(4);
L1.input_before(3,2);
L1.input_at_end(2);
L1.input_at_end(5);
L1.display();
//L1.delete_position(1);
//L1.delete_end();
//L1.deleteList();

 cout<<endl<<"Reversed List."<<endl;
 L1.reverse();
 L1.display();

//cout<<endl<<"Swapping two Adjacent nodes."<<endl;
//node *n = new node();
//n->data = 12;
//L1.swapnode(n);
//L1.display();

 cout<<endl<<"Sorted List."<<endl;
 L1.sort();
 L1.display();


cout<<endl<<"Deleting Duplicates."<<endl;
L1.dup();
L1.display();

return 0;
}
