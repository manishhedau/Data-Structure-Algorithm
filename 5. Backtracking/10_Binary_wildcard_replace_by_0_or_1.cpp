// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

// Approach -
// Time Complexity - O(2^(N*N))
// Space complexity - O(N) for storing the string
char mapping[2] = {'0', '1'};
void Solve_binary_string(char *arr, int i) {
	// base case

	if (arr[i] == '\0')
	{
		cout << arr << endl;
		return;
	}

	// if the current character is `?`
	if (arr[i] == '?')
	{
		for (int k = 0; k < 2; k++)
		{
			// replace `?` with 0 and 1
			arr[i] = mapping[k];

			// recur for the remaining pattern
			Solve_binary_string(arr, i + 1);

			// backtrack (As the array is passed by reference to the function)
			arr[i] = '?';
		}
		return;
	}

	// if the current character is 0 or 1, ignore it and
	// recur for the remaining pattern
	Solve_binary_string(arr, i + 1);
}
int main() {
	char arr[100];
	cin >> arr;

	int len = strlen(arr);
	Solve_binary_string(arr, 0);
	// cout << 0 + '0' << endl;
	// cout << 1 + '1' << endl;
	return 0;
}

/*
Input :-
--------
1?11?00?1?

Output :-
---------
1011000010
1011000011
1011000110
1011000111
1011100010
1011100011
1011100110
1011100111
1111000010
1111000011
1111000110
1111000111
1111100010
1111100011
1111100110
1111100111

*/