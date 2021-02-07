// Given an spiral matrix shift all element by 1.
/*
Input :-
4 4 -->row, col
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7



output:
after shifting all element by 1
16 1 2 3
11 12 13 4
10 15 14 5
9 8 7 6

*/

#include<iostream>
using namespace std;
void sprial_print(int arr[][100], int n, int m)
{


    int start_row = 0;
    int end_row = n-1;
    int start_col = 0;
    int end_col = m-1;

    // for number array index
    int temp = arr[0][0];
    int next = 0;
    while(start_row<=end_row && start_col<=end_col)
    {
        // printting first riw
        if(start_col==0)
        {
            for(int i = start_col+1; i<=end_col; i++)
            {
                next = arr[start_row][i];
                arr[start_row][i] = temp;
                temp = next;
            }
            start_row++;

        }
        else
        {
            for(int i = start_col; i<=end_col; i++)
            {
                next = arr[start_row][i];
                arr[start_row][i] = temp;
                temp = next;
            }
            start_row++;
        }

        // printing last col

        for(int i = start_row; i<=end_row; i++)
        {
            next = arr[i][end_col];
            arr[i][end_col] = temp;
            temp = next;
        }
        end_col--;

        // bottom row
        if(end_row>start_row){
            for(int i = end_col; i>=start_col; i--)
            {
                next = arr[end_row][i];
                arr[end_row][i] = temp;
                temp = next;
            }
            end_row--;
        }
        // first col
        if(end_col>start_col){
            for(int i = end_row; i>=start_row; i--)
            {
                next = arr[i][start_col];
                arr[i][start_col] = temp;
                temp = next;
            }
            start_col++;
        }
    }
    arr[0][0] = temp;
}
int main()
{
    int n,m;
    cin>>n>>m;

    int arr[100][100] = {0};
    for(int row=0;row<n; row++)
    {
        for(int col = 0; col<m; col++)
        {
            cin>>arr[row][col];
        }
    }

    sprial_print(arr,n, m);
    cout<<"after shifting all element by 1"<<endl;
    for(int row=0;row<n; row++)
    {
        for(int col = 0; col<m; col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*
OUTPUT :-
4 4
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7

after shifting all element by 1

16 1 2 3
11 12 13 4
10 15 14 5
9 8 7 6
*/
