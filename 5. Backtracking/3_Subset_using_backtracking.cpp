#include<iostream>
#include<vector>
using namespace std;

// recurisve assumption
// just like recursive approach 
// include the current element 
// exclude the current element (means don't include)

// backtracking assumption
// just like recursive approach
// include the current element then remove the current element (push -->include, pop --> remove the current elememt)
// exclude the current element
void subset(int *arr, vector<int>&temp, int n, int i){
    // base case
    if(i==n){
        cout<<"[";
        for(auto x:temp){
            cout<<x<<" ";
        }
        cout<<"]";
        cout<<endl;
        return;
    }

    // recursive solution
    // Backtracking (make changes)
    temp.push_back(arr[i]);
    subset(arr, temp, n, i+1);
    // undo all the changes while return towords perents call using backtracking
    temp.pop_back();
    subset(arr, temp, n, i+1);
}
int main() {
    int n;
    cin>>n;

    int arr[n] = {0};

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>temp;
    subset(arr, temp, n, 0);
    return 0;
}

/*
Input :-
3
1 2 3
Output :-
[1 2 3 ]
[1 2 ]
[1 3 ]
[1 ]
[2 3 ]
[2 ]
[3 ]
[]
*/