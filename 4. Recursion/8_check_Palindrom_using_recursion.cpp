// Given An string, Check this is Palindromic string or Not.
/*
Example :-
Input :-
abcdc
Output :-
Not a Palindromic String


Input :-
abcdcba
Output :-
Palindromic String
*/

#include<iostream>
using namespace std;

bool checkPalindrome(string str, int n, int i){

    // Base case
    if(n==1)
        return true;
    
    if(n==0)
        return true;
    
    if((n/2)==i){
        return true;
    }

    bool ans = false;
    // Self work
    if(str[i]==str[n-1-i])
    {
        // Recursive Assumption
        ans = checkPalindrome(str, n, i+1);
    }
    else
    {
        // Self work
        ans = false;
    }

    // Self work
    return ans;
}
int main(){
    string str;
    getline(cin, str);

    int len = str.length();

    if(checkPalindrome(str, len, 0)){
        cout<<"Palindromic String"<<endl;
    }
    else {
        cout<<"Not a Palindromic String"<<endl;
    }
    return 0;
}

/*
Input :-
abcdcba
Output :-
Palindromic String
*/