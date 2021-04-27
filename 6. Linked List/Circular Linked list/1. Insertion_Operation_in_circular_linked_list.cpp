// Code By - Manish Hedau
// Circular linked list
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int data) {
		this->data = data;
		next = NULL;
	}
};

// Tail pointer maintain the last node of the linked list
node *tail = NULL;
// insertAtHead function is used to insert data at head of the linked list
void insertAtHead(node *&head, int data) {
	// when linked list is empty
	if (head == NULL) {
		head = new node(data);
		tail = head;
		tail->next = head;

		return;
	}

	// when linked list has one or more nodes
	node *newBucket = new node(data);
	newBucket->next = head;
	head = newBucket;
	tail->next = head;
}

// this function is used to create linked list
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

// function is used to get length of linked list
int length(node *head) {

	int len = 0;
	while (head) {
		len++;
		if (head->next == tail->next) {
			break;
		}
		head = head->next;
	}
	return len;
}

// Inserting at tail of linked list
void insertAtTail(node *&head, int data) {
	// check linked list is empty or not
	// we have to insert At head because
	// there is no node present in linked list
	if (head == NULL) {
		insertAtHead(head, data);
		return;
	}

	// when linked list is not empty then

	// creating new node
	tail->next = new node(data);
	// tail will point to new tail
	tail = tail->next;
	// and new tail->next point to head;
	tail->next = head;

}

// Inserting data at given position by the user
void insertAtPos(node *&head, int pos, int data ) {
	// check linked list is empty or not
	// if linked list is empty and position != 1
	// then return invalid position
	if (head == NULL and pos == 1) {
		insertAtHead(head, data);
		return;
	}

	// when we inserting at last-1 node position
	if (pos == length(head)) {
		// iterate over the linked list upto last-1 node
		node *tempHead = head;
		while (tempHead) {
			if (tempHead->next == tail) {
				break;
			}
			tempHead = tempHead->next;
		}

		tempHead->next = new node(data);
		tempHead->next->next = tail;

		// we can replace below commented lines with above two line for same task
		// node *newBucket = new node(data);
		// tempHead->next = newBucket;
		// newBucket->next = tail
		return;
	}

	// when user wanted to insert at tail position
	if (pos > length(head)) {
		insertAtTail(head, data);
		return;
	}

	// inserting at the middle of the linked list
	node *tempHead = head;
	int cnt = 1;
	while (cnt < pos - 1) {
		cnt++;
		tempHead = tempHead->next;
	}

	// storing the address of nextNode
	node *nextNode = tempHead->next;
	// creating new node bucket
	node *newBucket = new node(data);
	// tempHead->next point to newBucket
	tempHead->next = newBucket;
	// and newBucket->next point to nextNode
	newBucket->next = nextNode;
}
// this function is used to printing
// circular linked list in forward direction(for singly linked list)
void printCicularLLNode(node *head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Circular Linked List is empty!" << endl;
		return;
	}

	while (head) {
		cout << head->data << " -> ";
		if (head->next == tail->next) {
			break;
		}
		head = head->next;
	}
	cout << endl;
}
int main() {

	node *head = create_ll();
	cout << "Printing Circular Linked List : " << endl;
	printCicularLLNode(head);

	cout << "Insert Data At Head : " << endl;
	insertAtHead(head, 300);
	insertAtHead(head, 200);
	insertAtHead(head, 100);
	printCicularLLNode(head);

	cout << "Insert Data At Tail : " << endl;
	insertAtTail(head, 6);
	insertAtTail(head, 7);
	insertAtTail(head, 8);
	printCicularLLNode(head);


	cout << "Lenght of CLL : " << length(head) << endl;
	cout << "Insert At given Position : " << endl;
	int pos = 5;
	int data = 10;
	insertAtPos(head, pos, data);
	printCicularLLNode(head);
	return 0;
}

/*
Input :-
---------
5 4 3 2 1 -1

Output :-
---------
Printing Circular Linked List :
1 -> 2 -> 3 -> 4 -> 5 ->
Insert Data At Head :
100 -> 200 -> 300 -> 1 -> 2 -> 3 -> 4 -> 5 ->
Insert Data At Tail :
100 -> 200 -> 300 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 ->
Lenght of CLL : 11
Insert At given Position :
100 -> 200 -> 300 -> 1 -> 10 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 ->

*/