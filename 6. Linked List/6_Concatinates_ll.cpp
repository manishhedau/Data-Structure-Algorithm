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

int length(node *head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

// normal
node* concatinate_ll(node *head1, node *head2) {
	// check which linked list contain smaller value
	if (head1->data < head2->data) {
		node *temp = head1;
		// Iterate over the linked list upto last node
		while (temp->next != NULL) {
			temp = temp->next;
		}
		// connect last node->next with second linked list
		temp->next = head2;
		return head1;
	}
	else {
		node *temp = head2;
		// Iterate over the linked list upto last node
		while (temp->next != NULL) {
			temp = temp->next;
		}
		// connect last node->next with second linked list
		temp->next = head1;
		return head2;
	}
}

int main() {
	node *head1 = NULL, *head2 = NULL, *head3 = NULL;

	take_input(head1);
	take_input(head2);
	take_input(head3);

	printNode(head1);
	printNode(head2);
	printNode(head3);

	cout << "Concating Two sorted Linked List : " << endl;
	// Concatinate two sorted linked List
	node *two = concatinate_ll(head1, head2);
	printNode(two);
	// Concatinate Three Sorted Linked List
	node *three = concatinate_ll(two, head3);
	printNode(three);
	return 0;
}

/*
Input :-
----------
5 4 3 2 1 -1
 10 9 8 7 6 -1
 15 14 13 12 11 -1

Output :-
--------

1 -> 2 -> 3 -> 4 -> 5 ->
6 -> 7 -> 8 -> 9 -> 10 ->
11 -> 12 -> 13 -> 14 -> 15 ->
Concatinate Two sorted Linked List :
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 14 -> 15 ->

*/