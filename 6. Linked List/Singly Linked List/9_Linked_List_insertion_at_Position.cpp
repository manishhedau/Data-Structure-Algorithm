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


int length(node *head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}
void insertAtPosition(node *&head, int data, int pos) {
	// check one condition when linked list is empty
	node *new_bucket = new node(data);
	if (head == NULL) {
		head = new_bucket;
		return;
	}


	// check if user want to insert at head measn 1 or 0
	if (pos == 1) {

		new_bucket->next = head;
		head = new_bucket;
		return;
	}

	node *curr = head;
	// user want to insert in tail
	if (pos > length(head)) {
		while (curr->next != NULL) {
			curr = curr->next;
		}

		curr->next = new_bucket;
		return;
	}
	else {
		// when user want to insert data inside the linked list len
		int cnt = 1;
		while (cnt < pos - 1) {
			cnt++;
			curr = curr->next;
		}
		new_bucket->next = curr->next;
		curr->next = new_bucket;
	}
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Inserting an element at given Position : " << endl;
	insertAtPosition(head, 10, 10);
	printNode(head);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Inserting an element at given Position :
1 -> 2 -> 3 -> 4 -> 5 -> 10 ->

*/