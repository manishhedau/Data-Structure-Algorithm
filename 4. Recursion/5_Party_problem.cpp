// Given an N number of person go to party . They can either in a two's pair OR alone in a party.
// So figure out the all the possible way in which N person can Go.

/*Example -
Input :-
N = 3

Output :-
Number of way :- 4
Explanation :-
Let's consider The 3 persons are A, B,C
[A], [B], [c]
[A, B], [C]
[A, C], [B]
[B, C], [A]
These 4 possible way person can go to the party.
*/

#include<iostream>
using namespace std;

// party problem
int findWays(int n)
{
    // base case
    if (n == 1) return 1;
    if (n == 0) return 1;
    // recursive assumption
    // lets talk about one person
    // ek person pair me gya to partner sath leke jayenga - findways(n-2)
    // and baki person kaise bhi ja skte hai so - (n-1)*findways(n-2)
    int num = (n - 1) * findWays(n - 2);
    // self work
    // agar person single gya to to - findways(n-1) and baki persons to pair me ja skte or single bhi ja skte hai
    // we have to add
    return num + findWays(n - 1);
}

int main()
{
    int n;
    cin >> n;

    //int noWay = findWays(n);
    cout << "The ways are : " << noWay << endl;
    return 0;
}

/*
Input :-
3
Output :-
The ways are : 4*/