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

// Covert array into in form of linked list
node *create_ll(int arr[], int n) {
	// first create the first node
	node *head = new node(arr[0]);

	// last node which always point to last node
	// so whenever we have to add new node then
	// we can add at the last
	node *last_node =  head;

	for (int i = 1; i < n; i++) {
		last_node->next = new node(arr[i]);
		last_node = last_node->next;
	}
	return head;
}

void printNode(node *head) {
	// travers in entire linked list
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

bool isSorted(node *head) {
	int x = INT_MIN;

	while (head != NULL) {
		if (head->data < x) {
			// we are checking for asseconding order
			// next element is less then the current element then
			// it means it is not sorted
			return false;
		}
		// if next data is greater then the curr data then
		// traverse in the linked list
		x = head->data;
		head = head->next;
	}
	return true;
}
int main() {
	int arr[] = {1, 1, 2, 2, 4, 4, 5};
	int n = 7;

	node *head = create_ll(arr, n);

	printNode(head);
	if (isSorted(head)) {
		cout << "Linked List Sorted !" << endl;
	}
	else {
		cout << "Linked List not Sorted !" << endl;
	}

	return 0;
}

/*
Output:-
-------
Case - 1
========
1 -> 1 -> 2 -> 10 -> 4 -> 4 -> 5 ->
Linked List not Sorted !

Case - 2
========
1 -> 1 -> 2 -> 2 -> 4 -> 4 -> 5 ->
Linked List Sorted !
*/