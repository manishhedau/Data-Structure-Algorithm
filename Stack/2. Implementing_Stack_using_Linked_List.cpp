// Code By - Manish Hedau
// implementing Stack using Singly linked list
#include<bits/stdc++.h>
using namespace std;

// using linked list whenever we push data into stack
// we push data in head of the linked list

class node {
public:
	int data;
	node *next;

	node(int data) {
		this->data = data;
		next = NULL;
	}
};

class Stack {
public:
	node *head = NULL;

	// check stack is empty or not
	bool isEmpty() {
		return head == NULL;
	}

	// pushing data on top of the stack
	void push(int data) {
		// for first element
		if (head == NULL) {
			head = new node(data);
			return;
		}

		// when stack has one or more elements
		node *newBucket = new node(data);
		newBucket->next = head;
		head = newBucket;
	}

	// poping data from top of the stack
	void pop() {
		// check stack is empty or not
		if (isEmpty()) {

			cout << "Stack is empty !" << endl;
			return;
		}
		// when stack is not empty
		node *nextNode = head->next;
		delete head;
		head = nextNode;
	}

	// return top of the stack
	int top() {
		return head->data;
	}

	// printing stack data from top to bottom
	void printStack() {
		// iterate over the stack
		node *curr = head;
		while (curr != NULL) {
			cout << curr->data << " -> ";
			curr = curr->next;
		}
		cout << endl;
	}
};
int main() {

	Stack s;
	for (int i = 1; i <= 5; i++) {
		s.push(i * i);
	}

	cout << "Printing stack : " << endl;
	s.printStack();
	cout << "Top : " << s.top() << endl;
	for (int i = 0; i <= 5; i++) {
		s.pop();
	}
	return 0;
}

/*
Output :-
----------
Printing stack :
25 -> 16 -> 9 -> 4 -> 1 ->
Top : 25
Stack is empty !
*/