#include<iostream>
using namespace std;
/*
Input :-
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/

// 1 5 9 13 2 6 10 14 3 7 11 15 4 8 12 16 END

void wave_print(int arr[][100], int n)
{

    cout<<"Wave printing "<<endl;
    for(int row = 0; row<n; row++)
    {
        if(row%2==0)
        {
            for(int i = 0; i<n; i++)
            {
                cout<<arr[i][row]<<", ";
            }
        }
        else
        {
            for(int i = n-1; i>=0; i--)
            {
                cout<<arr[i][row]<<", ";
            }
        }
    }

    cout<<"END"<<endl;
}
int main()
{
    int n;
    cin>>n;

    int arr[100][100];

    int val = 0;
    for(int row=0;row<n; row++)
    {
        for(int col = 0; col<n; col++)
        {
            arr[row][col] = val;
            val++;
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    wave_print(arr,n);
    return 0;
}

/*
5
0 1 2 3 4
5 6 7 8 9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24

Wave printing
0, 5, 10, 15, 20, 21, 16, 11, 6, 1, 2, 7, 12, 17, 22, 23, 18, 13, 8, 3, 4, 9, 14, 19, 24, END
*/
