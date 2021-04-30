// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

/*
1. Approach :-
------------
Count number of zero, and one present in array.
by traversing over the array once.

now fill array :-
1. fill array first with number of counted zero.
2. fill array with number of counted one's.

Time complexity :- O(N) + O(N) // counting + placing(filling)
				 = O(2N) ~= O(N)
Space complexity :- O(1) // filling number of zero, one's in original array.
*/

/*
2. Approach :-
--------------
Two pointer technique for solving this problem.
0 to low -->contain 0(zero)
n-1 to high --> contain 1(one)

iterate over the array low<=high
	1. check low index has already 0, increment low.
	2. check high index has already 1, decrement high.
	3. check low == 1 and high == 0, swap both and increment low, decrement high.
	4. check high == 0, swap both and increment low.
	5. check low == 1, swap both and decrement high.
Now the array is sorted...
Time complexity - O(N) // just one traversal
Space complexity - O(1) // inplace sort algorithm
*/

void sortArray(int *arr, int n) {
	// two pointer low, high
	int low = 0, high = n - 1;

	while (low <= high) {
		// check low index has already 0
		if (arr[low] == 0) {
			low++;
		}

		// check high index has already 1
		if (arr[high] == 1) {
			high--;
		}

		// when low == 1 and high == 0, swap, increament low++, decrement high--
		if (arr[low] == 1 and arr[high] == 0) {
			swap(arr[low++], arr[high--]);
		}
		else if (arr[high] == 0) {
			// when high == 0, swap, increment low++
			swap(arr[high], arr[low++]);
		}
		else if (arr[low] == 1) {
			// when low == 1, swap, decrement high--
			swap(arr[low], arr[high--]);
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
	cout << "Sorted Array is : " << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}

/*
Input :-
---------
8
0 0 1 1 0 0 1 1

Output :-
---------
Sorted Array is :
0, 0, 0, 0, 1, 1, 1, 1,

*/