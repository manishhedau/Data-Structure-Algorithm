// Sudoku problem

#include<bits/stdc++.h>
using namespace std;

// Approach
/*
We don't know which element to place in which position so what we will do,
we try for every element range 1 to N(9) ,
By placing element our function will be able to solve the whole problem or not.
If able to solve then return true and try for another position
or false to parents function and try for different element.
*/

/*
Time complexity - O(9^(N*N))
Space complexity - O(N*N) to store the matrix
*/
bool isValid(int mat[9][9], int n, int i, int j, int num) {

	// checking in row that num  is present
	for (int col = 0; col < n; col++) {
		if (mat[i][col] == num) {
			return false;
		}
	}

	// checking in col that num  is present
	for (int row = 0; row < n; row++) {
		if (mat[row][j] == num) {
			return false;
		}
	}

	// now checking in grid that num  is present
	int sx = i - (i % 3);
	int sy = j - (j % 3);

	// Time complexity of this part is - O(N)
	// Because to check num is present in grid or not
	// we only need 9 iterations
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			if (mat[i][j] == num) {
				return false;
			}
		}
	}

	// return true when num are present in row, column and grid.
	return true;
}
bool solveSudoku(int mat[9][9], int n, int i, int j) {
	// base case

	if (i == n) {
		// print the sucessfully filled matrix
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	// when j == n means we have to shift to new row
	if (j == n) {
		return solveSudoku(mat, n, i + 1, 0);
	}

	// if i and j position we didn't find '0' then try function for j+1 position
	if (mat[i][j] != 0)
		return solveSudoku(mat, n, i, j + 1);

	// try to place 1 to  9 at every blank position (means 0 position)
	// then try to solve the whole matrix
	// if not able to solve or not able to place any element 1-9 then return
	// false to parent function, and parent function try different value
	// this cycle will run unto base condition will not true.
	for (int num = 1; num <= 9; num++) {
		if (isValid(mat, n, i, j, num)) {
			mat[i][j] = num;
			// try for every j+1 position that try to solve for all i and j+1 to base case
			if (solveSudoku(mat, n, i, j + 1))
				return true;
		}
		// not able to place element then try for another value of num.
		mat[i][j] = 0;
	}
	// not able to place any element 1-9 then return false to parent function
	return false;
}
int main() {
	int mat[9][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	int n = 9;

	if (solveSudoku(mat, n, 0, 0))
		cout << "Can solve sudoku" << endl;
	return 0;
}

/*
Output :-
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
Can solve sudoku
*/