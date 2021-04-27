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

void insertAtTail(node *&head, int data) {
	// check linked list is empty or not
	if (head == NULL) {
		head = new node(data);
		tail = head;
		return;
	}

	// linked list is not empty then,
	node *new_bucket = new node(data);
	tail->next = new_bucket;
	new_bucket->prev = tail;
	tail = new_bucket;
}

void insetAtPos(node *&head, int data, int pos) {
	// check linked list is empty or not
	if (head == NULL) {
		head = new node(data);
		tail = head;
		return;
	}
	// when linked list is not empty then,

	node *temp = head;
	int cnt = 1;
	while (cnt < pos - 1) {
		temp = temp->next;
		cnt++;
	}

	node *new_bucket = new node(data);
	new_bucket->next = temp->next;
	temp->next->prev = new_bucket;
	new_bucket->prev = temp;
	temp->next = new_bucket;
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

int main() {

	node *head = create_ll();
	cout << "Printing DLL in Forward direction : " << endl;
	printNode(head);

	int data;
	cin >> data;
	insertAtTail(head, data);
	cin >> data;
	insertAtTail(head, data);
	cin >> data;
	insertAtTail(head, data);

	cout << "After Inserting element At tail in Linked List :" << endl;
	printNode(head);

	int pos;
	cin >> pos;
	cout << "Enter position :" << pos << endl;

	cin >> data;
	cout << "Enter data : " << data << endl;;

	cout << "After inserting at given pos linked list is : " << endl;
	insetAtPos(head, data, pos);
	printNode(head);
	cout << "Printing in Backward direction :" << endl;
	printInReverse();
	return 0;
}

/*
Input :-
----------
5 4 3 2 1 -1
6 7 8 -> insetting at tail data

3  -> pos
9  -> data

Output :-
--------
Printing DLL in Forward direction :
1 -> 2 -> 3 -> 4 -> 5 ->
After Inserting element At tail in Linked List :
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 ->
Enter position :3
Enter data : 9
After inserting at given pos linked list is :
1 -> 2 -> 9 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 ->
Printing in Backward direction :
8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 9 -> 2 -> 1 ->

*/