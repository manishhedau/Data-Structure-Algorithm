// Given an N size array, Print all the values upto N using Recursion.
/*
Input :-
5
10 20 30 40 50

Output:-
10 20 30 40 50
*/
#include<iostream>
using namespace std;

void printArrayValues(int *arr, int n){
    if(n<=0){
        return;
    }
    printArrayValues(arr, n-1);
    cout<<arr[n-1]<<" ";
}
int main(){
    int n;
    cin>>n;

    int arr[n] = {0};

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The array values are : "<<endl;
    printArrayValues(arr, n);
    return 0;
}

/*
Input :-
5
10 20 30 40 50
Output :-
The array values are : 
10 20 30 40 50 
*/