// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


/*
Approach :-
------------
sortStack function is used extract the all stack element recursively
and insertAtBottom function is used to push data at bottom of stack recursively

Time complexity :- O(N^2) // two recursive function
Space complexity :- O(1)
*/
void insertAtBottom(stack<int>&s1, int data) {
	// base case
	if (s1.size() == 0) {
		s1.push(data);
		return;
	}
	else {
		// extract the all element upto stack become empty.
		int topelement = s1.top();
		s1.pop();

		// recusive case
		insertAtBottom(s1, data);
		// push topelement
		s1.push(topelement);
		return;
	}
	return;
}

void reverseStackRecursive(stack<int>&s1) {
	// base case
	if (s1.size() == 0) {
		return;
	}
	else {
		// extract each element in stack by recursion
		int data = s1.top();
		s1.pop();
		// recusive case
		reverseStackRecursive(s1);
		// insert data element at bottom of stack
		insertAtBottom(s1, data);
	}
	return;
}
int main() {
	int n;
	cin >> n;

	stack<int>s1;
	int data;
	for (int i = 0; i < n; i++) {
		cin >> data;
		s1.push(data);
	}

	reverseStackRecursive(s1);

	cout << "Printing the Reverse Stack : " << endl;

	while (!s1.empty()) {
		cout << s1.top() << ", ";
		s1.pop();
	}
	cout << endl;


	return 0;
}

/*
Input :-
----------
5 --> n
Original Stack element
5
4
3
2
1


Output :-
---------
Printing the Reverse Stack :
1, 2, 3, 4, 5,

Reverse Stack element :-
---------------------------
1
2
3
4
5

*/