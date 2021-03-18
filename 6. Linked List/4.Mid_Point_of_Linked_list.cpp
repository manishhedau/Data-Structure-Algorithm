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

void printNode(node *head) {
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

void take_input(node *&head) {
	int n;
	cin >> n;

	while (n != -1) {
		insertAtHead(head, n);
		cin >> n;
	}
}

int length(node *head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

// Time Complexity - O(2N)
// Because N iteration for length
// and N Iteration for iterating over len/2.
// N + N = 2N
node *mid_point(node *head) {
	node *temp = head;
	int cnt = 0;
	while (cnt < (length(head) / 2)) {
		temp = temp->next;
		cnt++;
	}
	return temp;
}

// Time Complexity - O(N)
// For just one iteration
node *midPoint_optimized(node *head) {

	if (head == NULL or head->next == NULL) {
		return head;
	}
	node *slow = head;
	node *fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
int main() {
	node *head = NULL;
	take_input(head);

	printNode(head);

	cout << "length : " << length(head) << endl;
	node *mid = midPoint_optimized(head);
	cout << "mid : " << mid->data << endl;
	return 0;
}

/*
Input :-
----------
5 4 3 2 1 -1

Output :-
--------
1 -> 2 -> 3 -> 4 -> 5 ->
length : 5
mid : 3

*/