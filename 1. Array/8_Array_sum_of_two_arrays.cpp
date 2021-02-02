// Array sum of two arrays

/*
Sample Input
4
1 0 2 9
5
3 4 5 6 7
Sample Output
3, 5, 5, 9, 6, END
*/

#include<iostream>
#include<cstring>
using namespace std;

int return_number(int arr[], int n)
{
    int sum = 0;
    sum = arr[0];
    for(int i = 1; i<n; i++)
    {
        sum = sum*10+arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;

    int a1[n];

    for(int i = 0; i<n; i++)
    {
        cin>>a1[i];
    }
    int m = return_number(a1, n);
    cin>>n;
    int a2[n];

    for(int i = 0; i<n; i++)
    {
        cin>>a2[i];
    }
    int k = return_number(a2, n);

    int total = m+k;

    string s1 = to_string(total);
    for(int i = 0; i<s1.length(); i++)
    {
        cout<<s1[i]<<", ";
    }
    cout<<"END"<<endl;
}


/*
OUTPUT :-
4
1 0 2 9
5
3 4 5 6 7
3, 5, 5, 9, 6, END

*/
