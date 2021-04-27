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


int length(node *head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}
void deleteFromHead(node *&head) {
	// check linked list is empty
	if (head == NULL) {
		return;
	}

	// store next node address in pointToNext variable
	node *pointToNext = head->next;
	// delete head node
	delete head;
	// head point to pointToNext which store next node address
	head = pointToNext;
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
void deleteFromPosition(node *&head, int pos) {
	// check ll is empty
	if (head == NULL) {
		return;
	}

	// check user want to delete first node means head
	if (pos == 1) {
		deleteFromHead(head);
		return;
	}
	// check pos is valid or not
	// if invalid then just delete last node
	if (pos > length(head)) {
		deleteFromTail(head);
		return;
	}
	else {
		node *curr = head, *prev;
		int cnt = 1;
		while (cnt < pos) {
			cnt++;
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		delete curr;
	}
}
int main() {
	int arr[5] = { 1, 2, 3, 4, 5};
	int n = 5;

	node *head = create_ll(arr, n);
	printNode(head);

	cout << "Delete form position : " << endl;
	deleteFromPosition(head, 1);
	printNode(head);
	return 0;
}

/*
Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 ->
Delete form position :
1 -> 2 -> 4 -> 5 ->

1 -> 2 -> 3 -> 4 -> 5 ->
Delete form position :
1 -> 2 -> 3 -> 4 ->

1 -> 2 -> 3 -> 4 -> 5 ->
Delete form position :
2 -> 3 -> 4 -> 5 ->
*/