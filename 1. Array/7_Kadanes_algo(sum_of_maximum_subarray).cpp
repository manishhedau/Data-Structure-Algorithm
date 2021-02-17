// Maximum sub array sum
// Fastest Approach is using Kadane's algorithm

/*
Input :-
4
-2 1 -3 4

Output :-
4
*/
#include<iostream>
using namespace  std;

// 1 Approach  Time - 0(N^3), space - 0(1)
int Maximum_subarray_sum_1(int arr[], int n)
{
    int Max_sum = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            int curr_sum = 0;
            for(int k = i; k<=j; k++)
            {
                curr_sum += arr[k];
            }
        if(curr_sum>Max_sum)
        {
            Max_sum = curr_sum;
        }
        }
    }
    return Max_sum;
}


// 2. Approach Time - 0(N^2), space 0(N)
int Maximum_subarray_sum_2(int arr[], int n)
{
    int Max_sum = 0;

    int cs[n] = {arr[0]};
    // consecutive sum
    for(int i = 1; i<n; i++)
    {
        cs[i] = arr[i]+cs[i-1];
    }


    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            int curr_sum = cs[j]-cs[i-1];
            if(curr_sum>Max_sum)
            {
                Max_sum = curr_sum;
            }
        }
    }
    return Max_sum;
}

// 3. Approach Time - 0(N), space 0(1)
int Maximum_subarray_sum_3(int arr[], int n)
{
    // using Kadane's Algorithm
    int Max_sum = 0;
    int curr_sum = 0;
    for(int i = 0; i<n; i++)
    {
        curr_sum += arr[i];

        if(curr_sum<0)
        {
            curr_sum = 0;
        }
        Max_sum = max(Max_sum, curr_sum);
    }

    return Max_sum;
}

// To get the sequence of subarray which sum is max
// Use two pointer approach to get the start,end index of sequence of max subarray
void find_max_subarray_sum(int arr[], int n)
{
    int s = 0;
    int e = 0;

    int maxSum = 0;
    int currSum = 0;

    for(int i = 0; i<n; i++)
    {
        currSum += arr[i];

        if(currSum<0)
        {
            currSum = 0;
            s = i+1;
        }
        maxSum = max(maxSum, currSum);
        e = i;
    }

    cout<<"The maximum of subarray is : "<<maxSum<<endl;

    for(int i = s; i<=e; i++)
    {
        cout<<arr[i]<<", ";
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n] = {0};

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<Maximum_subarray_sum_3(arr, n);
    return 0;
}

/*
OUTPUT :-
4
-2 1 -3 4
4
*/
