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

	// recusive case
	node * shead = reverse_ll_recursive(head->next);

	// self work
	node *temp = shead;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	head->next = NULL;
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

	// self work
	node *temp = head->next;
	temp->next = head;
	head->next = NULL;
	return shead;
}


int main() {
	node *head = NULL;
	take_input(head);

	printNode(head);
	cout << "Reverse a Linked List : " << endl;
	// head = reverse_ll_recursive(head);

	head = reverse_ll_recursive2(head);
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