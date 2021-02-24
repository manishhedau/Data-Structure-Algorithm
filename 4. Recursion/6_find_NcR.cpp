// Given two number N, R. Find the combination NcR
// To find NcR
// Formula is :-
// NcR = N!/R!(N-R)!

/*
Basic Properties:-
******************
1. N==R , Answer = 1;
2. R=0 , Answer = 1;
3. R==1, Answer = N;
*/
#include<iostream>
using namespace std;

int findNCR(int n, int r){
    // Base cases
    if(n==r) return 1;
    if(r==1) return n;
    if(r==0) return 1;
    // recursive assumption
    int num = findNCR(n-1, r-1);
    // self work
    return (n*num)/r;
}

int main(){
    int n, r;
    cin>>n>>r;

    cout<<"The combination is : "<<findNCR(n, r);
    return 0;
}

/*
Input :-
10 3
Output :-
The combination is : 120
*/