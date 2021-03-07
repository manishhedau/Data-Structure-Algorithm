#include<iostream>
using namespace std;

/*
Output :- for N = 2
(())
()()
*/
void generateBrackets_1(int n, int i = 0, int j = 0, string res = ""){
    // base case
    if(i==n && j == n){
        cout<<res<<endl;
        return ;
    }

    if(i>n || j>n){
        return;
    }
   
    if(i<n){
        generateBrackets_1(n, i+1, j, res+"(");
    }
    if(j<i){
        generateBrackets_1(n, i, j+1, res+")");
    }
    
}

/*
Output :- for N = 2
()()
(())
*/
void generateBrackets_2(int n, int i = 0, int j = 0, string res = ""){
    // base case
    if(i==n && j == n){
        cout<<res<<endl;
        return ;
    }

    if(i>n || j>n){
        return;
    }
    if(j<i){
        generateBrackets_2(n, i, j+1, res+")");
    }
    if(i<n){
        generateBrackets_2(n, i+1, j, res+"(");
    }
    
}
int main(){
    int n;
    cin>>n;

    generateBrackets_1(n);
}