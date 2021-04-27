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

void printInReverse() {
	// printing Linked list in reverse order
	node *temp = tail;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->prev;
	}
	cout << endl;
}

// function is used for finding length of DLL
int lengthOfDLL(node *head) {
	int len = 0;
	while (head != NULL) {
		head = head->next;
		len++;
	}
	return len;
}

// All deletion operation
void deleteFromHead(node *&head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty!" << endl;
		return;
	}

	// check linked list has only one node
	// then if we delete that first node(means head node)
	// then tail will also point to NULL.
	if (head->next == NULL) {
		delete head;
		tail = head = NULL;
		return;
	}

	// if linked list has more than one node
	// we delete the node and head point to next node

	// nextNode is used to store the referance of nextNode
	node *nextNode = head->next;
	// assiging prev to NULL
	nextNode->prev = NULL;
	// delete head
	delete head;

	// assign nextNode to head(means head will point to next node)
	head = nextNode;
}

void deleteFromTail(node*&head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty!" << endl;
		return;
	}

	// check linked list has only one node
	// then if we delete that first node(means head node)
	// then tail will also point to NULL.
	if (head->next == NULL) {
		delete head;
		tail = head = NULL;
		return;
	}
	// if linked list has more than one node
	// we delete the tail node and tail point to ptev node

	// storing prev node address in prevNode pointer
	node *prevNode = tail->prev;
	//prevNode->next should point to NULL
	prevNode->next = NULL;

	// delete tail
	delete tail;

	// tail point to prevNode
	tail = prevNode;
}

void deleteFromPos(node *&head, int pos) {
	// // check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty!" << endl;
		return;
	}

	// check if user want to delete from head or not
	// means pos == 1 (if wanted to delete from head)
	if (pos == 1) {
		deleteFromHead(head);
		return;
	}
	// check if user want to delete form tail or not
	// means pos == length (if wanted to delete from tail)
	if (pos == lengthOfDLL(head)) {
		deleteFromTail(head);
		return;
	}

	// If wanted to delete form middle or any pos leaving (head, tail)
	int cnt = 1;
	node *temp = head;
	while (cnt < pos) {
		temp = temp->next;
		cnt++;
	}
	// storing the delete node address
	node *deleteNode = temp;

	// storing prevNode and nextNode address to pointing or connecting work
	node *prevNode = deleteNode->prev;
	node *nextNode = deleteNode->next;

	// connecting prevNode and nextNode together
	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	// delete deleteNode
	delete deleteNode;
}

int main() {
	node *head = create_ll();
	cout << "Printing DLL in Forward direction : " << endl;
	printNode(head);
	cout << "Deleting pos : " << endl;
	// deleteFromTail(head);
	deleteFromPos(head, 5);
	printNode(head);
	cout << "Printing DLL in Backward direction : " << endl;
	printInReverse();
	return 0;
}


/*
Input :-
----------
5 4 3 2 1 -1

Output :-
--------
Try by calling different-different Deletion function.

Printing DLL in Forward direction :
1 -> 2 -> 3 -> 4 -> 5 ->
Deleting pos :
1 -> 2 -> 3 -> 4 ->
Printing DLL in Backward direction :
4 -> 3 -> 2 -> 1 ->

*/