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
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void insertAtHead(node *&head, int data) {
	// check linked list empty or not
	// if true
	if (head == NULL) {
		head = new node(data);
		return;
	}

	// not empty
	node *new_bucket = new node(data);
	new_bucket->next = head;
	head = new_bucket;
}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Inserting some value in head : " << endl;
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	printNode(head);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Inserting some value in head :
10 -> 20 -> 30 -> 1 -> 2 -> 3 -> 4 -> 5 ->

*/