// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;
#define vec vector<vector<int>>


void display(vec &arr, vec &visited, int n) {
	// print the grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 1)
				cout << arr[i][j] << " -> ";
		}
	}
	cout << endl;
}

bool check(vec &arr, vec &visited, int n, int k, int row, int col) {
	return row < n and col<n and visited[row][col] == 0 and k >= 0;
}
void findPath(vec &arr, vec &visited, int n, int k, int row, int col) {
	// base case
	if ((row == n - 1 and col == n - 1) and k == 0) {
		visited[row][col] = 1;
		display(arr, visited, n);
		visited[row][col] = 0;
		return;
	}


	if (row >= n or col >= n) {
		return;
	}
	// recursive assumption

	// right
	if (check(arr, visited, n, k - arr[row][col + 1], row, col + 1)) {
		visited[row][col + 1] = 1;
		findPath(arr, visited, n, k - arr[row][col + 1], row, col + 1);
		visited[row][col + 1] = 0;
	}

	// down
	if (check(arr, visited, n, k - arr[row + 1][col], row + 1, col)) {
		visited[row + 1][col] = 1;
		findPath(arr, visited, n, k - arr[row + 1][col], row + 1, col);
		visited[row + 1][col] = 0;
	}


	// self work
}
int main() {

	int n;
	cin >> n;

	vec arr(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int k;
	cin >> k;
	vec visited(n, vector<int>(n, 0));

	visited[0][0] = 1;
	findPath(arr, visited, n, k - arr[0][0], 0, 0);
	return 0;
}

/*
Output :-
---------
3 --> size of row and col
1 2 3   -> 2d array value
4 6 5
3 2 1

12 -->k value


1 -> 2 -> 3 -> 5 -> 1 ->
1 -> 2 -> 6 -> 2 -> 1 ->
*/