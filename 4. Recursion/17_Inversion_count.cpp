/*
    Given an unsorted array count the total number of pair where the condition is arr[i]>arr[j] for (i<j).
    Example :-
    Input :-
    6
    1 5 2 6 3 0
    Output :-
    8
    Explanation :-
    (1,0)
    (5,0)
    (5,2)
    (5,3)
    (2,0)
    (6,0)
    (6,3)
*/

#include<iostream>
using namespace std;

// 1. Approach using two for loop and check given two conditions in every iterations
// if condition is true then maintain one variable 'countPair' and increment  that variable whenever the condition will be true.
// Time complexity - O(N^2)
// Space complexity - O(1)
int countInvertion(int *arr, int n)
{
    int cnt = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) {
            if((arr[i]>arr[j])&&(i<j))
            {
                cnt++;
            }
        }
    }

    return cnt;
}
// 2. Approach 
// Time complexity - O(N logN)
// Space complexity - O(N)
int merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = s;

    int cnt = 0;
    int temp[1000];
    while(i<=mid  && j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += mid-i+1;
        }
    }

    // remaining element store in temp
    while(i<=mid) 
        temp[k++] = arr[i++];
    while(j<=e) 
        temp[k++] = arr[j++];

    for(int i = s; i<=e; i++) 
        arr[i] = temp[i];

    return cnt;
}
int inversionCount(int *arr, int s, int e){
    if(s>=e) return 0;

    int mid = (s+e)/2;

    int x = inversionCount(arr, s, mid);
    int y = inversionCount(arr, mid+1, e);
    int z = merge(arr, s, e); // cross inversion
    return x + y + z;  
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int countPair = inversionCount(arr, 0, n-1);
    cout<<countPair<<endl;
    return 0;
}

/*
Input :-
6
1 5 2 6 3 0
Output :-
8
*/