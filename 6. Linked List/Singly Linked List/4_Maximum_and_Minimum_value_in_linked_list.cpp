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
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}


void max_min(node *head) {
	int max = head->data;
	int min = head->data;
	head = head->next;
	while (head != NULL) {
		if (max < head->data) {
			max = head->data;
		}

		if (min > head->data) {
			min = head->data;
		}

		head = head->next;
	}

	cout << "Maximum in Linked List : " << max << endl;
	cout << "Minimum in Linked List : " << min << endl;
}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	max_min(head);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Maximum in Linked List : 5
Minimum in Linked List : 1

*/