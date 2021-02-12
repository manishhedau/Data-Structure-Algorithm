// Given an sorted 2D array find the key in matrix

/*
Input :- 
4 4 --> row, col
1 2 3 4
5 6 7 8
9 10 11 12   --> 2d Arrays values
13 14 15 16
15 ---> key

Output:-
15 value in index 3, 2
*/

#include <iostream>
using namespace std;

void Matrix_search(int arr[][1001], int n, int m, int key)
{
    int row = 0;
    int col = m-1;
    while(row<=n-1 && col>=0)
    {
	// If curr val == key , print
        if(arr[row][col]==key)
        {
            cout<<arr[row][col]<<" value in index "<<row<<", "<<col<<endl;
            break;
        }
        else if(arr[row][col]<key)  // if curr val is < key , increment row
        {
            row++;
        }
        else // if curr val is > key , decrement col
        {
            col--;
        }
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
    Matrix_search(arr, n ,m, key);
}
/*
OUTPUT :-
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
15
15 value in index 3, 2
*/