// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


/*
Approach :-
------------
sortStack function is used extract the all stack element recursively
and placeData function is used to place current Given data element at
there right position in stack

Time complexity :- O(N^2) // two recursive function
Space complexity :- O(1)
*/
void placeData(stack<int>&s1, int data) {
	// base case
	if (s1.size() == 0) {
		s1.push(data);
		return;
	}
	else {
		if (s1.top() > data) {
			// extract top element call function unitl s1.top()<=data
			int topelement = s1.top();
			s1.pop();

			// recusive case
			placeData(s1, data);
			// push topelement
			s1.push(topelement);
			return;
		}
		else {
			// when s1.top()<=data
			s1.push(data);
		}
	}
	return;
}
void sortStack(stack<int>&s1) {
	// base case
	if (s1.size() == 0) {
		return;
	}
	else {
		// extract each element in stack by recursion
		int data = s1.top();
		s1.pop();
		// recusive case
		sortStack(s1);
		// now try to place data at there right position in stack
		placeData(s1, data);
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

	sortStack(s1);

	cout << "Printing the sorted Stack : " << endl;

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
unsorted element
5
1
4
2
3


Output :-
---------
Printing the sorted Stack :
5, 4, 3, 2, 1,

Sorted Stack element :-
---------------------------
5
4
3
2
1

*/