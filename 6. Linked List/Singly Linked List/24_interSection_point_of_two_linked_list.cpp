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



// Approach -
// We store the first linked list all nodes address in Array(of type node).
// and then we iterate over the second linked list
// and in every iteration we will check the currNode is present in array or not
// if there is an intersection then any one currNode is present in Array
// Otherwise we return Null.

// By using isPresent Function we will check the currNode is present in array or not.
// Time complexity - O(N^2 + m) : N & M - denote length of both linked list
// Space complexity - O(N) : for storing first linked list node address
bool isPresent(node *currNode, node **arr, int len) {

	// iterate over the array and check currNode address is present in array
	// or not
	for (int i = 0; i < len; i++) {
		if (arr[i] == currNode) {
			return true;
		}
	}
	return false;
}

node *intersectionPointOfTwoLinkedList(node *first, node *second) {
	// check both the linked list is empty or not
	if (first == NULL and second == NULL) {
		// because both the linked list are emepty
		return NULL;
	}

	// store address of first linked list into array of nodes
	int len = lengthOfLL(first);
	node *arr[len] = {NULL};
	int cnt = 0;
	node *tempfirst = first;
	while (tempfirst != NULL) {
		arr[cnt] = tempfirst;
		tempfirst = tempfirst->next;
		cnt++;
	}

	// now iterate over the second linked list
	while (second != NULL) {
		if (isPresent(second, arr, len)) {
			return second;
		}
		second = second->next;
	}
	return NULL;
}

int main() {
	node *head1 = create_ll();
	cout << "Printing The Linked List : " << endl;
	printNode(head1);

	node *head2 = create_ll();
	head2->next->next = head1->next->next;
	printNode(head2);

	cout << "Inter section point of two linked list : " << endl;
	node *interSectionNode = intersectionPointOfTwoLinkedList(head1, head2);
	if (interSectionNode) {
		cout << "Point : " << interSectionNode->data << endl;
	}
	else {
		cout << "No intersection point is detect!" << endl;
	}
	return 0;
}

/*

Input :-
----------
5 4 3 2 1 -1
20 10 -1

Output :-
-----------
Printing The Linked List :
1 -> 2 -> 3 -> 4 -> 5 ->
10 -> 20 -> 3 -> 4 -> 5 ->
Inter section point of two linked list :
Point : 3


*/