// Code By - Manish Hedau
// Implementing Stack Data Structure by using Underline data structure 'Array'
#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
	int *array = NULL;
	int Top = -1;
	int size = 0;

public:
	Stack(int size) {
		this->array = new int[size];
		this->size = size;
	}

	// push is used to insert data at Top of the stack
	// and also check one condition is that stack is full or not
	void push(int data) {
		// check stack is full or not
		if (size == Top + 1) {
			cout << "Stack is full! and pass data = " << data << endl;
			return;
		}

		Top++;
		array[Top] = data;
	}

	// Pop is used to remove data from Top of the stack
	// also check one condition is that stack is empty or not
	int pop() {
		// check stack is empty or not
		if (Top == -1) {
			cout << "Stack is empty!" << endl;
			return -1;
		}

		int temp = array[Top];
		Top--;
		return temp;
	}

	// printing stack from bottom to Top
	void printStack() {
		// iterate upto Top
		for (int i = 0; i <= Top; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	// function return Top element data of stack
	int top() {
		if (Top == -1) {
			return -1;
		}
		return array[Top];
	}

};

int main() {

	Stack s(5);

	for (int i = 1; i <= 5; i++) {
		s.push(i);
	}
	cout << "Printing Stack : " << endl;
	s.printStack();

	cout << "Poping Data : " << endl;
	cout << "pop Element : " << s.pop() << endl;
	cout << "pop Element : " << s.pop() << endl;
	s.printStack();
	cout << "Top Element: " << s.top() << endl;
	return 0;
}

/*
Output :-
-------
Printing Stack :
1 2 3 4 5
Poping Data :
pop Element : 5
pop Element : 4
1 2 3
Top Element: 3

*/