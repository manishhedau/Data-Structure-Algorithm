// Given a sorted array find the no of pair which sum = K
/*
Input :-
9 --> array length
1 4 4 5 5 5 6 6 11 -->Array values
11 -->K
Output :-

6 -->(6 pair possible)
*/


#include<iostream>
using namespace std;

// 1 Approach Time - 0(N^2), Space - 0(1)
void find_pair_1(int arr[], int n, int k)
{
    int Pair = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j< n; j++)
        {
            if((arr[i]+arr[j])==k)
            {
                Pair++;
            }
        }
    }

    cout<<Pair<<endl;
}

// 2 Approach Time - 0(N), Space - 0(1)
void find_pair_2(int arr[], int n, int k)
{
    // Two pointer Approach
    int low = 0;
    int high = n-1;

    while(low<high)
    {
        if((arr[low]+arr[high])>k)
        {
            high--;
        }
        else if((arr[low]+arr[high])<k)
        {
            low++;
        }
        else
        {
            int m = 0;
            int i = low;
            while(arr[i]==arr[low])
            {
                m++;
                i++;
            }

            int n = 0;
            i = high;
            while(arr[i]==arr[high])
            {
                n++;
                i--;
            }
            cout<<m*n<<endl;
            break;
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

    int k;
    cin>>k;

    find_pair_2(arr, n, k);

    return 0;
}

/*
OUTPUT :-

9
1 4 4 5 5 5 6 6 11
11
6
*/
