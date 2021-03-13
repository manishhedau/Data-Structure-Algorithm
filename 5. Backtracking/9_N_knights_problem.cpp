// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

int totalPaths = 0;

bool isValid(int currRow, int currCol, int n) {
	// cout << "Inside the validation function" << endl;
	return currRow >= 0 && currRow < n && currCol >= 0 && currCol < n;
}
bool isItSafe(vector<vector<int>>&grid, int n, int currRow, int currCol) {
	// check in all 8 direction that knight are attacking to each other
	// if they are attacking then return false means we can't place knight on that position
	// all the eight direction from the any position
	int xdir[8] = { -2, -2, -1, -1, 2, 2, 1, 1};
	int ydir[8] = {1, -1, 2, -2, 1, -1, 2, -2};
	//cout << "Inside this function1" << endl;
	for (int i = 0; i < 4; i++) {
		int a = xdir[i];
		int b = ydir[i];
		//cout << "function shoudl return : " << i << endl;
		if (isValid(currRow + a, currCol + b, n)) {
			// we have found a knight that can attack to current knight so that can't place knight
			// in this position
			//cout << "Inside the if statement" << endl;
			if ((grid[currRow + a][currCol + b] == 1))
				return false;
		}
	}
	// if we are safe from all the 8 directions
	//cout << "Inside this function2" << endl;

	return true;
}

void display(vector<vector<int>>&grid, int n) {
	// print the grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				cout << "K" << " ";
			}
			else {
				cout << "_" << " ";
			}
		}
		cout << endl;
	}
}
void placeKnight(vector<vector<int>>&grid, int n, int currRow, int currCol, int count) {
	// base case
	if (count ==  n) {
		// we have all the knight in every row
		totalPaths++;
		display(grid, n);
		cout << endl << endl;
		return;
	}

	// try to every row that we are able to place all the knight
	// cout << "It is not safe" << endl;
	for (int i = currRow; i < n; i++) {
		for (int j = (i == currRow) ? currCol : 0; j < n; j++) {
			if (isItSafe(grid, n, currRow, i)) {
				// it is safe then
				// cout << "It is safe" << endl;
				grid[i][j] = 1;
				placeKnight(grid, n, i, j + 1, count + 1);
				grid[i][j] = 0;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>>grid(n, vector<int>(n, 0));

	placeKnight(grid, n, 0, 0, 0);
	cout << "Total paths : " << totalPaths << endl;
	return 0;
}

/*
Input :-
--------
2

Output :-
---------
K K
_ _


K _
K _


K _
_ K


_ K
K _


_ K
_ K


_ _
K K


Total paths : 6
*/