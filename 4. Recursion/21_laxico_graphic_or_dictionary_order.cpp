/* Given an N, print all the laxico graphic order/ Dictionary order
*/

#include<iostream>
using namespace std;

void lexicoGraphicalOrder(int n, int i){
    // base case
    if(i>n) return ;

    cout<<i<<" ";
    for(int j = (i==0)?1:0; j<=9; j++)
        lexicoGraphicalOrder(n, 10*i+j);
}

int main(){
    int n;
    cin>>n;

    lexicoGraphicalOrder(n, 0);
}


/*
Input :-
13
Output :-
0 1 10 11 12 13 2 3 4 5 6 7 8 9 
*/