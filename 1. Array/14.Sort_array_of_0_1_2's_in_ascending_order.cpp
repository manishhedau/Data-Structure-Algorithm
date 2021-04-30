// Sort Array of 0, 1, 2's
// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


/* 1. Approach :-
--------------------
We have given array which contain 0, 1, 2's and we have to sort in ascending order.
So what i am going to do is that,
create three variable counZero, countOne, countTwo.
these three variable maintain count of 1, 2, 3 in array

1. iterate over the array
	count number of zero, one, two.

2. now iterate over the array again.
	I) place first number of counted zero in array.
	II) next place number of counted one in array.
	III) next place number of counted two in array.

Now array is sorted...
Time complexity -  O(N)// for count number of 0, 1, 2 //
					+ O(N) // for placing number of 0, 1, 2 //
				= O(2N) --> ~= O(N)
Space complexity - O(1)
*/

/* 2. Approach :-
--------------------
we use three pointer to solve this problem....
low, mid, high
low, mid --> point to start index of array(after sorting 0 always at begining of array)
high --> points to end index of array(after sorting 2 always at end of array)
and 1's are in middle...

We use an algorithm - "find an algo"

iterate over the array upto 'mid<=high'
1) when mid index == 0, swap(arr[mid], arr[low]) and increment mid++, low++.
2) when mid index == 2, swap(arr[high], arr[mid]) and decrement high--.
3) when mid index = 1, just increment mid++.

Time complexity - O(N) // for one traversal
Space complexity - O(1) // inplace sort
*/
void sortArray(int *arr, int n) {
	// three pointer
	int mid = 0;
	int low = 0;
	int high = n - 1;

	while (mid <= high) {
		// for 0 in at arr[mid]
		if (arr[mid] == 0) {
			swap(arr[mid++], arr[low++]);
		} // for 2 at arr[mid]
		else if (arr[mid] == 2) {
			swap(arr[high--], arr[mid] );
		}
		else {
			// for 1 at arr[mid]
			mid++;
		}
	}
}

int main() {
	int n;
	cin >> n;

	int arr[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sortArray(arr, n);
	// now print the sorted array
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}

/*
Input :-
-----------
10
0 0 1 2 1 2 0 0 1 1

Output :-
-----------
0, 0, 0, 0, 1, 1, 1, 1, 2, 2,

*/