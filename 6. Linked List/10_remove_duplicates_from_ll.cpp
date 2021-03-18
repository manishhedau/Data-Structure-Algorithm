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


// Time complexity - O(N)
// Space Complexity - O(1)
void remove_duplicates_from_ll(node*&head) {
	// take two pointer
	// 1. first pointer point to first node means prev node
	// 2. Second pointer point to second node means next node of prev

	node *first = head;
	node *second = head->next;

	while (second != NULL) {
		// same value then delete second
		if (first->data == second->data) {
			first->next = second->next;
			delete second;
			second = first->next;
		} else {
			// not same then point to next nodes
			first = second;
			second = second->next;
		}
	}
}
int main() {
	int arr[] = {1, 1, 2, 3, 4, 4, 5};
	int n = 7;

	node *head = create_ll(arr, n);

	printNode(head);

	remove_duplicates_from_ll(head);
	cout << "remove duplicate linked list  : " << endl;
	printNode(head);
	return 0;
}

/*
Output:-
-------
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 ->
remove duplicate linked list  :
1 -> 2 -> 3 -> 4 -> 5 ->

*/