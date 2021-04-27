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

node *addTwoLinkedList(node *head1, node *head2) {
	// check both the linked list are empty or not
	if (head1 == NULL and head2 == NULL) {
		return NULL;
	}

	// creating number1 from first linked list
	int number1 = 0;
	while (head1 != NULL) {
		number1 = number1 * 10 + head1->data;
		head1 = head1->next;
	}

	// creating number2 from second linked list
	int number2 = 0;
	while (head2 != NULL) {
		number2 = number2 * 10 + head2->data;
		head2 = head2->next;
	}
	// cout << "First : " << number1 << " and " << "Second : " << number2 << endl;
	// cout << "Addition : " << number1 + number2 << endl;

	// adding num1 and num2
	int total = number1 + number2;

	// Creating new linked list by extracting digit
	// and inserting digit at head of new linked list
	node *newList = NULL;
	while (total) {
		int rem = total % 10;
		insertAtHead(newList, rem);
		total = total / 10;
	}
	return newList;
}
int main() {
	node *head1 = create_ll();
	cout << "Printing 1 The Linked List : " << endl;
	printNode(head1);

	node *head2 = create_ll();
	cout << "Printing 2 The Linked List : " << endl;
	printNode(head2);

	cout << "Addition of two linked list : " << endl;
	node *head3 = addTwoLinkedList(head1, head2);

	printNode(head3);

	return 0;
}

/*

Input :-
----------
3 2 1 -1
1 2 3 -1

Output :-
-----------
Printing 1 The Linked List :
1 -> 2 -> 3 ->
Printing 2 The Linked List :
3 -> 2 -> 1 ->
Addition of two linked list :
4 -> 4 -> 4 ->

*/