/*
Change all elements of row i and column j in a matrix to 0 if cell (i, j) has value 0
*/
/*
Input:-
5 5
1 1 0 1 1
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
0 1 1 1 1

Output :-
0 0 0 0 0
0 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 0 0 0 0
*/
#include<iostream>
using namespace std;
int row, col;

// 1 Approach Space - 0(row*col) Same solution in brute force way
// making one extra 2D array with same value and while performing operation instead of making changes in original array
// make changes in extra 2D array and that array would contain the output


// 2 Approach Space - 0(1)
// Approach is same but without using extra 2D array
// converting row x and col y 1 to -1 (istead of -1 we can take any other value but not 0)
void change_row_col(int arr[][100], int x, int y)
{
    // converting all 1 to -1 in row
    for (int j = 0; j < col; j++)
    {
        if (arr[x][j] != 0)
        {
            arr[x][j] = -1;
        }
    }

    // converting all 1 to -1 in col
    for (int j = 0; j < row; j++) {
        if (arr[j][y] != 0)
        {
            arr[j][y] = -1;
        }
    }
}
void convert(int arr[][100])
{
    // finding 0 in matrix and changing row and col
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
                change_row_col(arr, i, j);
        }
    }

    // inverting -1 to 0 in matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }

}


void print_matrix(int arr[][100])
{
    // printing all the matrix

    cout << "Printing Matrix" << endl << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    cin >> row >> col;

    int arr[100][100];

    for (int i  = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    convert(arr);
    print_matrix(arr);
    return 0;
}


/*
Output:-
5 5
1 1 0 1 1
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
0 1 1 1 1
Printing Matrix

0 0 0 0 0
0 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 0 0 0 0
*/
