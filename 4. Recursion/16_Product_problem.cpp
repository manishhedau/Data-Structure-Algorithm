/*
Replace every array element with the product of every other element without using a division operator
Input:  { 1, 2, 3, 4, 5 }
Output: { 120, 60, 40, 30, 24 }   -->total array element product is = 120, if we devide product/arr[i], 
                                      120/1 = 120, 120/2 = 60, 120/3 = 40, 120/40 = 30, 120/5 = 24
 
Input:  { 5, 3, 4, 2, 6, 8 }
Output: { 1152, 1920, 1440, 2880, 960, 720 }
*/

#include<iostream>
using namespace std;
// Global variable which store product of array elements
int product = 1;

int result(int val, int currProduct, int j){
    // Base case
    if(currProduct<=0) return j;

    // self work
    currProduct = currProduct-val;
    j = j+1;
    // Recursive Assumption
    return result(val, currProduct, j);
}
void replaceProduct(int *arr, int n, int i){
    // Base case 
    if(i==n) return;
    // Self work , take the product of array element
    product = product *arr[i];
    // Recursive Assumption
    replaceProduct(arr, n, i+1);
    
    // self work
    arr[i] = result(arr[i], product, 0);
}
int main(){
    int n;
    cin>>n;

    int arr[n] = {0};

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    replaceProduct(arr, n, 0);

    cout<<"Now the array values are : "<<endl;

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<", ";
    return 0;
}

/*
Input :-
5
1 2 3 4 5
Output :-
Now the array values are : 
120, 60, 40, 30, 24, 
*/