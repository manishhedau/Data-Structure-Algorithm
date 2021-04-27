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

// Iterative Approach for merging
void mergeSorted_LL(node *&head1, node*&head2) {
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

	node *ll1 = head1;
	node *ll2 = head2;
	node *head = NULL;
	// connect first node to head
	if (ll1->data < ll2->data) {
		head = ll1;
		ll1 = ll1->next;
	}
	// creating an temp for maintaining head last node
	node *temp = head;
	// Iterating over the both linked list
	while (ll1 != NULL and ll2 != NULL) {
		// checking the condtion of ascending order
		if (ll1->data <= ll2->data) {
			temp->next = ll1;
			temp = temp->next;
			ll1 = ll1->next;
		}
		else {
			temp->next = ll2;
			temp = temp->next;
			ll2 = ll2->next;
		}
	}

	// if some node are left in ll1 then connect them with temp
	while (ll1 != NULL) {
		temp->next = ll1;
		ll1 = ll1->next;
	}
	// if some node are left in ll2 then connect them with temp
	while (ll2 != NULL) {
		temp->next = ll2;
		ll2 = ll2->next;
	}

	printNode(head);

}

// Recusive Approach for merging
node *mergeSortedLL_recursive(node *head1, node *head2) {
	// base case
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	// Self work
	node *head = NULL;
	if (head1->data <= head2->data) {
		head = head1;
		head->next = mergeSortedLL_recursive(head1->next, head2);
	}
	else {
		head = head2;
		head->next = mergeSortedLL_recursive(head1, head2->next);
	}
	return head;
}
int main() {
	int arr1[10] = { 1, 3, 5, 7, 9};
	int n = 5;

	node *head1 = create_ll(arr1, n);
	printNode(head1);
	int arr2[10] = {2, 4, 6, 8, 10};
	node *head2 = create_ll(arr2, n);
	printNode(head2);
	cout << "Merging Two Sorted Linked List : " << endl;
	node *head = mergeSortedLL_recursive(head1, head2);
	printNode(head);
	return 0;
}

/*
Output :-
---------
Iterative Solution -
=====================
1 -> 3 -> 5 -> 7 -> 9 ->
2 -> 4 -> 6 -> 8 -> 10 ->
Merging Two Sorted Linked List :
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->

Recusive Solution -
===================
1 -> 3 -> 5 -> 7 -> 9 ->
2 -> 4 -> 6 -> 8 -> 10 ->
Merging Two Sorted Linked List :
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->
*/