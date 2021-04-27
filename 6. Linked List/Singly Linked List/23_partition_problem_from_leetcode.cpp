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


node *tail = NULL;
void insertAtHead(node *&head, int data) {
	// check linked list is empty or not
	if (head == NULL) {
		head = new node(data);
		tail = head;
		return;
	}

	// when linked is not empty then
	node *newBucket = new node(data);
	newBucket->next = head;
	head = newBucket;
}
node *create_ll() {

	int data;
	cin >> data;

	node *head = NULL;
	while (data != -1) {
		insertAtHead(head, data);
		cin >> data;
	}
	return head;
}

int lengthOfLL(node *head) {
	// check linked is empty
	if (head == NULL) {
		// because linked list is empty
		return 0;
	}
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

void printNode(node *head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty !" << endl;
		return;
	}

	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void insertAtTail(node *curr) {
	// just add curr node with tail pointer
	tail->next = curr;
	curr->next = NULL;
	tail = curr;
}

// 1. Approach -
// We will devide the linked list in two parts
// first linked list contain nodes upto kTh node
// second linked list contain remaing node
// then we will just insert second node one by one in first linked list at right posittion
/*
Example :
	Original list = 1->4->3->2->5->2->Null
	K = 3;
	first = 1->4->3->Null
	second = 2->5->2->Null
	insert second list nodes in first list
	first = 1->2->2->4->3->5->Null
*/
void insertAtsorted(node *&head, node *&tail, node *curr) {
	// check linked list is empty or not
	if (head == NULL) {
		// because linked list is empty
		return;
	}

	if (head->data >= curr->data) {
		curr->next = head;
		head = curr;
		return;
	} else if (tail->data <= curr->data) {
		tail->next = curr;
		curr->next = NULL;
		tail = curr;

	}
	else {
		node *temp = head;
		node *prev = NULL;
		while (temp->data < curr->data and temp != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = curr;
		curr->next = temp;
	}
}

void partionInLL(node *&head, int k) {
	// check linked list is empty or not
	if (head == NULL) {
		return;
	}

	node *tempHead = head;
	while (tempHead->data != k and tempHead != NULL) {
		tempHead = tempHead->next;
	}

	node *second = tempHead->next;
	tempHead->next = NULL;
	while (second != NULL) {
		node *nextNode = second->next;
		insertAtsorted(head, tempHead, second);
		second = nextNode;
	}
}


int main() {
	node *head = create_ll();
	cout << "Printing The Linked List : " << endl;
	printNode(head);

	int k;
	cin >> k;
	cout << "After partition linked list : " << endl;
	partionInLL(head, k);
	printNode(head);
	return 0;
}

/*

Input :-
----------
1 2 8 2 10 5 3 -1

5

Output :-
-----------
Printing The Linked List :
3 -> 5 -> 10 -> 2 -> 8 -> 2 -> 1 ->
After partition linked list :
1 -> 2 -> 2 -> 3 -> 5 -> 8 -> 10 ->

*/