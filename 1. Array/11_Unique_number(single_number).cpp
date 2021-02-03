// Unique Number / Single Number
// And array has all element which occurs twice except One element and that would be unique number.
/*
Input :-
5
1 2 3 2 1

Output :
3
*/


// 1 Approach Time - 0(N), Space - 0(N)
// using hash-map we can implement this approach and check which key value is 1
// if any particular key value is 1 then that would be your Unique number

// 2 Approach Time - 0(N), Space - 0(1)
// using Bit-masking (XOR)

#include<iostream>
using namespace std;

void printUniqueNumber(int arr[], int n)
{
    int unique_number = 0;

    for(int i = 0; i<n; i++)
    {
        unique_number ^= arr[i];
    }

    cout<<"The unique number is : "<<unique_number<<endl;
}

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    printUniqueNumber(arr, n);
    return 0;
}

/*
OUTPUT :-
5
1 2 3 2 1
The unique number is : 3

*/
