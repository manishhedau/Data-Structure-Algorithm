// Rotate the 2d array / Rotate image problem
// give an 2d array we have to rotate it

/*
Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13
Explanation
Rotate the array 90 degrees anticlockwise.
*/

#include<iostream>
#include<algorithm>
using namespace std;


void rotate_image(int arr[][1001], int n)
{

    // reverse the every row
    for (int i = 0; i < n; i++)
    {
        reverse(arr[i], arr[i] + n);
    }

    // make an triangle and swap every values
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    // print the result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;


    int arr[1001][1001];

    // taking the 2d array values an input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    rotate_image(arr, n);
}


/*
OUTPUT :-

4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

rotate image :-

4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13
*/
