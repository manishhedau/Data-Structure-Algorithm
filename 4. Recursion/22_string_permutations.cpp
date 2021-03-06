// Given an string , Print all the possible permutations of the given string.

#include<iostream>
using namespace std;

/*
abc acb
bac bca
cab cba

If we observ one thing in the output ,
for all possible permutation which is start from a, 
can I say first given me all the permutation of 'bc' first
------
bc
cb  (bc permutations)
------

so now can i say if we add 'a' to 'bc' permutation then 
I will get all the possible permutation which start from 'a'

a + bc = abc
a + cb = acb

Same task these permutation which is start form 'b'
b + ac = bac
b + ca = bca

next permutation which is start from 'c'
c + ab = cab
c + ba = cba 
*/

void permulations(string str, string perm){
    // base case
    if(str.size()==0){
        cout<<perm<<endl;
        return;
    }

    // recursive case
    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        string res = str.substr(0,i)+str.substr(i+1);
        permulations(res, perm + ch);
    }
}

// 
int main(){
    string str;
    cin>>str;

    permulations(str, "");
    return 0;
}

/*
Input :-
abc
Output :-
abc
acb
bac
bca
cab
cba
*/