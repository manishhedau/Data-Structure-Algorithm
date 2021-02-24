/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0

*/

#include <iostream>
using namespace std;
int main() {
    int x;
    cin>>x;
    long sum = 1;
    int res = x%10;
    sum = sum *res;
    //cout<<sum<<endl;
    x = x/10;

    // for positive number
    while(x>0)
    {
        res = x%10;
        sum = sum * 10+res;
        //cout<<sum<<endl;
        x = x/10;

    }

    // for negative number
    while(x<0)
    {
        res = x%10;
        sum = sum * 10+res;
        //cout<<sum<<endl;
        x = x/10;
    }
    cout<<"The reverse number is : "<<sum<<endl;
}
