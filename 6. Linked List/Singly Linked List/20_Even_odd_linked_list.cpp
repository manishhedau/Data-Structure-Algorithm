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

void oddAFterEven(node *&head) {
	// check linked list is empty or not
	if (head == NULL) {
		cout << "Linked List is empty!" << endl;
		return;
	}

	// seperate odd and even part of linked list
	node *tempHead = head;
	node *odd = NULL;
	node *oddTail = NULL;
	node *even = NULL;
	node *evenTail = NULL;

	while (tempHead != NULL) {
		node *nextNode = tempHead->next;
		if (tempHead->data % 2 == 0) {
			// for first element to add in even linked list
			if (even == NULL) {
				even = tempHead;
				evenTail = even;
			}
			else {
				// for remaining all even node
				evenTail->next = tempHead;
				evenTail = tempHead;
			}
		} else {
			// for first odd node to add in odd linked list
			if (odd == NULL) {
				odd = tempHead;
				oddTail = odd;
			}
			else {
				// for remaining all odd node
				oddTail->next = tempHead;
				oddTail = tempHead;
			}
		}
		tempHead = nextNode;
	}

	// connect odd and even node
	oddTail->next = even;
	evenTail->next = NULL;

	// head point to odd
	head = odd;
}


int main() {
	node *head = create_ll();
	cout << "Printing The Linked List : " << endl;
	printNode(head);

	cout << "After Seperating Odd and Even Nodes : " << endl;
	oddAFterEven(head);
	printNode(head);
	return 0;
}

/*

Input :-
----------
6 5 4 3 2 1 -1

Output :-
-----------

Printing The Linked List :
1 -> 2 -> 3 -> 4 -> 5 -> 6 ->
After Seperating Odd and Even Nodes :
1 -> 3 -> 5 -> 2 -> 4 -> 6 ->

*/