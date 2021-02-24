// Find GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers using recursion.
/*
Input :-
36 24

Output :-
12 (Because 12 is highest common Factor of both the numbers)
*/

#include<iostream>
using namespace std;
// Finding GCD of any two given number
int findGCD(int a, int b, int min){

    // Base case
    if(min==1)
        return 1;

    // Self work
    if(a%min==0 && b%min==0)
    {
            return min;
    }

    // Recurance Assumption
    return findGCD(a,b,min-1);
}
int main(){
    int a, b;
    cin>>a>>b;
    cout<<findGCD(a,b,min(a,b));
    return 0;
}

/*
Input :-
9 6
Output :-
3
*/