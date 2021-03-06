#include<iostream>
using namespace std;

// Intution 
/*
str = 'abc'
for 'a' or for every first character
can i say if we swap 'a' with 'b' - bac
and again swap 'a' with 'c' - bca

for 'b'  str = "bca"
swap 'b' with 'c' - cba
swap 'b' with 'a' - cab

for 'c' str = "cab"
swap 'c' with 'a' - acb
swap 'c' with 'b' - abc

now after every swaping the str is permutation string because we are swaping 2 time for string len 3
so total operation will be = 2*3 = 6
*/

/*
We can also do printing work while going top to down 
or while coming bottom to top in 
recursive tree.
*/ 
// Recursive solution
// swap first character with j+1 character
// printing  the str
// and again we are calling function for i+1, 0 
void permutations(string str,int i, int j){
    // base case
    if(i==str.size()){
        return;
    }

    // if string contain only one character
    if(str.size()==1){
        cout<<str<<endl;
        return;
    }

    // Recursive assumption
    if(j<str.size()-1){
        swap(str[j], str[j+1]);
        cout<<str<<" ";
        permutations(str, i, j+1);
    }
    else{
        permutations(str, i+1, 0);
    }
}
int main(){
    string str;

    cin>>str;

    cout<<str.size()<<endl;
    permutations(str, 0, 0);

    // Iterative solution
    // for(int i = 0; i<str.size(); i++){
    //     for(int j = 1; j<str.size(); j++){
    //         swap(str[j-1], str[j]);
    //         cout<<str<<endl;
    //     }
    // }

    return 0;
}

/*
Input :-
abc
Output :-

bac bca cba cab acb abc 
*/