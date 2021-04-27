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


int sum_of_ll(node *head) {
	int sum = 0;
	while (head != NULL) {
		sum = head->data + sum ;
		head = head->next;
	}
	return sum;
}

int main() {
	int arr[5] = {1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Sum of linked list : " << sum_of_ll(head) << endl;
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Sum of linked list : 15
*/