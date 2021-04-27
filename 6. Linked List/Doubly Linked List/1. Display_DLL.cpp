// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *prev;
	node *next;

	node(int d) {
		data = d;
		prev = NULL;
		next = NULL;
	}
};

// Tail pointer in Linked List
// And tail pointer point to last node of the linked list
// Just like head pointer point to first node of the linked list
node *tail = NULL;
void insertAtHead(node *&head, int data) {
	// check linked list is empty
	if (head == NULL) {
		// if ll is empty then next = NULL, prev = NULL
		head = new node(data);
		// after creating new node
		// data = d, next = NULL, prev = NULL
		tail = head;
		return;
	}

	// creating new bucket for new node
	node *new_bucket = new node(data);
	// first head->prev point to new bucket
	head->prev = new_bucket;

	// then new_bucket->next point to head to become first node of ll
	new_bucket->next = head;
	// then assign new bucket address to head
	head = new_bucket;

}

// creating the doubly linked list
node *create_ll()
{
	int data;
	cin >> data;

	node *head = NULL;

	while (data != -1) {
		insertAtHead(head, data);
		cin >> data;
	}
	return head;
}

// printing the doubly linked list in reverse order
// by using tail pointer
// means backward direction
void printInReverse() {
	// printing Linked list in reverse order
	node *temp = tail;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->prev;
	}
	cout << endl;
}

// printing the doubly linked list in forward direction
// by using head pointer
void printNode(node *head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty !" << endl;
		return ;
	}

	while (head != NULL) {
		cout << head->data << " -> ";
		head  = head->next;
	}
	cout << endl;
}


int main() {

	node *head = create_ll();
	cout << "Printing DLL in Forward direction : " << endl;
	printNode(head);
	cout << "Printing DLL in Backward direction : " << endl;
	printInReverse();
	return 0;
}

/*
Input :-
5 4 3 2 1 -1

Output :-
Printing DLL in Forward direction :
1 -> 2 -> 3 -> 4 -> 5 ->
Printing DLL in Backward direction :
5 -> 4 -> 3 -> 2 -> 1 ->

*/