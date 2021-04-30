// Code By - Manish Hedau
// Balance paranthesis problem for three brackets {}, [], ().
#include<bits/stdc++.h>
using namespace std;
/*
Question :-
-----------
Given an paranthesized expression as string
return no of balanced paranthesis in given string.
Input :-
------------
5
((())

Output :-
---------
No of balance paranthesis in : 4

Explaination :-
-------------
(()) -->these paranthesis are balanced in given input string.
*/

/*
Approach :-
-------------
Approach is same for checking given paranthesised expression
is balanced or not

same approach we just need to maintain one variable which count valid paranthesis
and where we find balaced paranthesis in expression we just have to
add 2 to that countBalancedpara += 2.

*/

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


int findNoOfBalanceParanthesis(char *arr, int len , Stack &s) {
	int countBalancedpara = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == '(' or arr[i] == '{'  or arr[i] == '[') {
			s.push(arr[i]);
		}
		else {

			if (isMatch(s.top(), arr[i]) == true) {
				s.pop();
				countBalancedpara += 2;
			}
		}
	}
	return countBalancedpara;
}


int main() {

	int len;
	cin >> len;

	char arr[len];
	cin >> arr;
	Stack s(len);

	cout << "No of balance paranthesis in : " << findNoOfBalanceParanthesis(arr, len, s);
	return 0;
}

/*
Input :-
------------
5
((())

Output :-
---------
No of balance paranthesis in : 4

Input :-
-----------
6
({[]})

Output :-
--------
No of balance paranthesis in : 6

Input :-
-------
5
({[]}
Output :-
--------
No of balance paranthesis in : 4
*/