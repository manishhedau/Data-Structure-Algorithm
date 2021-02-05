// Find the number of element are smaller then the every current element in array

/*
Input :-
5
2 1 3 6 5

Output :-
1, 0, 2, 4, 3,
*/

#include<iostream>
using namespace std;


void find_smaller_array(int arr[], int n)
{
    int temp[n];

    for(int i = 0; i<n; i++)
    {
        int cnt = 0;
        for(int j = 0; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                cnt++;
            }
        }

        temp[i] = cnt;
    }

    for(int i = 0; i<n; i++)
    {
        cout<<temp[i]<<", ";
    }
}
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    find_smaller_array(arr, n);

    return 0;
}


/*

OUTPUT :-
5
2 1 3 6 5
1, 0, 2, 4, 3,
*/
