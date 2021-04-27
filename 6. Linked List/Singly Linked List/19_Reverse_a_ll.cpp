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


// converting an array into an linked list
node *create_ll(int *arr, int n) {
	// head pointer
	node *head = new node(arr[0]);

	// temp pointer which always point to next node
	node *last_node = head;
	for (int i = 1; i < n; i++) {
		last_node->next = new node(arr[i]);
		last_node = last_node->next;
	}
	return head;
}

// Printing the nodes value
// By travesing in entire linked list
void printNode(node *head) {
	// check ll is empty
	if (head == NULL) {
		cout << "Linked List is empty " << endl;
		return;
	}
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

// function for reversing a linked list
void revese_ll(node *&head) {
	// using three pointer technique
	node *prev, *curr, *next;
	prev = curr = NULL;
	next = head;
	while (next != NULL) {
		prev = curr;
		curr = next;

		next = next->next;
		curr->next = prev;
	}
	head = curr;
}
int main() {
	int arr[10] = { 1, 2, 3, 4, 5};
	int n = 5;
	node *head = create_ll(arr, n);
	printNode(head);
	cout << "Reverse a Linked List : " << endl;
	revese_ll(head);
	printNode(head);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Reverse a Linked List :
5 -> 4 -> 3 -> 2 -> 1 ->
*/