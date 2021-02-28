// Given an string which contains numbers, convert string into integer number
/*
Example - str = "1234";
output : - 1234 -->integer format
*/ 
#include <iostream>
using namespace std;

int convertIntoNumber(string &str, int i, int curr)
{
    // Base case;
    // just add the last number with curr number , because no need to calculate curr*10.
    if(i==str.length()-1) {
        curr = curr + (str[i]-'0');
        return curr;
    }   

    // Self work
    int num = str[i]-'0';
    num = curr+num;

    // Recursive Assumption
    return  convertIntoNumber(str, i+1, num*10);

}

int main() {
    string str;
    getline(cin, str);

    cout<<convertIntoNumber(str, 0,0)<<endl;
    return 0;
}


/*
Input :-
56781
Output :-
56781
*/