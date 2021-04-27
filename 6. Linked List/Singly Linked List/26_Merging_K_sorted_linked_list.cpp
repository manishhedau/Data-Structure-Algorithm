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

// Merginig K linked list in one linked list
node *mergeTwoSortedLinkedList(node *first, node * second) {
	// check both the linked list are empty or not
	if (first == NULL and second == NULL) {
		return NULL;
	}

	node *newList = NULL;
	node *newCurr = NULL;

	while (first != NULL and second != NULL) {

		if (newList == NULL) {
			if (newList == NULL and first->data < second->data) {
				node *firstNext = first->next;
				newList = first;
				newList->next = NULL;
				newCurr = newList;
				first = firstNext;
			}
			else {
				node *secondNext = second->next;
				newList = second;
				newList->next = NULL;
				newCurr = newList;
				second = secondNext;
			}
		}
		else {
			if (first->data <= second->data) {
				node *firstNext = first->next;
				newCurr->next = first;
				first->next = NULL;
				newCurr = first;
				first = firstNext;
			}
			else {
				node *secondNext = second->next;
				newCurr->next = second;
				second->next = NULL;
				newCurr = second;
				second = secondNext;
			}
		}
	}

	// insert all the remaining nodes
	while (first != NULL) {
		node *firstNext = first->next;
		newCurr->next = first;
		first->next = NULL;
		newCurr = first;
		first = firstNext;
	}

	while (second != NULL) {
		node *secondNext = second->next;
		newCurr->next = second;
		second->next = NULL;
		newCurr = second;
		second = secondNext;
	}

	return newList;
}
int main() {

	int k;
	cin >> k;
	node *head1 = NULL;
	if (k >= 1) {
		head1 = create_ll();
		cout << "Printing 1 Linked List : " << endl;
		printNode(head1);
	}

	for (int i = 1; i < k; i++) {
		node *head2 = create_ll();
		cout << "Printing " << i + 1 << " Linked List : " << endl;
		printNode(head2);

		head1 = mergeTwoSortedLinkedList(head1, head2);
	}

	cout << "Merging k the linked list in sorted order : " << endl;
	printNode(head1);


	return 0;
}

/*

Input :-
----------
3 --> k value
5 4 3 2 1 -1
10 9 8 7 1 -1
15 14 13 12 1 -1


Output :-
-----------
Printing 1 Linked List :
1 -> 2 -> 3 -> 4 -> 5 ->
Printing 2 Linked List :
1 -> 7 -> 8 -> 9 -> 10 ->
Printing 3 Linked List :
1 -> 12 -> 13 -> 14 -> 15 ->
Merging k the linked list in sorted order :
1 -> 1 -> 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> 8 -> 9 -> 10 -> 12 -> 13 -> 14 -> 15 ->

*/