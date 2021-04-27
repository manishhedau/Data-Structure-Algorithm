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

void joinedTwo_LL(node *&head1, node*&head2) {
	// check both the linked list empty
	if (head1 == NULL and head2 == NULL)
		return;

	// if ll1 is empty then ll1 head point to ll2 head
	if (head1 == NULL) {
		head1 = head2;
		return;
	}

	// if ll2 is empty then we don't need to do anything so just return
	if (head2 == NULL) {
		return;
	}

	// iterate over the one linked list
	node *curr1 = head1;
	// iterate over the first linked list upto last node
	while (curr1->next != NULL) {
		curr1 = curr1->next;
	}
	// connect ll1 last node to ll2 first node
	curr1->next = head2;
}

int main() {
	int arr1[10] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head1 = create_ll(arr1, n);
	printNode(head1);
	int arr2[10] = {6, 7, 8, 9, 10};
	node *head2 = create_ll(arr2, n);
	printNode(head2);

	joinedTwo_LL(head1, head2);
	printNode(head1);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
6 -> 7 -> 8 -> 9 -> 10 ->
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->

*/