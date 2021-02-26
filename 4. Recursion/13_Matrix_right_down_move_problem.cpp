// Given an N*M matrix we have to reach n-1*m-1 cell.
// To move in matrix either we can go right or down.
// print all the possible paths by we can reach first cell to end cell of matrix
/*
Input :-
3 3
Output :-
RRDD
RDRD
RDDR
DRRD
DRDR
DDRR
*/

#include<iostream>
using namespace std;

void printMatrix(int n, int m, int i, int j , string osf){
    // Base case
    if(i==n-1 && j==m-1){
        // self work
        cout<<osf<<endl;
        return;
    }
    // Edge case or self work
    if(i>=n || j>=m)
        return;

    // Recursive Assumption
    // Right move
    printMatrix(n ,m ,i, j+1, osf+"R");
    // Down move
    printMatrix(n ,m ,i+1, j, osf+"D");
}
int main(){
    int n,m;
    cin>>n>>m;

    printMatrix(n,m,0,0,"");
    return 0;
}
/*
Input :-
3 3
Output :-
RRDD
RDRD
RDDR
DRRD
DRDR
DDRR
*/