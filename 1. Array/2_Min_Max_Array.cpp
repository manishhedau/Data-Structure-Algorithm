// Find the minimum and maximum value from the array
/*
Input :-
5
1 2 3 4 5

Output :-
Minimum = 1
Maximum = 5

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


    int Max = arr[n-1];
    int Min = arr[0];

    for(int i = 0; i<n; i++)
    {
        if(arr[i]>Max)
        {
            Max = arr[i];
        }

        if(arr[i]<Min)
        {
            Min = arr[i];
        }
    }

    // Printing Max and min value
    cout<<"Minimum : "<<Min<<endl;
    cout<<"Maximum : "<<Max<<endl;
    return 0;
}

/*
OUTPUT :-
5
30 20 10 50 40
Minimum : 10
Maximum : 50
*/
