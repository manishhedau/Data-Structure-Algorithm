// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

/*
Question :- NGR(Nearest greatest element to right)
------------
find nearest smallest element to right for all element in array,
there is no smallest element is present then just print -1.

Ex :-
arr[] = {5, 6, 3, 10, 8}
Output :- {3, 3, -1, 8, -1}
*/

/*
1. Approach : -
------------
Basic approach is like we have to take two loop
1. outer loop will track the current element
2. and inner loop is used to find right nearest smallest element

for (int i = 0; i < n; i++) {
	// this flag denote the we find smallest element or not
	// flag = false then that means we have find nearest smallest element
	// flag = true then that means there is no  smallest element present than curr element
	bool flag = true;
	for (int j = i + 1; j < n; j++) {
		if (arr[i] >= arr[j]) {
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
2. now iterate from right to left
	1) when s.size()==0 , push_back(-1) in vector because there is no smallest element
	2) when s.top()<=arr[i], push_back(s.top()) means we have found the nearest smallest element
	3) when s.top()>arr[i],
		a) pop item unitl s.top()<=arr[i] or s.size==0

		then there can be two possiblities left in stack
		1). stack would become empty, then push_back(-1)
		2). s.top()<=arr[i], push_back(s.top())
	4)and push current element in stack

3. reverse the vector

Time complexity - O(N logN)
Space complexity - O(N)
*/

vector<int>v;
void find_NSR(int *arr, int n) {
	// creating an empty vector
	stack<int>s;
	// now we have to find NSR so we iterate from right to left
	for (int i = n - 1; i >= 0; i--) {

		// when size is empty that means
		// there is no element smallest than current element
		if (s.size() == 0) {
			v.push_back(-1);
		}
		else if (s.top() <= arr[i]) {
			// we found smallest element then , push into vector
			v.push_back(s.top());
		}
		else if (s.top() > arr[i]) {
			// pop item unitl s.top()<=arr[i] or s.size==0
			while (s.size() != 0 and s.top() > arr[i]) {
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
			// 2. stack s.top()<=arr[i]
		}
		// at every iteration push current element in stack
		s.push(arr[i]);
	}

	// reverse the vector
	reverse(v.begin(), v.end());
}

int main() {

	int n;
	cin >> n;

	int arr[n] = {0};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	find_NSR(arr, n);
	cout << "Printing the right nearest smallest element : " << endl;
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
Printing the right nearest smallest element :
3, 3, -1, 8, -1,

*/