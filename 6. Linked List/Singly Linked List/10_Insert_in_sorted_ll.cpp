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

// Approach -
/*
Algorithm-
----------
1. Check ll is empty then add new_bucket to head
2. check head->data>data then add new_bucket to head
3. node *curr = head, *prev maintain these variable
4. iterate over ll when codition curr->next!=NULL and curr->data<data
    a. prev = curr
    b. curr = curr->next;
5. check curr->data<data then add new_bucket to the end
6. new_bucket->next = prev->next;
7. prev->next = new_bucket
*/
void insertInSorted_ll(node *&head, int data) {
	// check ll is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}
	// check data is less than head->data
	if (data < head->data) {
		node *new_bucket = new node(data);
		new_bucket->next = head;
		head = new_bucket;
		return;
	}

	// now data can be inserted at middle or tail(end)
	node *curr = head, *prev;
	while (curr->next != NULL and curr->data < data) {
		prev = curr;
		curr = curr->next;
	}

	// if last_node->data < data then add data to end
	if (curr->data < data) {
		curr->next = new node(data);
		return;
	}
	// if when data to be insert in middle
	node *new_bucket = new node(data);
	new_bucket->next = prev->next;
	prev->next = new_bucket;
}
int main() {
	int arr[5] = { 10, 20, 40, 50};
	int n = 4;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Inserting an element in sorted Linked List : " << endl;
	insertInSorted_ll(head, 14);
	printNode(head);
	return 0;
}

/*
Output :-
---------
10 -> 20 -> 40 -> 50 ->
Inserting an element in sorted Linked List :
10 -> 14 -> 20 -> 40 -> 50 ->
*/