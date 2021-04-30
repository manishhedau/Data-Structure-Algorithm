// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

/*
Approach :-
----------------
Stack element(s1)
1
2
3
4
5

Iteration - i = 0
Extract top topdata = 1 and pop 1 from stack
i = 0, N = 4-i = 4-0 = 4
now transfer s1 to s2
stack element (s2)
5
4
3
2

Now push topdata into s1
Stack element(s1)
1

next transfer s2 to s1
2
3
4
5
1

Iteration - i = 1
topdata = 2
Extract top topdata = 1 and pop 1 from stack
i = 1, N = 4-i = 4-1 = 3
now transfer s1 to s2
stack element (s2)
5
4
3

Now push topdata into s1
Stack element(s1)
2
1

next transfer s2 to s1
3
4
5
2
1


Iteration - i = 2
topdata = 3
Extract top topdata = 1 and pop 1 from stack
i = 2, N = 4-i = 4-2 = 2
now transfer s1 to s2
stack element (s2)
5
4

Now push topdata into s1
Stack element(s1)
3
2
1

next transfer s2 to s1
4
5
3
2
1

Iteration - i = 3
topdata = 4
Extract top topdata = 1 and pop 1 from stack
i = 3, N = 4-i = 4-3 = 1
now transfer s1 to s2
stack element (s2)
5

Now push topdata into s1
Stack element(s1)
4
3
2
1

next transfer s2 to s1
5
4
3
2
1

Iteration - i = 4
topdata = 5
Extract top topdata = 1 and pop 1 from stack
i = 4, N = 4-i = 4-4 = 0
now transfer s1 to s2
stack element (s2)
5

Now push topdata into s1
Stack element(s1)
5
4
3
2
1

next transfer s2 to s1
5
4
3
2
1

Output :-
---------
Now S1 is
5
4
3
2
1
Iterate over the stack all the element of stack
	1. extract top() of stack and pop() that top element
	2. count size N - stack.size()-i
	3. transfer(means element) s1 to s2 by using function upto N.
	4. Now push topElement at stack
	5. now transfer s2 to s1 by using function upto N.

Time complexity :- O(N^2)
Space complexity :- O(N) for storing traverse data
*/


void transfereElements(stack<int>&s1, stack<int>&s2, int n) {
	for (int i = 0; i < n; i++) {
		// top of s1
		int data = s1.top();
		// remove from s1
		s1.pop();

		// now push remove data into s2
		s2.push(data);
	}
}
void reverseStack(stack<int>&s1) {
	// creating new stack for traverse element operation
	stack<int>s2;

	for (int i = 0; i < s1.size(); i++) {
		int topElement = s1.top();
		s1.pop();

		int n = s1.size() - i;
		// transfere n element from s1 to s2
		transfereElements(s1, s2, n);

		// now push topELement into s1
		s1.push(topElement);

		// now transfere n element from s2 to s1
		transfereElements(s2, s1, n);
	}
}
int main() {
	stack<int>s1;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		s1.push(i);
	}
	reverseStack(s1);
	cout << "Printing reverse Stack data : " << endl;

	while (!s1.empty()) {
		cout << s1.top() << ", ";
		s1.pop();
	}
	return 0;
}
/*
Input :-
5

Ouput :-

Printing reverse Stack data :
1, 2, 3, 4, 5,

Explaintaion :-
--------------
Stack(after pushing n data)
top ->5 4 3 2 1
Stack(after reversing n data)
top ->1 2 3 4 5
*/