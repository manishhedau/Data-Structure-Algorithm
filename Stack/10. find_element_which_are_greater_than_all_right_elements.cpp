// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

// Find all elements in an array that are greater than all elements to their right

/*1 . Approach :-
---------------
We use two loop for this operation
1. outer loop iterate over the array
2. second inner loop check next elements are greater than curr element
if that so then we just iterate upto last element.
and if curr is element is greater then we just print it.

Time complexity - O(N^2) because of two loop
Space complexity - O(1)
*/


/*
2. Approach :-
--------------
we use stack to solve this problem because stack reverse the array/containers.
and after reversing problem become easier to solve.
by using one iteration over stack
for first iteration we just assign prevtop = currtop and print prevtop
and in every iteration check 'prevtop <= currtop'then
		1.) prevtop = currtop
		2.) print prevtop
otherwise iterate/pop over the remaining part

Time complexity - O(N)
Space complexity - O(N)

Example :- arr[] = [10, 4, 6, 3, 5]

stack[] = {5, 3, 6, 4, 10}
prevtop = -1;

1. iterate over stack upto stack != empty
	// for first element
	if(prevtop == -1){
		prevtop = stack[top] // because this is right most element
		print prevtop
	}
	else if(prevtop<=currtop(stack[top])){
		// if prevtop is less then currtop
		// means this is higher than all right elements
		prevtop = currtop(stack[top])
		print prevtop
	}
	// pop from stack
	pop()

this process is continue upto stack become empty.
*/

/*
3. Approach:-
---------------
Time complexity - O(N), Space complexity - O(1)
we can solve this problem in linear time and constant space.
by iterate from right to left and apply the same above approach2.
// prev maintain the higher element from right
prev = -1;
i = n-1;
1. while(i>=0)
// for first element
	if(prev == -1){
		prev = arr[i] // because this is right most element
		print prev
	}
	else if(prev<=arr[i]){
		// if prev is less then curr
		//curr means this is higher than all right elements
		prev = arr[i]
	}
	// decrease curr index
	i--
*/

int my_stack[100] = {0};
int top = -1;

void push(int data) {
	my_stack[++top] = data;
}

int pop() {
	// check stack is empty or not
	if (top == -1) {
		return -1;
	}
	int num = my_stack[top];
	my_stack[top] = 0;
	top--;
	return num;
}

int main() {
	int n;
	cin >> n;

	int arr[n] = {0};
	// taking my_stackay element input
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// push my_stackay item onto an stack
	for (int data : arr) {
		push(data);
	}

	int prevTop = -1;
	while (top != -1) {
		if (prevTop == -1) {
			prevTop = my_stack[top];
			cout << prevTop << " ";
		}
		else if (prevTop <= my_stack[top]) {
			prevTop = my_stack[top];
			cout << prevTop << " ";
		}
		pop();
	}
	cout << endl;
	return 0;
}

/*
Input :-
----------
5
10 4 6 3 5

Output :-
------------
5 6 10


Input :-
-----------
5
5 4 3 2 1

Output :-
----------
1 2 3 4 5
*/