// Sum of all array elements
/*
Input :-
5
1 2 3 4 5

Output :-
15

*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n] ={0};

    // taking values of the array index's
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }


    int sum = 0;

    for(int i = 0; i<n; i++)
    {
        sum += arr[i];
    }

    // sum of all array element
    cout<<sum<<endl;
    return 0;
}

/*
OUTPUT :-

5
10 2 4 6 3
25
*/
