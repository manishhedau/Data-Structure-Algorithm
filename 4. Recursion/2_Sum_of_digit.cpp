// Given an number N print the sum of digit
/*
Example :-
Input :- N = 2000
Output :- 2 (2+0+0+0)

Input :- N = 2400
Output :- 6 (2+4+0+0)
*/ 

#include <iostream>
using namespace std;

int sumDigit(int n)
{
    if(n==0)
        return 0 ;
    
    int lastDigit = n%10;
    n = n/10;
    return lastDigit+sumDigit(n);
}
int main() {
    int n;
    cin>>n;

    int sum = sumDigit(n);
    cout<<"Sum of digit is : "<<sum<<endl;
}


/*
Input
12345
Output
Sum of digit is : 15
*/