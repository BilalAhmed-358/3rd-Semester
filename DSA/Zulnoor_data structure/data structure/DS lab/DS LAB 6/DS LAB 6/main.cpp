#include<iostream>
#include "Ssl.h"
#include "Node.h"

using namespace std;
int main(int argc, char *argv[]){
	Ssl stinglyList(0);
	stinglyList.Insert_at_Head(5);
	stinglyList.Insert_at_Head(6);
	stinglyList.Insert_at_End(10);
	stinglyList.Insert_at_End(1);
	stinglyList.Insert_at(4,1);
	
	return 0;
}
