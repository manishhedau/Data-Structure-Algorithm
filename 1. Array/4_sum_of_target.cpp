
// Sum of target
/*
Input :-
10
1 2 3 4 5 6 7 8 9 10
10

Output :-
1 and 9
2 and 8
3 and 7
4 and 5

*/

#include<iostream>
using namespace std;


// 1 Approach Time - 0(N^2), Space - 0(1)
void find_pair_sum_of_target_1(int * arr, int n, int target)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if((arr[i]+arr[j])==target)
            {
                cout<<arr[i]<<" and "<<arr[j]<<endl;
            }
        }
    }
}

// 2 Approach Time - 0(N log N), space 0(1)
// iterate over the whole loop and find 'target-arr[i]'  value exist or not using binary search
// if exist then print pair

// 3 Approach Time - 0(log N), Space - 0(1)
// Two pointer approach(if array is sorted)
void find_pair_sum_of_target_3(int *arr, int n, int target)
{
    int low = 0;
    int high = n-1;

    while(low<high)
    {
        if((arr[low]+arr[high])==target)
        {
            cout<<arr[low]<<" and "<<arr[high]<<endl;
            low++;
            high--;
        }
        else if((arr[low]+arr[high])>target)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
}
int main()
{
    int n;
    cin>>n;

    int arr[n] ={0};

    // taking values of the array index's
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    int target;
    cin>>target;

    find_pair_sum_of_target_3(arr, n, target);
    return 0;
}

/*
OUTPUT :-
10
1 2 3 4 5 6 7 8 9 10
10
1 and 9
2 and 8
3 and 7
4 and 6
*/
