// N Queen Problem


#include<bits/stdc++.h>
using namespace std;

// Approach-
// Time Complexity - O(N!)
// Space Complexity - O(N*N) for grid

/*
Recursive Assumption:-
--------------------
What i am saying is that just place queen at starting cell,
and recursive function will do automatically work for us(means place N-1).

Base case :-
----------
if we are able to place all the N Queen successfully
means current Row == N .

Self work :-
------------
for every col in a row
we check if this position is safe to place Queen (check by function) ,
then place queen and try to place Queen in next row by using 'Recursive Assumption'.
*/
int totalPaths = 0;

// this function will check that we are able to place Queen at currRow and currCol
bool isItSafe(vector<vector<bool>> &grid, int currRow, int currCol, int n) {
	// check in column
	for (int i = currRow - 1; i >= 0; i--) {
		if (grid[i][currCol] == true) {
			return false;
		}
	}

	// check in left digonal
	for (int i = currRow - 1, j = currCol - 1; i >= 0 and j >= 0; i--, j--) {
		if (grid[i][j] == true) {
			return false;
		}
	}

	// check in right digonal
	for (int i = currRow - 1, j = currCol + 1; i >= 0 and j < n; i--, j++) {
		if (grid[i][j] == true) {
			return false;
		}
	}

	// if we did not found the gueen attacking each other at currRow and curCol then
	// Can be able to place Qeen (means this position is valid to place queen)
	return true;

}
void placeNQueen(vector<vector<bool>> &grid, int currRow, int n) {
	// base case
	if (currRow == n) {
		// we have place all the N queens
		totalPaths++;

		// printing the grid

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == true) {
					cout << "Q" << " ";
				}
				else {
					cout << "_" << " ";
				}
			}
			cout << endl;
		}

		cout << endl;
		return;
	}

	// check for every row that we are able to place queen or not
	for (int i = 0; i < n; i++) {
		// is it safe to place queen then we place
		if (isItSafe(grid, currRow, i, n)) {
			grid[currRow][i] = true;
			placeNQueen(grid, currRow + 1, n);
			// we are able to place all the queen then undo all the changes
			// Backtracking
			grid[currRow][i] = false;
		}
	}
}
int main() {
	int n;
	cin >> n;

	vector<vector<bool>> grid(n, vector<bool>(n, 0));

	placeNQueen(grid, 0, n);
	cout << "Total Paths : " << totalPaths << endl;
	return 0;
}

/*

Input :-
4
Ouptut:-
_ Q _ _
_ _ _ Q
Q _ _ _
_ _ Q _

_ _ Q _
Q _ _ _
_ _ _ Q
_ Q _ _

Total Paths : 2
*/