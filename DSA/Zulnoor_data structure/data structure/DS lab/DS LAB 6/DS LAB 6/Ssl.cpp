#include <iostream>
using namespace std;


#include "Ssl.h"
#include "Node.h"

Ssl::Ssl(){
	
}

Ssl::Ssl(int s){
	size = s;
}

void Ssl::Insert_at_Head(int d){
	Node *n = new Node();
	if(head==0){
		head = n;
	}
	else{
		n->next = head;
		head = n;
	}
		n->data = d;
		size++;
	cout<< "Node Added at Top: "<<n->data<<endl;
}

void Ssl::Insert_at_End(int d){
	Node *n = new Node(),*currentNode;
	
	if(head==0){
		head = n;
	}
	else{
		currentNode = head;
		while(currentNode->next!=0){
			currentNode = currentNode->next;
		}
		currentNode->next = n;
	}
		n->data = d;
		size++;
	cout<< "Node Added at End: "<<n->data<<endl;
}

void Ssl::Insert_Before(int toPut,int whereToPut){
	Node *n = new Node(),*currentNode;

	while(currentNode->next->data!=toPut||currentNode->next!=0){
		
		
	}
}


void Ssl::Insert_at(int d, int indx){
	Node *n = new Node(),*currentNode;

	if(indx<size){
		for(int i=0;i<indx;i++){
			currentNode = currentNode->next;
		}
		n = currentNode;
		currentNode->next = n;
		n->data = d;
		cout<< "Node Added at: "<<indx<<" before : "<< n->next->data<<endl;
	}
	else{
		cout<< "Invalid input"<<endl;
		return ;
	}
}
