#include<iostream>
#include<cstring>
using namespace std;

// Time complexity - O(N), Space complexity - O(N)
// we can also solve this problem taking empty string as parameter
// whenever we found i & i+1 char is different then "add" 'i' character to 'empty string'

// Time complexity - O(N), Space complexity - O(1)
// remove all the duplicates character from the given string
char * removeDuplicates(char * str, int i, int idx, int len){
    // base case
    if(i==len){
        str[idx] = NULL;
        return str;
    }

    // self work
    if(str[i]!= str[i+1]){
        str[idx] = str[i];
        idx++;
    }
    // recursive calls
    return removeDuplicates(str, i+1, idx, len);
}
int main(){
    char str[1000];
    cin>>str;
    cout<<removeDuplicates(str, 0, 0, strlen(str));
}

/*
Input :-
aabccba
Output :-
abcba
*/