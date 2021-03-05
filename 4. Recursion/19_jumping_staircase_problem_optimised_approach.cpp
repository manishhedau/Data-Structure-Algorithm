// Hackerrank problem - Recursion: Davis' Staircase
// visit this question for more details

/*
Input :-
s 
s time value of N

Note :- N denote the hight of Staircase
Output :-
for every value of N calculate the no of ways to reach N by using (1, 2, 3) jumps
*/

#include <iostream>
using namespace std;

// 1. Approach 
// Calculate no of ways for every value of N.
// Time complexity => Best case - O(N), worse case - O(N)
// Space complexity - O(1) or constants
int printWays(int n){
    // base case
    if(n==0 || n==1) return 1;
    if(n<0) return 0;

    int res = printWays(n-1) + printWays(n-2) + printWays(n-3);
    return res
}

// 2. Approach
// time complexity 
// best case - O(1)
// Worse case - O(N)
// Space complexity - constant if in this problem constrainst is given 
// for storing the value in array so that we again we have this value of N , we will not need to perform calculation for the same N value
// hasing key-> N , value -> no. of way of reaching N.
int res[100] = {0};
int printWays(int n){
    // base case
    if(n == 0 || n == 1) {
        return 1;
    }
    if(n<0) return 0;
    if(n==2) return 2;
    if(n==3) return 4;

    // dp
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    res[3] = 4;

    // recursive part
    if(res[n]==0){
        res[n] = printWays(n-1) + printWays(n-2) + printWays(n-3);
    }
    return res[n];
}
int main() {
    int s;
    cin>>s;

    for(int i = 0; i<s; i++){
        int n;
        cin>>n;

        cout<<printWays(n)<<endl;
    }
}


/*
Input :-
3
1 3 7
Output :-
1
4
44
*/