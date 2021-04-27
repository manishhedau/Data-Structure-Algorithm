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
	// check ll is empty
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

node *NthNode_from_End(node *head, int N) {
	// Using runner technique we can solve this problem
	// or two pointer approach
	node *fast = head;
	node *slow = head;
	int cnt = 0;
	while (fast != NULL) {
		if (cnt < N) {
			cnt++;
			fast = fast->next;
		}
		else {
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}
int main() {
	int arr[10] = { 1, 2, 3, 4, 5};
	int n = 5;
	node *head = create_ll(arr, n);
	printNode(head);
	cout << "Nth node from the end of Linked List : " << endl;
	node *Nth = NthNode_from_End(head, 3);
	cout << "Nth node value : " << Nth->data << endl;
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Nth node from the end of Linked List :
Nth node value : 3
*/