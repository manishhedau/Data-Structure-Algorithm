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
bool isSorted(node *head) {
	// check ll is empty
	if (head == NULL) {
		return true;
	}

	node *prev = head;
	node *next = head->next;
	while (next != NULL) {
		// if prev->data > head->data then return true
		// because we are checking for ascending order
		// in ascending order prev->data is less than next->data
		if (prev->data > next->data) {
			return false;
		}
		prev = next;
		next = next->next;
	}
	return true;
}

bool isSorted_recusive(node *prev, node *next ) {
	// base case
	if (next == NULL) {
		return true;
	}
	// Self work
	if (prev->data > next->data) {
		return false;
	}
	else {
		// Recusive case
		return isSorted_recusive(next, next->next);
	}
}
int main() {
	int arr[10] = { 1, 2, 10, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	if (isSorted_recusive(head, head->next)) {
		cout << "Linked List is sorted" << endl;
	}
	else {
		cout << "Linked List is not sorted" << endl;
	}
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Linked List is sorted


1 -> 2 -> 10 -> 3 -> 4 -> 5 ->
Linked List is not sorted

*/