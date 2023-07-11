#include <iostream>
using namespace std;

class Node
{
	public: 
		int data;
		Node* next;
		
		Node () 
		{
			data = 0;
			next = NULL;
		}
		Node (int d, Node* n)
		{
			data = d;
			next = n;
		}
};

class SinglyLinkedList{
	Node* head;
//	Node* tail;
//	int size;
	public:
		// Default constructor
	    SinglyLinkedList() { head = NULL; }
	  
	    // Function to print the linked list.
	    void printList(){
	    	Node* temp = head;
		    while (temp != NULL) {
		        cout << temp->data << " ";
		        temp = temp->next;
		    }
		    cout << "\n";
		}
	  
	  	// Insert at the front
	  	void push_front(int data){
	  		// make new node and set its data
	  		Node* new_node = new Node(data, NULL);
	  		
	  		// assign head as next of new node
	  		new_node->next = head;
	  		
	  		// make new node head
	  		head = new_node;
		}
		
		// Insert after a given node
		void insertAfter(Node* prev_node, int data) {
			// Return if given prev_node is NULL
		    if (prev_node == NULL) 
		    { 
		        cout << "the given previous node cannot be NULL"; 
		        return; 
		    }
			// make new node and set its data
	  		Node* new_node = new Node(data, NULL);
	  		
	  		// assign next node as next of new node
	  		new_node->next = prev_node->next;
	  		
	  		// assign next of given node as new node
	  		prev_node->next = new_node;
		}
		
		// Insert at the end
		void push_back(int data){
			
			// make new node and set its data and set its next as NULL
	  		Node* new_node = new Node(data, NULL);
	  		
	  		// If the Linked List is empty,
		    // then make the new node as head
		    if (head == NULL)
		    { 
		        head = new_node; 
		        return; 
		    }
	  		
	  		// make a temporary node to iterate through the LL
	  		Node* last = head;
	  		
	  		// traverse to the last node
	  		while(last->next != NULL){
	  			last = last->next;
			}
	  		
	  		// append new node to next of previous last node
	  		last->next = new_node;
		}	// O(n). And O(1) if using tail.
		
		// Insert before a given node???
		
		// Delete from head
		void deleteFromHead(){
			if (head == NULL){
				cout << "List is empty.";
				return;
			}
			
			// use temp to point to head node
			Node* temp = head;
			
			// make next of head as head
			head = head->next;
			
			// use temp to delete/free head node
			delete temp;
		}
		
		// delete node with a value (first occurence)
		void deleteNode(int val){
			if (head == NULL){
				cout << "Node with the value does not exist.";
				return;
			}
			
			Node* temp = head;
			Node* prev = NULL;
			
			// If head node itself to be deleted
			if (temp->data == val){
				head = temp->next;
				delete temp;
				return;
			}
			
			// Search for the value to be deleted
			while(temp->data != val){
				prev = temp;
				temp = temp->next;
				// If value not found, return
				if (temp == NULL)
					return;
			}
			
			// Unlink the node from linked list
			prev->next = temp->next;
			
			delete temp;
		}
		
		// Delete from tail
		void deleteFromTail(){
			if (head == NULL){
				cout << "Node with the value does not exist.";
				return;
			}
			
			Node* temp = head;
			
			// Only one node
			if (temp->next == NULL){
				head = NULL;
				delete temp;
				return;
			}
			
			while(temp->next->next!= NULL){
				temp = temp->next;
			}
			
			Node* last = temp->next;
			temp->next = NULL;
			delete last;
		}
		
		// Delete List
		deleteList(){
			if (head != NULL){
				Node *temp;		
				Node *curr = head; // to iterate
				
				while(curr != NULL){
					temp = curr; // hold curr to delete later on
					curr = curr->next;
					delete temp;
				}
			}
		}
		
		// Copy constructor
		SinglyLinkedList(const SinglyLinkedList& obj){
			head = NULL;
			Node *temp_node = obj.head;	// to iterate through obj's list
			Node *last_node, *n;
			
			while(temp_node!=NULL){
				n = new Node(temp_node->data, NULL);
				
				if (head == NULL){
					head = n;
				}
				else{
					last_node->next = n;
				}
				last_node = n;
				temp_node = temp_node->next;
			}
		}
		
		// Assignment operator
		SinglyLinkedList& operator=(const SinglyLinkedList& obj){
			if (this != &obj){
				deleteList();
				Node *temp_node = obj.head;	// to iterate through obj's list
				Node *last_node, *n;
				
				while(temp_node!=NULL){
					n = new Node(temp_node->data, NULL);
					
					if (head == NULL){
						head = n;
					}
					else{
						last_node->next = n;
					}
					last_node = n;
					temp_node = temp_node->next;
				}
			}
			return *this;
		}
		
		// Destructor
		~SinglyLinkedList(){
			deleteList();
		}
		
		// Search value in list - can also return node
		bool isInList(int val){
			Node* temp = head;
			while(temp != NULL){
				if (temp->data == val){
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
		
		// reverse Linked List
		void reverseList() {
		    Node* current = head;
		    Node* next = NULL;
		    Node* prev = NULL;
		    while (current != NULL) {
		    	// keep head pointing to current
		    	head = current;
		    	
		    	// save next before reversing link 
				// otherwise next node can be accessed
		    	next = current->next;
		    	
		    	// reverse link
		    	current->next = prev;
		    	
		    	// move previous and current to their respective next nodes
		    	prev = current;
		    	current = next;		        
		    }
		}
};

int main(){
	SinglyLinkedList sll;
	cout << "\nPush front 2 4 6\n";
	sll.push_front(2);
	sll.push_front(4);
	sll.push_front(6);
	sll.printList();
	
	cout << "\nPush back 8 10 12\n";
	sll.push_back(8);
	sll.push_back(10);
	sll.push_back(12);
	sll.printList();
	
	cout << "\nDelete 10\n";
	sll.deleteNode(11);
	sll.printList();
	
	cout << "\nDelete from head\n";
	sll.deleteFromHead();
	sll.printList();
	
	cout << "\nDelete from tail\n";
	sll.deleteFromTail();
	sll.printList();
	
	cout << "\nFind 2 in list\n";
	cout << sll.isInList(2);
	
	cout << "\nreverseList\n";
	sll.reverseList();
	sll.printList();
	
	cout << "\nCopy constructor\n";
	SinglyLinkedList sll2(sll);
	sll2.printList();
}


