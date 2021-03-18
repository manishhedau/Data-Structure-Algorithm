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

// Time complexity - O(N) for iterating over LL
void printNode(node *head) {
	// iterate over the linked list for printing the value
	// iterate over the linked list till then head = NULL
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;

}

void insertAtHead(node *&head, int data) {
	// if ll is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}

	// if ll is not empty
	node *new_bucket = new node(data);
	new_bucket->next = head;
	head = new_bucket;
}

void reverse_ll(node*&	head)
{
	// Sliding windows technique
	node *next = head;
	node *prev = NULL, *current = NULL;
	while (next != NULL)
	{
		prev = current;
		current = next;

		next = next->next;

		current->next = prev;
	}
	head = current;
}

void reverse_ll(node*& head)
{
	// Initialize current, previous and
	// next pointers
	node *current = head;
	node *prev = NULL, *next = NULL;
	while (current != NULL)
	{
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	head = prev;
}
int main() {

	node *head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	cout << "Original Linked List : " << endl;
	printNode(head);
	cout << "Reverse the Linked List : " << endl;
	reverse_ll(head);
	printNode(head);

	return 0;
}

/*
Output :-
--------
Original Linked List :
1 -> 2 -> 3 -> 4 -> 5 ->
Reverse the Linked List :
5 -> 4 -> 3 -> 2 -> 1 ->
*/