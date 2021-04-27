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


void deleteFromHead(node *&head) {
	// check linked list is empty
	if (head == NULL) {
		return;
	}

	// store next node address in pointToNext variable
	node *pointToNext = head->next;
	// delete head node
	delete head;
	// head point to pointToNext which store next node address
	head = pointToNext;
}
int main() {
	int arr[5] = { 1};
	int n = 1;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Delete form head : " << endl;
	deleteFromHead(head);
	printNode(head);
	return 0;
}

/*
Output :-
---------
0 -> 1 -> 2 -> 4 -> 5 ->
Delete form head :
1 -> 2 -> 4 -> 5 ->


1 ->
Delete form head :
Linked List is empty

*/