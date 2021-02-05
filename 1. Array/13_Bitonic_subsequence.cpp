// Find the bitonic length of the subarray
/*
Sample Input
2
6
12 4 78 90 45 23
4
40 30 20 10
Sample Output
5
4
Explanation
ForMaximum length = 4, 78, 90, 45, 23*/
#include<iostream>
using namespace std;

// 1 Approach Time - 0(N^2), Space - 0(N)
// This is an brute force approach to solve this problem
int find_bitonic_subsequence(int arr[], int n)
{
    int left[n] = {0},right[n]= {0};

    left[0] = 1;
    right[n-1] = 1;

    // finding the left array
    for(int i = 1; i<n; i++)
    {
        int x = 1;

        for(int j = 0; j<i; j++)
        {
            if(arr[i]>arr[j])
            {
                x = max(x, left[j]+1);
            }
        }
        left[i] = x;
    }

    // finding the right array

    for(int i = n-2; i>=0; i--)
    {
        int x = 1;
        for(int j = i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                x = max(x, right[j]+1);
            }
        }
        right[i] = x;
    }

    int ans = 0;

    for(int i = 0; i<n; i++)
    {
        ans = max(ans,left[i]+right[i]-1);
    }
    return ans;
}

// 2 Approach Time - 0(N), Space - 0(N)
// This is an efficient solution to solve this problem
int bitonic(int arr[], int n)
{
    int inc[n]; // Length of increasing subarray ending at all indexes
    int dec[n]; // Length of decreasing subarray starting at all indexes
    int i, max;

    // length of increasing sequence ending at first index is 1
    inc[0] = 1;

    // length of increasing sequence starting at first index is 1
    dec[n-1] = 1;

    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;

    return max;
}
void solve()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<bitonic(arr, n)<<endl;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }

}
