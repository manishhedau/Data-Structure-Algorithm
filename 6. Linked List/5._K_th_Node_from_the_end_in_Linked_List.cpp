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

// Brute force Approach
// Time complexity - O(2N)
// Because N iteration for length
// and K iteration for K th Node which is n = k
// N + N = 2N
node * kNode(node *head, int k) {

	int cnt = 0;
	node *temp = head;
	while (cnt < (length(head) - k)) {
		temp = temp->next;
		cnt++;
	}
	return temp;
}

// Optimized Approach -
// Time complexity - O(N)
// Just signle iteration
// Approach - Fast move to k steps
// then slow and fast move one by one step upto fast->next = null
// and then slow will point to last Kth Node
node *knode_Optimized(node *head, int k) {
	node *slow = head;
	node *fast = head;
	int cnt = 0;
	while (fast->next != NULL) {
		if (cnt < k) {
			fast = fast->next;
			cnt++;
		}
		else {
			fast = fast->next;
			slow = slow->next;
		}
	}

	return slow;
}


int main() {
	node *head = NULL;
	take_input(head);

	printNode(head);

	cout << "length : " << length(head) << endl;
	node *knode = kNode(head, 3);
	cout << "K-th Node : " << knode->data << endl;
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
K-th Node : 3


*/