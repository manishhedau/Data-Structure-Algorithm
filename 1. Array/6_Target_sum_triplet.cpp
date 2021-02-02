// Arrays-Target Sum Triplets
// Given a sorted array find the three number which sum = Target
/*
Input :-

9 --> array length
5 7 9 1 2 4 6 8 3 --> array values
10 --> target

Output :-
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
*/


#include<iostream>
#include<algorithm>
using namespace std;

// 1 Approach Time - 0(N^3), Space - 0(1)

void Target_sum_triplet_1(int arr[], int n, int target)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            for(int k = j+1; k<n; k++)
            {
                if((arr[i]+arr[j]+arr[k])==target)
                {
                    cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k]<<endl;
                }
            }
        }
    }
}

// 2 Approach Time - 0(N log N), Space - 0(1)
void Target_sum_triplet_2(int a[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == target)
            {
                cout << a[i] << ", " << a[l] << " and " << a[r] << endl;
                l++;
                r--;
            }
            else if (a[i] + a[l] + a[r] < target)
                l++;
            else
                r--;
        }
    }

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

    int target;
    cin>>target;
    sort(arr, arr+n);
    Target_sum_triplet_2(arr, n, target);

    return 0;
}

/*
OUTPUT :-

9
5 7 9 1 2 4 6 8 3
10
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
*/
