// Print the given Pattern using Recursion

/*
Input
5
Output
* 
* * 
* * * 
* * * * 
* * * * * 
*/


#include<iostream>
using namespace std;
// Print star Pattern using one single for loop in recursion
void printPattern(int n ){
    // Base Case
    if(n==0)
        return;

    // Self work
    for(int i = 0; i<n; i++){
        cout<<"* ";
    }
    cout<<endl;
    // Recurance Assumption
    printPattern(n-1);
}

// Print the same pattern without using for loop
void printPattern1(int n, int i){
    // Base Cases
    if(n==0)
        return;
    // Recurance Assumption
    if(i==0)
        printPattern1(n-1, 0);
    if(i<n){
        cout<<"* ";
        // Recurance Assumption
        printPattern1(n, i+1);    
    }
    else{
        cout<<endl;
    }
   // All the remainig things are the self work
}



int main(){
    int n;
    cin>>n;

    printPattern1(n,0);
    return 0;
}

/*
Input :-
5
Output :-
* 
* * 
* * * 
* * * * 
* * * * * 
*/
