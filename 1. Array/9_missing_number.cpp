// Find the missing number in a sequence of number.
/*
Input :-
5 --> array length
1 2 4 5 6 --> array values

Output :-
3 (Because 3 is missing in the sequence of series)
*/

#include<iostream>
using namespace std;

// 1. approach Time - 0(N), Space - 0(1)
int getMissingNo_1(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];

    // For xor of all the elements from 1 to n+1
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];

    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}


// 2. Approach Time - 0(N), Space - 0(1)
int getMissingNo_2(int arr[], int n)
{
    int total = (n*(n+1))/2;

    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += arr[i];
    }
    return abs(total - sum);
}
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<getMissingNo_2(arr, n);
}


/*
OUTPUT :-
5
1 2 4 5 6
3
*/
