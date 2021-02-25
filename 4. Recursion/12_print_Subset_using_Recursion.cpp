// Given an N size array print all the subset of array recursively

/*
Input :-
3
1 2 3
Output :-
[1,2,3,]
[1,2,]
[1,3,]
[1,]
[2,3,]
[2,]
[3,]
[]
*/

#include<iostream>
using namespace std;
// 1. Approach
// Find the subset of n-1 element then either you have two choices either to get included or excluded.
// In this solution there is an one problem [1,3] not printed on screen if [1,2,3] is the array
void printSubset1(int *arr, int i, int n){
    // Base case
    if(n==0)
    {
        cout<<"[]"<<endl;
        return;
    }
    // self work
    if(i<n){
        cout<<"[";
        for(int j = i; j<n; j++)
        {
            cout<<arr[j]<<",";
        }
        cout<<"]"<<endl;
        // Recursive Assumption
        printSubset1(arr, i+1, n);
        return;
    }
    else
    {
        // Recursive Assumption
        printSubset1(arr, 0, n-1);
    }
}

// 2. Approach
// The approach of the problem is like every element has two choices either to get included or excluded.
// Based on these strategy we have solved this problem
void printSubset(int *arr, int i, int n, string osf){
    // Base case
    if(i==n){
        cout<<"["<<osf<<"]"<<endl;
        return ;
    }

    // Recursive Assumption
    // Element included 
    printSubset(arr, i+1, n,  osf+to_string(arr[i])+",");
    // Element excluded
    printSubset(arr, i+1, n, osf);
        
}
int main(){
    int n;
    cin>>n;

    int arr[n] = {0};

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    printSubset(arr, 0, n, "");
    return 0;
}

/*
Input :-
3
1 2 3
Output :-
[1,2,3,]
[1,2,]
[1,3,]
[1,]
[2,3,]
[2,]
[3,]
[]
*/