// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


class node {
public:
	int data;
	node *next;

	// constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

void printNode(node *head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void insertAtHead(node *&head, int data) {
	// if ll is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}

	// if ll is not empty
	node *new_bucket = new node(data);
	new_bucket->next = head;
	head = new_bucket;
}

void take_input(node *&head) {
	int n;
	cin >> n;

	while (n != -1) {
		insertAtHead(head, n);
		cin >> n;
	}
}
// Time Complexity - O(N^2)
node *reverse_ll_recursive(node *head) {
	// base case
	if (head == NULL or head->next == NULL) {
		return head;
	}

	// recursive call upto the last node
	// recusive case
	node * shead = reverse_ll_recursive(head->next);

	// self work
	// then we iterate upto last node of small linked list
	node *temp = shead;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	// and we break connection of head linked list
	// 1->2->3<-4<-5<-Shead(small linked list)
	// head = 2 node
	// temp = 3 node
	// so we break head node connection
	head->next = NULL;
	// and temp->next will point to head
	// 1->2<-3<-4<-5<-Shead
	temp->next = head;
	return shead;
}


// Time complexity - O(N) +
node *reverse_ll_recursive2(node *head) {
	// base case
	if (head == NULL or head->next == NULL) {
		return head;
	}

	// recusive case
	node * shead = reverse_ll_recursive2(head->next);

	// here we are just removing the looping part
	// Because head->next is pointing to last node of small linked list
	// self work
	// storing last node at temp
	node *temp = head->next;
	// last node ->next will point to head
	temp->next = head;
	// and head->next point to null to break connection of previous node of head.
	head->next = NULL;
	return shead;
}

// first store the head of reverse linked list
node *first = NULL;
void reverse_ll_recursive3(node *prev, node *next) {
	if (next != NULL) {
		reverse_ll_recursive3(next, next->next);
		// next->next will point to it's previous node
		next->next = prev;
	}
	else {
		// last condition when if condition will not true
		// first will point to last node address of linked list
		first = prev;
	}
}

int main() {
	node *head = NULL;
	take_input(head);

	printNode(head);
	cout << "Reverse a Linked List : " << endl;
	// head = reverse_ll_recursive(head);

	head = reverse_ll_recursive2(head);
	printNode(head);

	reverse_ll_recursive2(NULL, head)
	head = first;
	printNode(head);
	return 0;
}

/*
Input :-
----------
5 4 3 2 1 -1

Output :-
--------
1 -> 2 -> 3 -> 4 -> 5 ->
Reverse a Linked List :
5 -> 4 -> 3 -> 2 -> 1 ->

*/