// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;
/*
1. Approach :-
--------------
so the brute force approach is like we have find to find nearest smallest element
in both the side(right and left) for current element .
now find calculate expanded width for current number
width = right - left -1;
now to find the area of that ractangle
area = width *height(current element arr[i])

now find maxArea by compairing
if(maxArea<area){
	maxArea = area;
}

Time complexity :- O(N^2) // because we are using nested loops
Space complexity :- O(1) // we are using any other space just instead of creating some variables
*/

void findMaxAreaOfHistogram(vector<int>arr, int n) {

	int maxArea = 0;
	// iterate over the vector
	for (int i = 0; i < n; i++) {

		// find right smallest element index
		int right;
		for (right = i + 1; right < n; right++) {
			if (arr[i] > arr[right])
				break;
		}

		// find left smallest element index
		int left;
		for (left = i - 1; left >= 0; left--) {
			if (arr[i] > arr[left])
				break;
		}

		// calculate expanded width of current element
		int width = right - left - 1;

		// now muliply current element * width (expanded width)
		int max = width * arr[i];
		if (maxArea < max) {
			maxArea = max;
		}
	}
	cout << "Maximum Area of Histogram : " << maxArea << endl;
}


/*
2. Approach :-
----------
this problem is depends on two subproblem of finding nearest smallerst number
in right and left side, then calculate width
width = right[i]-left[i]-i
i will create a maxArea variable which will store the maximum area of ractangle/histogram.
max = arr[i]*width

if(max>maxArea){
	maxArea = max;
}

				// left smallerst + right smallerst + histogram function
Time complexity :- O(N) + O(N) + O(N)
				= O(3N) = O(N)
				// left smallerst + right smallerst + histogram function
				// for creating vector and stack of pairs
Space complexity :- O(N) + O(N) + O(N)
					= O(3N) = O(N)

So overall summary is :
Time complexity : O(N)
Space complexity : O(N)

*/
vector<int> nearestSmallerToRight(vector<int>arr, int n) {
	// stack<val, index>
	stack<pair<int, int>>s;
	vector<int>v;
	for (int i = n - 1; i >= 0; i--) {

		if (s.empty()) {
			v.push_back(n);
		}
		else if (s.top().first >= arr[i]) {
			// pop the pair from stack
			while (s.size() != 0 and s.top().first >= arr[i]) {
				s.pop();
			}

			// now there can be two conditions
			// 1. stack can be empty
			// 2. otherwise stack.top().first< arr[i]
			if (s.empty()) {
				v.push_back(n);
			}
			else {
				v.push_back(s.top().second);
			}
		}
		else if (s.top().first < arr[i]) {
			v.push_back(s.top().second);
		}
		s.push(make_pair(arr[i], i));
	}

	reverse(v.begin(), v.end());
	return v;
}

vector<int> nearestSmallerToLeft(vector<int>arr, int n) {
	stack<pair<int, int>>s;
	vector<int>v;
	for (int i = 0; i < n; i++) {

		if (s.empty()) {
			v.push_back(-1);
		}
		else if (s.top().first >= arr[i]) {
			// pop the pair from stack
			while (s.size() != 0 and s.top().first >= arr[i]) {
				s.pop();
			}

			// now there can be two conditions
			// 1. stack can be empty
			// 2. otherwise stack.top().first< arr[i]
			if (s.empty()) {
				v.push_back(-1);
			}
			else {
				v.push_back(s.top().second);
			}
		}
		else if (s.top().first < arr[i]) {
			v.push_back(s.top().second);
		}
		s.push(make_pair(arr[i], i));
	}

	return v;
}


void printVector(vector<int>v) {
	for (int x : v)
		cout << x << ", ";
	cout << endl;
}
void maxAreaOfHistogram(vector<int>arr, int n) {
	vector<int>left = nearestSmallerToLeft(arr, n);
	vector<int>right = nearestSmallerToRight(arr, n);

	cout << "Original Array : " << endl;
	printVector(arr);
	cout << "Right nearest smallest element index : " << endl;
	printVector(right);
	cout << "Left nearest smallest element index : " << endl;
	printVector(left);

	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		int width = right[i] - left[i] - 1;
		int max = arr[i] * width;

		if (max > maxArea) {
			maxArea = max;
		}
	}

	cout << "Maximum Area of Histogram : " << maxArea << endl;
}


int main() {
	int n;
	cin >> n;

	vector<int>arr;

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	findMaxAreaOfHistogram(arr, n);
	return 0;
}

/*
Input :-
-----------
7
6 2 5 4 5 1 6

Approach-1 Output :-
-------------------
Maximum Area of Histogram : 12

Approach-2 Output :-
-------------------
Original Array :
6, 2, 5, 4, 5, 1, 6,
Right nearest smallest element index :
1, 5, 3, 5, 5, 7, 7,
Left nearest smallest element index :
-1, -1, 1, 1, 3, -1, 5,
Maximum Area of Histogram : 12

*/