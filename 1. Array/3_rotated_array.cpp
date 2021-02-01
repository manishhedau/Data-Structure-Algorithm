
// Rotate the array from the given index value
/*
Input :-
5
1 2 3 4 5
2

Output :-
3 4 5 1 2

*/

#include<iostream>
using namespace std;


// 1 Approach Time - 0(N), Space - 0(N)
void Rotate_array_1(int *arr, int n, int index)
{
    int rr[n];


    int j = 0;
    // From index to N-1 Assigning value to rr array
    for(int i = index; i<n; i++)
    {
        rr[j] = arr[i];
        j++;
    }

    // form 0 to index Assigning value to rr array
     for(int i = 0; i<index; i++)
    {
        rr[j] = arr[i];
        j++;
    }

    // Parsing all element value to original array(arr)
    for(int i = 0; i<n; i++)
    {
        arr[i] = rr[i];
    }

}


// 2. Approach Time - 0(log N), space - 0(1)

void Rotate_array_2(int *arr, int n, int index)
{
    int low = 0;
    int high = n-1;

    while(low<high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }

    low = 0;
    high = n-index-1;

    while(low<high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }

    low = n-index;
    high = n-1;

    while(low<high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
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

    int index;
    cin>>index;

    Rotate_array_2(arr, n, index);
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

/*
OUTPUT :-
5
30 40 50 60 70
2
50 60 70 30 40
*/
