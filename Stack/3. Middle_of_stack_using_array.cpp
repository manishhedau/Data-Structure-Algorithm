// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

// Note - when we use doubly linked list then we have to check even and odd condition for mid.
// in this solution we are using zero based indexing so don't need to check condtion
// 5/2 = 2 and 6/2 = 3
// if we used 1 based indexing then
// 5/2 = 2+1 = 3 and 6/2 = 3 // here in odd condition we have to add 1 in result.

class my_stack {
private:
	int *arr = NULL;
	int top;
	int mid;
	int size;
public:
	my_stack(int size) {
		this->size = size;
		arr = new int[size] {0};
		top = -1;
		mid = -1;
	}

	bool isEmpty() {
		return top == -1;
	}
	void push(int data) {
		// check stack is full or not
		if (size == top + 1) {
			cout << "Stack is full" << endl;
			return;
		}

		top++;
		arr[top] = data;
		if (top == 1) {
			mid = arr[top];
		}
		else {
			// even and odd condtion
			mid = arr[top / 2];
		}
	}

	void pop() {
		// check stack is empty or not
		if (isEmpty()) {
			cout << "Stack is empty !" << endl;
			return;
		}
		arr[top] = 0;
		top--;

		if (top == -1) {
			mid = -1;
		}
		else {
			mid = arr[top / 2];
		}
	}

	int top_element() {
		if (top == -1) {
			return -1;
		}
		return arr[top];
	}
	int midOfStack() {
		return mid;
	}

	void printStack() {
		// iterating from bottom to top
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	my_stack ms(5);
	for (int i = 1; i <= 5; i++) {
		ms.push(i);
	}

	ms.printStack();
	cout << "middle of stack : " << ms.midOfStack() << endl;
	ms.pop();
	ms.printStack();
	cout << "middle of stack : " << ms.midOfStack() << endl;

	return 0;
}

/*
Output :-
==========
1 2 3 4 5
middle of stack : 3
1 2 3 4
middle of stack : 2
*/