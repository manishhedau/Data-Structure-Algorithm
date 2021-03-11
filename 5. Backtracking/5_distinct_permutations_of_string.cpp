#include<bits/stdc++.h>
using namespace std;


void permute(char *arr, int i, set<string>&str) {
	// base case
	if (arr[i] == '\0') {
		string t(arr);
		str.insert(t);
		return;
	}

	// recursive case
	for (int j = i; arr[j] != '\0'; j++) {
		swap(arr[i], arr[j]);
		permute(arr, i + 1, str);
		// Backtracking
		swap(arr[i], arr[j]);
	}
}
int main() {
	char arr[100];
	cin >> arr;

	set<string> str;
	permute(arr, 0, str);

	for (auto s : str) {
		cout << s << " ,";
	}
	return 0;
}

/*
Input:-
aba
ouput:-
aab ,aba ,baa ,
*/