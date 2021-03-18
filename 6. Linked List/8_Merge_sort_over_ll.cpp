// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;
	// constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertHead(node *&head, int data) {
	// check if ll is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}

	node *new_bucket = new node(data);
	new_bucket->next = head;
	head = new_bucket;
}

void printNode(node *head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void take_input(node *&head) {
	int data;
	cin >> data;

	while (data != -1) {
		insertHead(head, data);
		cin >> data;
	}
}

node *midPoint(node *head) {
	node *slow = head;
	node *fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node *merge(node *head1, node *head2) {
	// base case
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	node *temp = NULL;
	if (head1->data < head2->data) {
		temp  = head1;
		temp->next = merge(head1->next, head2);
	}
	else {
		temp = head2;
		temp->next = merge(head1, head2->next);
	}
	return temp;
}


// Time complexity - O(N logN)
// Space complexity - O(N)
node *merge_sort(node *head) {
	// base case
	if (head == NULL or head->next == NULL) {
		return head;
	}

	// Recursive case
	// 1. Break
	node *mid = midPoint(head);
	node * first = head;
	node * second = mid->next;
	mid->next = NULL;

	// 2. Recursive sort the linked list
	first = merge_sort(first);
	second = merge_sort(second);
	return merge(first, second);
}

int main() {
	node *head = NULL;
	take_input(head);
	printNode(head);

	cout << "Sorting the Linked List : " << endl;
	head = merge_sort(head);
	printNode(head);
	return 0;
}

/*
Input :-
--------
5 6 8 2 1 -1

Output :-
---------
1 -> 2 -> 8 -> 6 -> 5 ->
Sorting the Linked List :
1 -> 2 -> 5 -> 6 -> 8 ->
*/