// Given an array calculate the sum of array
/*
Input details :-
N denote the size of a array
Example :-
Input :- N = 5 
         arr =   [10, 20, 30, 40, 50]
Output :- 150

Input :- N = 1
         arr = [20]
Output :- 20
*/ 

#include <iostream>
using namespace std;

int Sum_of_n_number(int *arr, int n)
{
    // Base case
    if(n==0)
        return arr[n];

    // Self Work
    int currNum = arr[n];
    // Recursive Assumption
    return currNum + Sum_of_n_number(arr, n-1);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int sum = Sum_of_n_number(arr,n-1);
    cout<<"Sum of array is : "<<sum<<endl;
    return 0;
}


/*
Input
5
10 20 30 40 50
Output
Sum of array is : 150
*/