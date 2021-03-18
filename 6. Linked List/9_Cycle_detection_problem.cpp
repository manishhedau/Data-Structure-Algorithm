// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;
	// constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertHead(node *&head, int data) {
	// check if ll is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}

	node *new_bucket = new node(data);
	new_bucket->next = head;
	head = new_bucket;
}

void printNode(node *head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void take_input(node *&head) {
	int data;
	cin >> data;

	while (data != -1) {
		insertHead(head, data);
		cin >> data;
	}
}

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

void create_cycle(node *&head) {
	// create cycle function will create cycle in LL
	node *temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	node *mid = midPoint_optimized(head);

	temp->next = mid;
}

bool cycle_detection(node *head) {
	// pointer approach or runner Technique
	node *slow = head;
	node *fast = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}

	// not found any cycle
	return false;
}
int main() {
	node *head = NULL;
	take_input(head);
	printNode(head);
	cout << "creating the cycle : " << endl;
	create_cycle(head);
	if (cycle_detection(head)) {
		cout << "cycle found in ll " << endl;
	}
	else {
		cout << "cycle not found in ll" << endl;
	}
	return 0;
}

/*
Input :-
--------
6 5 4 3 2 1 -1

Output :-
---------
1 -> 2 -> 3 -> 4 -> 5 -> 6 ->
creating the cycle :
cycle found in ll

*/