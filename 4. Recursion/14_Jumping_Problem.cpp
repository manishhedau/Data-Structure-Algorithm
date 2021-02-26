// Given an Nth cell which arranged in linear fashion,
// And you are standing at 0th cell & want to reach (N-1)th cell,
// You can have 6 possible ways to reach (N-1)th cell,
// Now you have to print all possible ways to reach.

/*
Input :-
4
Output :-
111
12
21
3
*/
#include<iostream>
using namespace std;


// The Approach to solve this problem is like
/*
We have given N value and 6 possible jump we can make to reach (N-1)th cell.
We don't how we can reach but we know we have 6 possible jump[1,2,3,4,5,6] we can make.
so we make 6 possible jump from  start and check we have reached (N-1) cell
check start == (N-1)
    print all possible ways

check start>=N
    return 
start = 0
f(N, start) = f(N, start+1)
              f(N, start+2)
              f(N, start+3) 
              f(N, start+4) 
              f(N, start+5) 
              f(N, start+6)  
*/
void printWays(int n, int start, string osf){
    // Base case
    if((n-1)==start){
        cout<<osf<<endl;
        return ;
    }

    // Edge case
    if(start>=n)
        return;

    // Recursive Assumption
    printWays(n, start+1, osf+to_string(1));
    printWays(n, start+2, osf+to_string(2));
    printWays(n, start+3, osf+to_string(3));
    printWays(n, start+4, osf+to_string(4));
    printWays(n, start+5, osf+to_string(5));
    printWays(n, start+6, osf+to_string(6));
}
int main(){
    int n;
    cin>>n;

    printWays(n, 0, "");
}

/*
Input :-
5
Output :-
1111
112
121
13
211
22
31
4
*/