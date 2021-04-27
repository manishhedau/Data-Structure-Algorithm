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


node * search_ll(node *head, int key) {
	node *temp = NULL;

	while (head != NULL) {
		if (head->data == key) {
			temp = head;
			return temp;
		}

		head = head->next;
	}
	return temp;
}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	int key = 10;
	node *search = search_ll(head, key);
	if (search != NULL) {
		cout << "Search key '" << search->data << "' is found in Linked List " << endl;
	}
	else {
		cout << "Search key '" << key << "' is not found in Linked List" << endl;
	}
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Search key '3' is found in Linked List

1 -> 2 -> 3 -> 4 -> 5 ->
Search key '10' is not found in Linked List
*/