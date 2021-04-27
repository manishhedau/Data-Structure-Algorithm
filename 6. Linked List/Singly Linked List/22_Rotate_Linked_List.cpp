// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};


node *tail = NULL;
void insertAtHead(node *&head, int data) {
	// check linked list is empty or not
	if (head == NULL) {
		head = new node(data);
		tail = head;
		return;
	}

	// when linked is not empty then
	node *newBucket = new node(data);
	newBucket->next = head;
	head = newBucket;
}
node *create_ll() {

	int data;
	cin >> data;

	node *head = NULL;
	while (data != -1) {
		insertAtHead(head, data);
		cin >> data;
	}
	return head;
}

int lengthOfLL(node *head) {
	// check linked is empty
	if (head == NULL) {
		// because linked list is empty
		return 0;
	}
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

void printNode(node *head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty !" << endl;
		return;
	}

	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

// for adding curr node to last node
// we use this function
void insertAtTail(node *curr) {
	// just add curr node with tail pointer
	tail->next = curr;
	curr->next = NULL;
	tail = curr;
}

// 1. Approach :-
// Basic Approach is like while creating linked list maintain tail pointer
// so that we will have to traverse through whole linked to find last node
// using loop upto k, we iterate over the linked list
// and at every iteration, we add current node to last node of linked list
// By using above insertAtTail function
// rotate linked list by k
void rotateLL(node *&head, int k) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked list is empty!" << endl;
		return;
	}

	// when linked list is not empty then rotate it by k element
	int cnt = 0;
	node *tempHead = head;
	while (cnt < k) {
		node *nextNode = tempHead->next;
		insertAtTail(tempHead);
		tempHead = nextNode;
		cnt++;
	}
	head = tempHead;
}
int main() {
	node *head = create_ll();
	cout << "Printing The Linked List : " << endl;
	printNode(head);

	cout << "Rotated Linked List : " << endl;
	rotateLL(head, 4);
	printNode(head);

	return 0;
}

/*

Input :-
----------
5 4 3 2 1 -1

Output :-
-----------
Printing The Linked List :
1 -> 2 -> 3 -> 4 -> 5 ->
Rotated Linked List :
5 -> 1 -> 2 -> 3 -> 4 ->

*/