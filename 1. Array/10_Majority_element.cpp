// Find the Majority element
/*
Input :-
6
1 1 2 1 3 1

Output :-
The majority element is : 1
*/

#include<iostream>
#include<algorithm>
using namespace std;

// 1 Approach Time - 0(N^2), Space - 0(1)
void printMajority_1(int arr[], int n)
{
    int Maj_index = 0;
    int Max_count = -1;

    for(int i = 0; i<n; i++)
    {
        int Count = 0;

        for(int j = 0; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                Count++;
            }
        }

        if(Count>Max_count)
        {
            Max_count = Count;
            Maj_index = i;
        }
    }

    if(Max_count>n/2)
    {
        cout<<"The majority element is : "<<arr[Maj_index]<<endl;
    }
    else
    {
        cout<<"No majority element in array"<<endl;
    }
}


// 2 Approach Time - 0(N logN), Space - 0(1)/0(N)
void printMajority_2(int arr[], int n)
{
    sort(arr, arr+n);

    int maj_index = 0;

    int Maj_count = -1 , Count = 1;

    for(int i = 1; i<n;  i++)
    {
        if(arr[i]==arr[i-1])
        {
            Count++;
        }
        else
        {
            Count = 1;
        }

        if(Count>Maj_count)
        {
            maj_index = i;
            Maj_count = Count;
        }
    }

    if(Maj_count>n/2)
    {
        cout<<"The majority element is : "<<arr[maj_index]<<endl;
    }
    else
    {
        cout<<"No majority element ."<<endl;
    }

}

// 3 Approach Time - 0(N), Space - 0(1)
// Finding Candidate using this function
int findCandidate(int arr[], int n)
{
    int maj_index = 0, counter = 1;

    for(int i = 1; i<n; i++)
    {
        if(arr[maj_index]==arr[i])
            counter++;
        else
            counter--;

        if(counter>maj_index)
        {
            maj_index = i;
            counter = 1;
        }
    }
    return arr[maj_index];
}

// Checking the candidate is majority element or not using this function
bool isMajority(int arr[], int n, int cand)
{
    int Count = 0;

    for(int i = 0; i<n; i++)
    {
        if(arr[i]==cand)
        {
            Count++;
        }
    }

    if(Count>n/2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Printing the majority element using that function
void printMajority_3(int arr[], int n)
{
    int Cand = findCandidate(arr, n);

    if(isMajority(arr, n, Cand))
    {
        cout<<"The majority element is : "<<Cand<<endl;
    }
    else
    {
        cout<<"Array has no majority element ."<<endl;
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

    printMajority_2(arr, n);
    return 0;
}

/*
OUTPUT :-
6
1 1 2 1 3 1
The majority element is : 1

5
1 3 3 1 2
No majority element .
*/
