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


// Approach -
// take both linked list and iterate over it parellel
// and create new linked list by first and second linked list
// so at every iteration we will check which linked list node contain less value
// first->data<second->data or first->data>second->data (both condition should be applied)
// and less value node,  we add at head of new linked list

// and like this we will continues this process both linked list not empty
// and by using insertNodeAtHead() function we will insert node at head of new linked list
// and at the end we will get new list which contain data in decreasing order
// and we just return that new linked list to main() function
// Time complexity - O(N+M) - N & M - denote length of both linked list
// Space complexity - O(1) - Because we are not taking any extra space here.

void insertNodeAtHead(node *&newList, node *curr) {
	// when linked list has no element
	// then newList is NULL
	if (newList == NULL) {
		newList = curr;
		curr->next = NULL;
		return;
	}

	// when linked list is not empty
	curr->next = newList;
	newList = curr;
}
// Merge two sorted linked list from the end
node *mergeTwoSortedLLFromEnd(node *first, node *second) {
	if (first == NULL and second == NULL) {
		// because both the linked list is empty
		return NULL;
	}

	// New list which store nodes in decreasing order
	node *newList = NULL;

	while (first != NULL and second != NULL) {
		if (newList == NULL and first->data <= second->data) {
			node *firstNext = first->next;
			insertNodeAtHead(newList, first);
			first = firstNext;
		}
		else if (newList == NULL and first->data >= second->data) {
			node *secondNext = second->next;
			insertNodeAtHead(newList, second);
			second = secondNext;
		}
		else if (newList != NULL and first->data <= second->data)
		{
			node *firstNext = first->next;
			insertNodeAtHead(newList, first);
			first = firstNext;
		}
		else if (newList != NULL and first->data >= second->data) {
			node *secondNext = second->next;
			insertNodeAtHead(newList, second);
			second = secondNext;
		}
	}

	// for remaining data insert All at head;
	// for first linked list
	while (first != NULL) {
		node *firstNext = first->next;
		insertNodeAtHead(newList, first);
		first = first->next;
	}

	// for second linked list
	while (second != NULL) {
		node *secondNext = second->next;
		insertNodeAtHead(newList, second);
		second = secondNext;
	}

	// now return new linked list to main function
	return newList;
}
int main() {
	node *head1 = create_ll();
	cout << "Printing First Linked List : " << endl;
	printNode(head1);

	node *head2 = create_ll();
	cout << "Printing Second Linked List : " << endl;
	printNode(head2);

	cout << "Merging Two Linked List in Decreasing Order : " << endl;
	node *head3 = mergeTwoSortedLLFromEnd(head1, head2);
	printNode(head3);

	return 0;
}

/*

Input :-
----------
5 3 1 -1
10 8 7 6 2 -1

Output :-
-----------
Printing First Linked List :
1 -> 3 -> 5 ->
Printing Second Linked List :
2 -> 6 -> 7 -> 8 -> 10 ->
Merging Two Linked List in Decreasing Order :
10 -> 8 -> 7 -> 6 -> 5 -> 3 -> 2 -> 1 ->


*/