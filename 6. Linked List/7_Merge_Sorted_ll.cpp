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
int main() {
	node *head1 = NULL, *head2 = NULL;
	take_input(head1);
	take_input(head2);

	printNode(head1);
	printNode(head2);

	cout << "Mergining the two sorted LL : " << endl;
	node *head = merge(head1, head2);
	printNode(head);

	return 0;
}

/*
Input :-
--------
7 4 3 1 -1
10 8 2 0 -1

Output :-
---------
1 -> 3 -> 4 -> 7 ->
0 -> 2 -> 8 -> 10 ->
Mergining the two sorted LL :
0 -> 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 10 ->
*/