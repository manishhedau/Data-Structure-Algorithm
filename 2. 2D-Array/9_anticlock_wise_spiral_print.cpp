// Given N*M matrix print the value in anticlock sprial wise
/*
Input :-
5 3  -- > row, col
1 2 3
4 5 6
7 8 9   --> array values
10 11 12
13 14 15

Output :-
1, 4, 7, 10, 13, 14, 15, 12, 9, 6, 3, 2, 5, 8, 11, END
*/


#include <iostream>
using namespace std;

// Sample output :-
// 11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
void anticlock_spiral_print(int arr[][1001], int n, int m)
{
    int startRow = 0;
    int endRow = n-1;
    int startCol = 0;
    int endCol = m-1;

    while(startRow<=endRow && startCol<=endCol)
    {
        // First column
        for(int i = startRow; i<=endRow; i++)
        {
            cout<<arr[i][startCol]<<", ";
        }
        startCol++;

        // Bottom row 
        if(startRow<endRow){
            for(int i = startCol; i<=endCol; i++)
            {
                cout<<arr[endRow][i]<<", ";
            }
            endRow--;
        }

        // curr last column
        if(startCol<endCol){
            for(int i = endRow; i>=startRow; i--)
            {
                cout<<arr[i][endCol]<<", ";
            }
            endCol--;
        }
        // curr top row
        for(int i = endCol; i>=startCol; i--)
        {
            cout<<arr[startRow][i]<<", ";
        }
        startRow++;
    }
    cout<<"END"<<endl;
}
int main() {
    int n, m;
    cin>>n>>m;

    int arr[1001][1001] = {0};

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    anticlock_spiral_print(arr, n,m);
    return 0;
}

/*
OUTPUT:-
5 3
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15

1, 4, 7, 10, 13, 14, 15, 12, 9, 6, 3, 2, 5, 8, 11, END
*/
