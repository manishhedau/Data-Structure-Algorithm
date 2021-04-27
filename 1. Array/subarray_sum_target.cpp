// Find the subarray that sum to a target
// This problem solve using Sliding window technique
/*

Input :-
8 --> array length
5 3 1 7 6 3 2 1 -->arrays values
14  -->target

Output :-
2 and 5 (1+7+6 = 14)
*/
#include<iostream>
using namespace std;


// 1. First Approach - using subarray sum and which subarray is sum == target
//  print the start and and end point of that subarray
// Time complextiy - O(N^3), Space complexity - O(1)

// 2. Second Approach - using conmulative sum method
// first calculate the commulative sum of array
// using two for loop iterate over the array
// outer for loop track start point of the array
// inner for loop track end point of the array

// Time complexity - O(N^2), Space Complexity - O(1)


// 3. Third Approach - Using Sliding Window Techniques
// Time complexity - O(N), Space Complexity - O(1)
void find_pair(int arr[], int n, int target)
{
    int start = 0, End = 0;

    int sum = 0;
    //cout<<"sum "<<sum<<endl;
    while (start < n)
    {
        if (start > End)
        {
            start = End;
            sum = arr[start];
        }
        if (sum < target)
        {
            if (End == n - 1)
                break;
            sum += arr[End];
            //cout<<sum<<endl;
            End++;
        }
        else if (sum > target)
        {
            sum -= arr[start];
            //cout<<sum<<endl;
            start++;
        }
        else
        {
            cout << sum << endl;
            cout << start << " and " << End << endl;
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    find_pair(arr, n, target);
    return 0;
}

/*
OUTPUT :
8
5 3 1 7 6 3 2 1
14

2 and 5
*/
