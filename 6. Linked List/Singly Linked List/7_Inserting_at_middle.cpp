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

node *midPoint(node*head) {
	node *slow = head;
	node *fast = head->next;
	// if we want to insert at middle position then uncomment this line and return temp insteed of slow
	//node *temp = NULL;
	while (fast != NULL and fast->next != NULL) {
		// temp = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


void insertAtMiddle(node *&head, int data) {
	// for inserting at middle we need middle point
	node *curr = head;
	node *mid = midPoint(head);
	while (curr != NULL) {

		if (curr == mid->next) {
			node *new_bucket = new node(data);
			new_bucket->next = mid->next;
			mid->next = new_bucket;
			break;
		}
		curr = curr->next;
	}
}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Inserting at the middle : " << endl;
	insertAtMiddle(head, 10);
	printNode(head);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Inserting at the middle :
1 -> 2 -> 3 -> 10 -> 4 -> 5 ->
*/