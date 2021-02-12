// Given an 2D Image rotate it by 180 degree.

/*
Input :- 
4 4 --> row, col
1 2 3 4
5 6 7 8
9 10 11 12   --> 2d Arrays values
13 14 15 16


Output:-
180 degree rotated image is : 
16 15 14 13 
12 11 10 9 
8 7 6 5 
4 3 2 1 
*/

#include <iostream>
using namespace std;

void reverse_row(int arr[][1001], int n, int m)
{
    for(int i = 0; i<n; i++)
    {
        int start_col = 0;
        int end_col = m-1;

        while(start_col<end_col)
        {
            swap(arr[i][start_col], arr[i][end_col]);
            start_col++;
            end_col--;
        }
    }
}


void reverse_col(int arr[][1001], int n, int m)
{
    for(int i = 0; i<m; i++)
    {
        int start_row = 0;
        int end_row = n-1;

        while(start_row<end_row)
        {
            swap(arr[start_row][i], arr[end_row][i]);
            start_row++;
            end_row--;
        }
    }
}

void print_matrix(int arr[][1001], int n, int m)
{
    cout<<"180 degree rotated image is : "<<endl;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n,m;
    cin>>n>>m;

    int arr[1001][1001];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cin>>arr[i][j];
    }

    int key;
    cin>>key;
    reverse_row(arr, n,m);
    reverse_col(arr, n, m);
    print_matrix(arr, n,m);
}

/*
 4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

180 degree rotated image is : 
16 15 14 13 
12 11 10 9 
8 7 6 5 
4 3 2 1 
*/