#include<iostream>
using namespace std;

// in recursive tree --> top to bottom solution
string replacePI(string str, int len , int i, string osf){
    // base case
    if(i==len){
        return osf;
    }
    if(len==0||len==1) return "";

    //self work
    if(str[i]=='p' && str[i+1]=='i'){
        return replacePI(str, len, i+2, osf+"3.14");
    }
    return replacePI(str, len, i+1, osf+str[i]);
}

// we can not solve this problem using bottom to top direction using this approach
// in recusive tree --> bottom to top solution
/*
Input :-
xypizpip
Output :-
xy3.14iz3.14ip
*/
string replacePI(string str, int len){
    // base case
    if(len==0){
        return "";
    }

    string osf = "";
    osf += replacePI(str, len-1);

    // self work
    if(str[len-1]=='p' && str[len]=='i'){
        osf += "3.14";
    }
    else
        osf += str[len-1];
    return osf;
}
int main() {
    string str;
    getline(cin, str);

    cout<<replacePI(str, str.length(), 0, "")<<endl;
    // cout<<replacePI(str, str.length())<<endl;
}

/*
Input :-
xypizpiip
Output :-
xy3.14z3.14ip
*/