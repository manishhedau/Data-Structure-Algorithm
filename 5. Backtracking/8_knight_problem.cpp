// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


// Aprroach -
// Time complexity - O(8^N) because we can move in 8 direction
// But the tight bound will be O(7^N) because from the every position we can not move 8 direction
// we can only move only 7 directions
// Space Complexity - O(N*N)
int totalPaths = 0;
// function for printing the grid
void display(vector<vector<int>>&grid, int n) {
	// printing the grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
// function for checking that in which position we are placing the count value is valid or not
bool isValid(vector<vector<int>>&grid, vector<vector<int>>&visited, int n, int currRow,
             int currCol) {
	return currRow >= 0 && currRow < n && currCol >= 0 && currCol < n && visited[currRow][currCol] == 0 && grid[currRow][currCol] == 0;
}

// function will recursivly try to place all the knight at there own place by validting there positions
void knight_solve(vector<vector<int>>&grid, vector<vector<int>>&visited, int n, int currRow,
                  int currCol, int count) {
	// base case
	if (count == n * n - 1) {
		// we have place n*n knight successfully
		grid[currRow][currCol] = count;
		display(grid, n);
		cout << endl << endl;
		grid[currRow][currCol] = 0;
		totalPaths++;
		return;
	}


	if (count >= n * n) {
		return;
	}

	// all the eight direction from the any position
	int xdir[8] = { -2, -2, -1, -1, 2, 2, 1, 1};
	int ydir[8] = {1, -1, 2, -2, 1, -1, 2, -2};

	// first we don't know where to place Knight
	// so what i can say first place the knight at start place
	// and call function for place all the knight in board
	visited[currRow][currCol] = 1;
	grid[currRow][currCol] = count;
	for (int i = 0; i < 8; i++) {
		int a = currRow + xdir[i];
		int b = currCol + ydir[i];
		// this function validate the all the 8 direction that recursive function has not visited the this places
		if (isValid(grid, visited, n, currRow + xdir[i], currCol + ydir[i])) {
			knight_solve(grid, visited, n, currRow + xdir[i], currCol + ydir[i], count + 1);
		}
	}
	// Backtracking
	grid[currRow][currCol] = 0;
	visited[currRow][currCol] = 0;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>>grid(n, vector<int>(n, 0));
	vector<vector<int>>visited(n, vector<int>(n, 0));

	knight_solve(grid, visited, n, 0, 0, 0);
	cout << "Total Paths : " << totalPaths << endl;
	return 0;
}