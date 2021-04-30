// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

/*
Question :- NGL(Nearest greatest element to Left)
------------
find nearest greater element to left for all element in array,
there is no greater element is present then just print -1.

Ex :-
arr[] = {5, 6, 3, 10, 8}
Output :- {-1, -1, 6, -1, 10}
*/

/*
1. Approach : -
------------
Basic approach is like we have to take two loop
1. outer loop will track the current element
2. and inner loop is used to find left nearest greater element

for (int i = 0; i < n; i++) {
	// this flag denote the we find greater element or not
	// flag = false then that means we have find nearest greater element
	// flag = true then that means there is no  greater element present than curr element
	bool flag = true;
	for (int j = i - 1; j>=0; j--) {
		if (arr[i] < arr[j]) {
			v.push_back(arr[j]);
			flag = false;
			break;
		}
	}
	if (flag) {
		v.push_back(-1);
	}
}

Time complexity - O(N^2)
Space complexity - O(1)
*/


/*
2. Approach :-
-------------
1. create empty vector, stack
2. now iterate from left to right
	1) when s.size()==0 , push_back(-1) in vector because there is no greater element
	2) when s.top()>arr[i], push_back(s.top()) means we have found the nearest greater element
	3) when s.top()<=arr[i],
		a) pop item unitl s.top()>arr[i] or s.size==0

		then there can be two possiblities left in stack
		1). stack would become empty, then push_back(-1)
		2). s.top()>arr[i], push_back(s.top())
	4)and push current element in stack


Here we don't need to reverse the because we are iterating from left to right.
Time complexity - O(N logN)
Space complexity - O(N)
*/

vector<int>v;
void find_NGL(int *arr, int n) {
	// creating an empty vector
	stack<int>s;
	// now we have to find NGR so we iterate from left to right
	for (int i = 0; i < n; i++) {

		// when size is empty that means
		// there is no element greater than current element
		if (s.size() == 0) {
			v.push_back(-1);
		}
		else if (s.top() > arr[i]) {
			// we found greater element then , push into vector
			v.push_back(s.top());
		}
		else if (s.top() <= arr[i]) {
			// pop item unitl s.top()>arr[i] or s.size==0
			while (s.size() != 0 and s.top() <= arr[i]) {
				s.pop();
			}

			// here are two case
			// 1. stack is empty
			if (s.size() == 0) {
				v.push_back(-1);
			}
			else {
				v.push_back(s.top());
			}
			// 2. stack s.top()>arr[i]
		}
		// at every iteration push current element in stack
		s.push(arr[i]);
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n] = {0};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	find_NGL(arr, n);
	cout << "Printing the Left nearest greater element : " << endl;
	for (int val : v) {
		cout << val << ", ";
	}
	cout << endl;
	return 0;
}

/*
Input :-
---------
5
5 6 3 10 8

Output :-
-----------
Printing the Left nearest greater element :
-1, -1, 6, -1, 10,

*/