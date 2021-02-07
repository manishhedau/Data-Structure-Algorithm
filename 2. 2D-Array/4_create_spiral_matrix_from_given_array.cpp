// Create the given Matrix from spiral array
/*
Input :-
5 3 -->row, col
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

output:
1 2 3
12 13 4
11 14 5
10 15 6
9 8 7

*/

#include<iostream>
using namespace std;
void sprial_print(int arr[][100], int n, int m, int number[])
{


    int start_row = 0;
    int end_row = n-1;
    int start_col = 0;
    int end_col = m-1;

    // for number array index
    int index = 0;
    while(start_row<=end_row && start_col<=end_col)
    {
        // printting first riw
        for(int i = start_col; i<=end_col; i++)
        {
            arr[start_row][i] = number[index];
            index++;
            //cout<<arr[start_col][i]<<" ";
        }
        start_row++;

        // printing last col

        for(int i = start_row; i<=end_row; i++)
        {
            arr[i][end_col] = number[index];
            index++;
            //cout<<arr[i][end_col]<<" ";
        }
        end_col--;

        // bottom row
        if(end_row>start_row){
            for(int i = end_col; i>=start_col; i--)
            {
                arr[end_row][i] = number[index];
                index++;
                //cout<<arr[end_row][i]<<" ";
            }
            end_row--;
        }
        // first col
        if(end_col>start_col){
            for(int i = end_row; i>=start_row; i--)
            {
                arr[i][start_col] = number[index];
                //cout<<arr[i][start_col]<<" ";
                index++;
            }
            start_col++;
        }
    }

}
int main()
{
    int n,m;
    cin>>n>>m;

    int number[n*m] = {0};

    for(int i = 0; i<n*m; i++)
    {
        cin>>number[i];
    }

    int arr[100][100] = {0};
    sprial_print(arr,n, m, number);

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
5 3
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15


1 2 3
12 13 4
11 14 5
10 15 6
9 8 7
*/
