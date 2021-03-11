#include<bits/stdc++.h>
using namespace std;

int totalPaths = 0;

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
bool placeNQueen(vector<vector<bool>> &grid, int currRow, int n) {
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
		return true;
	}

	// check for every row that we are able to place queen or not
	for (int i = 0; i < n; i++) {
		// is it safe to place queen then we place
		if (isItSafe(grid, currRow, i, n)) {
			grid[currRow][i] = true;
			if (placeNQueen(grid, currRow + 1, n))
				return true;
			// we are able to place all the queen then undo all the changes
		}
		grid[currRow][i] = false;
	}

	return false;
}
int main() {
	int n;
	cin >> n;

	vector<vector<bool>> grid(n, vector<bool>(n, 0));

	if (placeNQueen(grid, 0, n))
		cout << "Can able to place a queen" << endl;
	else
		cout << "Not able to place a queen" << endl;

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

Can able to place a queen
Total Paths : 2

*/