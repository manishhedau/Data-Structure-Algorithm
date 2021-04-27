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

void deleteFromHead(node*&head) {
	// check linked list is empty or not
	if (head == NULL) {
		return; // Because linked list is empty
	}

	// when linked list is only one node
	if (head->next == tail->next) {
		delete head;
		head = tail = NULL;
		return;
	}
	// when linked has more than one Node then
	// store the last node address
	node *nextNode = head->next;
	// deleting head/first node
	delete head;
	// assigning nextNode address to head node to make first node of linked list
	head = nextNode;
	// last->next will also point to new head of linked list
	tail->next = head;
}

void deleteFromTail(node *&head) {
	// check linked list is empty or not
	if (head == NULL) {
		return; // Because linked list is empty
	}

	// when linked list has only one node
	if (head->next == tail->next) {
		delete head;
		head = tail = NULL;
		return;
	}

	// When linked list has more than one Node then
	// Iterate upto head->next == tail
	node *tempHead = head;
	while (tempHead->next != tail) {
		tempHead = tempHead->next;
	}
	// delete last/tail node
	delete tail;
	// assiging new last node address to tail pointer
	tail = tempHead;
	// now new tail->next point to head/firstNode of linked list
	tail->next = head;
}

void deleteFromPos(node *&head, int pos) {
	// check list is empty or not
	if (head == NULL) {
		return;
	}

	// check user want to delete head node
	if (pos == 1) {
		deleteFromHead(head);
		return;
	}
	// check user want to delete last node
	if (pos == length(head)) {
		deleteFromTail(head);
		return;
	}

	// when user wants to delete node from middle
	node *curr = head;
	// to store prev node address
	node *prev = NULL;
	int cnt = 1;
	while (cnt < pos) {
		prev = curr;
		curr = curr->next;
		cnt++;
	}

	// to store nextNode address
	node *nextNode = curr->next;
	// delete curr node
	delete curr;
	// now prev->next will point to nextNode
	prev->next = nextNode;
}
int main() {

	node *head = create_ll();
	cout << "Printing Circular Linked List : " << endl;
	printCicularLLNode(head);

	cout << "Deleting From Head : " << endl;
	deleteFromHead(head);
	printCicularLLNode(head);

	cout << "Deleting From Tail : " << endl;
	deleteFromTail(head);
	printCicularLLNode(head);

	cout << "Deleting From Pos : " << endl;
	deleteFromPos(head, 2);
	cout << "From pos : 2" << endl;
	printCicularLLNode(head);
	return 0;
}

/*
Input :-
---------
7 6 5 4 3 2 1 -1

Output :-
---------
Printing Circular Linked List :
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 ->
Deleting From Head :
2 -> 3 -> 4 -> 5 -> 6 -> 7 ->
Deleting From Tail :
2 -> 3 -> 4 -> 5 -> 6 ->
Deleting From Pos :
From pos : 2
2 -> 4 -> 5 -> 6 ->


*/