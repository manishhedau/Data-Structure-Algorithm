// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;
// Two Linked Lists are identical when they have same data and with same arrangement too.

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
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

bool isIdentical(node *head1, node *head2) {

	while (head1 != NULL and head2 != NULL) {
		if (head1->data != head2->data) {
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return true;
}

int main() {
	int arr1[5] = { 1, 2, 3, 4, 5};
	int n = 5;
	node *head1 = create_ll(arr1, n);
	printNode(head1);
	int arr2[5] = { 10, 20, 30, 40, 50};
	node *head2 = create_ll(arr2, n);
	printNode(head2);

	if (isIdentical(head1, head2)) {
		cout << "Identical" << endl;
	}
	else {
		cout << "Not Identical" << endl;
	}
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
1 -> 2 -> 3 -> 4 -> 5 ->
Identical

1 -> 2 -> 3 -> 4 -> 5 ->
10 -> 20 -> 30 -> 40 -> 50 ->
Not Identical
*/