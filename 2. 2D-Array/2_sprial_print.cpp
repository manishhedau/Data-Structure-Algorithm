// Spiral printing of 2D array
/*
Input :-
5 3 -->row, col

output:
1 2 3
4 5 6
7 8 9   --> 2D array
10 11 12
13 14 15
1, 2, 3, 6, 9, 12, 15, 14, 13, 10, 7, 4, 5, 8, 11, END  (spiral)
*/

#include<iostream>
using namespace std;
void sprial_print(int arr[][100], int n, int m)
{

    int start_row = 0;
    int end_row = n-1;
    int start_col = 0;
    int end_col = m-1;

    while(start_row<=end_row && start_col<=end_col)
    {
        // printting first riw
        for(int i = start_col; i<=end_col; i++)
        {
            cout<<arr[start_row][i]<<", ";
        }
        start_row++;

        // printing last col

        for(int i = start_row; i<=end_row; i++)
        {
            cout<<arr[i][end_col]<<", ";
        }
        end_col--;

        // bottom row
        if(end_row>start_row){
            for(int i = end_col; i>=start_col; i--)
            {
                cout<<arr[end_row][i]<<", ";
            }
            end_row--;
        }
        // first col
        if(end_col>start_col){
            for(int i = end_row; i>=start_row; i--)
            {
                cout<<arr[i][start_col]<<", ";
            }
            start_col++;
        }
    }
    cout<<"END"<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;

    int arr[100][100];

    int val = 1;
    for(int row=0;row<n; row++)
    {
        for(int col = 0; col<m; col++)
        {
            arr[row][col] = val;
            val++;
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    sprial_print(arr,n, m);
    return 0;
}

/*
OUTPUT :-
5 3
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15
1, 2, 3, 6, 9, 12, 15, 14, 13, 10, 7, 4, 5, 8, 11, END
*/
