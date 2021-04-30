// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;

// Implement two stack with same size on single array.
/*
Approach :-
----------
1. first i will take both the arrays sizes.
2. and i will create one stack with 2*size of array.
3. in first half part i will store stack1 data.
4. and in remaining half part i will store stack2 data.
5. and i will create same two-two function for push, pop, isempty, top.
6. top1 = -1 and top2 = (size/2)-1
7. by using this approach i can create two stack of same size in an ARRAY.
*/

class My_STACK {
    int *arr = NULL;
    int top1 = -1;
    int top2 = -1;

    int size;

public :
    My_STACK(int size) {
        this->size = size;
        arr = new int[size] {0};
        top2 = size / 2 - 1;
    }

    // push operation on stack 1
    void push1(int data) {
        // check stack is full or not
        if ((size / 2) == top1 + 1) {
            cout << "Stack is full !" << endl;
            return;
        }
        top1++;
        arr[top1] = data;
    }

    // push operation on stack 2
    void push2(int data) {
        // check stack is full or not
        if (size == top2 + 1) {
            cout << "Stack is full !" << endl;
            return;
        }
        top2++;
        arr[top2] = data;
    }

    // check stack 1 is empty or not
    bool isEmpty1() {
        return (top1 == -1);
    }

    // check stack 2 is empty or not
    bool isEmpty2() {
        return (top2 == (size / 2) - 1);
    }

    // pop operation on stack 1 and return poped value.
    int pop1() {
        if (isEmpty1()) {
            return -1;
        }
        int num = arr[top1];
        arr[top1] = 0;
        top1--;

        return num;
    }

    // pop operation on stack 2 and return poped value.
    int pop2() {
        if (isEmpty2()) {
            return -1;
        }
        int num = arr[top2];
        arr[top2] = 0;
        top2--;

        return num;
    }

    // top element of stack1
    int topElement1() {
        if (isEmpty1()) {
            return -1;
        }
        return arr[top1];
    }

    // top element of stack2
    int topElement2() {
        if (isEmpty2()) {
            return -1;
        }
        return arr[top2];
    }
};

void take_input(int *arr, int size) {
    // taking input
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return;
}


int main() {
    int size;
    cin >> size;

    int arr1[size] = {0};
    int arr2[size] = {0};
    take_input(arr1, size);
    take_input(arr2, size);

    // creating stack object
    My_STACK st(size + size);

    for (int i = 0; i < size; i++) {
        st.push1(arr1[i]);
    }
    st.push1(6);


    for (int i = 0; i < size; i++) {
        st.push2(arr2[i]);
    }
    st.push2(11);

    cout << "Top element of stack 1 : " << st.topElement1() << endl;
    cout << "Top element of stack 2 : " << st.topElement2() << endl;

    for (int i = 0; i < size; i++) {
        cout << st.pop1() << ", ";
    }
    cout << st.pop1() << endl;;


    for (int i = 0; i < size; i++) {
        cout << st.pop2() << ", ";
    }
    cout << st.pop2() << endl;
    return 0;
}


/*
Input :-
---------
5
1 2 3 4 5
6 7 8 9 10

Output :-
-----------
Stack is full !
Stack is full !
Top element of stack 1 : 5
Top element of stack 2 : 10
5, 4, 3, 2, 1, -1
10, 9, 8, 7, 6, -1

*/