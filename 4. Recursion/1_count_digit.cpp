// Given an number N count How many digit present in that number
/*
Example :-
Input :- N = 2000
Output :- 4 

Input :- N = 12345678
Output :- 8
*/ 

#include <iostream>
using namespace std;

int countDigit(int n)
{
    if(n==0)
        return 0 ;
    
    int count = 1;
    n = n/10;
    return count+countDigit(n);
}
int main() {
    int n;
    cin>>n;

    int count = countDigit(n);
    cout<<"The digit present in that number are : "<<count<<endl;
}


/*
Input :-
2000
Output :-
The digit present in that number are : 4
*/