// Find the maximum element in bitonic array

/*
Input :-
8
1 2 3 4 5 4 3 2

Output :-
 5 (Because 5 is max element in array)
*/
#include<iostream>
using namespace std;


// 1 Approach using linear search
// Time - 0(N), Space - 0(1)

// 2 Approach using Binary search
// Time - 0(log N), space - 0(1)
int  findBitonicPoint(int arr[], int n, int l, int r)
{

    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if (arr[mid] > arr[mid - 1]
        && arr[mid] > arr[mid + 1])
    {
        return mid;
    }

    else if (arr[mid] > arr[mid - 1]
             && arr[mid] < arr[mid + 1])
    {
        bitonicPoint =  findBitonicPoint(arr, n, mid, r);
    }

    else if (arr[mid] < arr[mid - 1]
             && arr[mid] > arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, l, mid);
    }
    return bitonicPoint;
}

int find_maximum(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            return mid;
        else if(arr[mid] > arr[mid - 1]
             && arr[mid] < arr[mid + 1])
             s = mid+1;
        else if(arr[mid] < arr[mid - 1]
             && arr[mid] > arr[mid + 1])
             e = mid-1;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int l = 0;
    int r = n-1;
    //int index = findBitonicPoint(arr, n, l, r);
    int index = find_maximum(arr, n);
    cout<<"The maximum number is :"<<arr[index];
    return 0;
}
