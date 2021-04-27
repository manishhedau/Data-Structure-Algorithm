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

// Printing linked list in backward direction
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

// 1. Approach -
// Iterate from the backward and add all the node in forward direction
// while adding node maintain next and prev pointer
// Here tail is tracking curr node which we need to insert at last node of new linked list
// curr is tracking the last node to add tail node

void reverseDLL(node*&head) {
	node *templl = NULL;
	node *curr = NULL;
	while (tail != NULL) {
		// to store previous node
		node *prevNode = tail->prev;
		// for first element
		if (templl == NULL) {
			templl = tail;
			curr = templl;
			templl->next = NULL;
			templl->prev = NULL;
			// printNode(templl);
		}
		else {
			// for all remaining elements
			curr->next = tail;
			tail->prev = curr;
			curr = tail;
			curr->next = NULL;
			// printNode(templl);
		}
		tail = prevNode;
		// printNode(templl);
	}

	// assign new linked list head to original head pointer
	head = templl;
	// assign last node(curr node) to tail pointer
	tail = curr;
}

void insertAtHeadUsingTwoPointer(node *&head, node *curr) {
	// check linked list is empty
	// for first element
	if (head == NULL) {
		head = curr;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		return;
	}

	// for remaining all elements
	curr->next = head;
	head->prev = curr;
	head = curr;
	head->prev = NULL;
}

// 2. Approach -
// Iterate in forward direction
// and add all the node at head position
// using insertAtHeadUsingTwoPointer() function
node *reverseDLL2(node *head) {
	node *temp = NULL;
	while (head != NULL) {
		node *nextNode = head->next;
		insertAtHeadUsingTwoPointer(temp, head);
		head = nextNode;
	}
	return temp;
}


int main() {

	node *head = create_ll();
	cout << "Printing DLL in Forward direction : " << endl;
	printNode(head);

	cout << "Printing DLL in Backward direction : " << endl;
	printInReverse();

	cout << "Reversed Linked List : " << endl;
	reverseDLL(head);
	printNode(head);
	printInReverse();
	// head = reverseDLL2(head);
	// printNode(head);
	// printInReverse();


	return 0;
}


/*
Input :-
----------
1 2 3 4 5 -1

Output :-
---------

Printing DLL in Forward direction :
5 -> 4 -> 3 -> 2 -> 1 ->
Printing DLL in Backward direction :
1 -> 2 -> 3 -> 4 -> 5 ->
Reversed Linked List :
1 -> 2 -> 3 -> 4 -> 5 ->
5 -> 4 -> 3 -> 2 -> 1 ->

*/