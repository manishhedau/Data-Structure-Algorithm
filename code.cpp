#include<iostream>
using namespace std;

void permutations_backtracking(string str, int j) {
    // base case
    if (str.size() - 1 == j) {
        cout << str << endl;
        return;
    }

    for (int i = j; i < str.size(); i++) {
        swap(str[i], str[j]);
        // recursive case
        cout << "Going Toword Base : i = " << i << " j = " << j << endl;
        permutations_backtracking(str, j + 1);
        // cout << "Going Toword Base : i = " << i << " j = " << j << endl;
        swap(str[j], str[i]);
    }
}
int main() {
    permutations_backtracking("ABC", 0);
    return 0;
}

/*
Output :-
ABC
ACB
BAC
BCA
CBA
CAB
*/