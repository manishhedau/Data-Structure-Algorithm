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

void deleteFromTail(node *&head) {
	// check ll is empty
	if (head == NULL) {
		return;
	}
	// when linked list has one node
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	node *curr = head;
	// iterate over the ll upto last node
	while (curr->next->next != NULL) {
		curr = curr->next;
	}

	delete curr->next;
	curr->next = NULL;

}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Delete form tail : " << endl;
	deleteFromTail(head);
	printNode(head);
	return 0;
}

/*
Output :-
---------
1 ->
Delete form tail :
Linked List is empty

1 -> 2 ->
Delete form tail :
1 ->

1 -> 2 -> 3 -> 4 -> 5 ->
Delete form tail :
1 -> 2 -> 3 -> 4 ->
*/