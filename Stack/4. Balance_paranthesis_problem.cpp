// Code By - Manish Hedau
// Balance paranthesis problem for three brackets {}, [], ().
#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
	char *array = NULL;
	int Top = -1;
	int size = 0;

public:
	Stack(int size) {
		this->array = new char[size];
		this->size = size;
	}

	bool isEmpty() {
		return Top == -1;
	}
	// push is used to insert data at Top of the stack
	// and also check one condition is that stack is full or not
	void push(char data) {
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
	void pop() {
		// check stack is empty or not
		if (Top == -1) {
			cout << "Stack is empty!" << endl;
			return;
		}

		array[Top] = '\0';
		Top--;
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
	char top() {
		if (Top == -1) {
			return '0';
		}
		return array[Top];
	}

};

bool isMatch(char ch1, char ch2) {
	return ((ch1 == '(' and ch2 == ')') or
	        (ch1 == '[' and ch2 == ']') or
	        (ch1 == '{' and ch2 == '}'));
}


bool isBalance(char *arr, int len , Stack &s) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == '(' or arr[i] == '{'  or arr[i] == '[') {
			s.push(arr[i]);
		}
		else {
			if (s.isEmpty()) {
				return false;
			}
			else if (isMatch(s.top(), arr[i]) == false) {
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return (s.isEmpty() == true);
}


int main() {

	int len;
	cin >> len;

	char arr[len];
	cin >> arr;
	Stack s(len);

	if (isBalance(arr, len, s))
		cout << "Paranthesis are balanced!" << endl;
	else
		cout << "Paranthesis are not balanced!" << endl;
	return 0;
}

/*
Input and Output :-
-------------------
2
}{
Paranthesis are not balanced!

Input and Output :-
-----------------------
4
{}()
Paranthesis are balanced!

Input and Output :-
-----------------------
6
{([])}
Paranthesis are balanced!

*/