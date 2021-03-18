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

// reverse the linked list in my ways
// This is my way of writing code for this problem
// Be always have to move next element to head or begin
// to make a reverse linked list
void insertAtHead(node *&head, node*Node) {
	if (head == NULL) {
		head = Node;
		head->next = NULL;
		return;
	}
	Node->next = head;
	head = Node;
}

node *reverse_ll(node*head) {
	node *temp = NULL;

	// Traverse in entire linked list
	while (head != NULL) {
		node *p = head->next;
		// just add curr to front of temp
		insertAtHead(temp, head);
		head = p;
	}
	return temp;
}
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);

	printNode(head);

	head = reverse_ll(head);
	printNode(head);
	return 0;
}

/*
Output:-
-------
1 -> 1 -> 2 -> 2 -> 4 -> 4 -> 5 ->
5 -> 4 -> 4 -> 2 -> 2 -> 1 -> 1 ->

Another Exmaple
1 -> 2 -> 3 -> 4 -> 5 ->
5 -> 4 -> 3 -> 2 -> 1 ->

*/