// Given an two number a, b. Find the power of a, b recursively

#include<iostream>
using namespace std;

// Time Complexity - O(b)
// square problem
// mathamatical equation - a*a^(b-1)
int findSquare(int a, int b)
{
    // base case
    if (b == 1) return a;
    if (b == 0) return 1;
    // recursive assumption
    int prev = findSquare(a, b - 1);

    //self work
    return a * prev;
}

// optimized approach
// Time complexity - O(log b)
int powerRecursive(int a, int b) {
    // base case
    if (b == 1) return a;
    if (b == 0) return 1;
    // recursive assumption
    // The reason of first calculating power(a, b/2) to avoid double work for same problem
    // Understand by drawing Recursion Tree.
    int temp = powerRecursive(a, b / 2);
    if (b % 2 == 0)
    {
        return  temp * temp;
    }
    else
    {
        return a * temp * temp;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << "The ways are : " << powerRecursive(a, b) << endl;
    return 0;
}