
// Postfix expression evaluation.
#include<iostream>
using namespace std;

char s[20];
int top = -1;

void push(int x)
{
    s[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    else
        return s[top--];
}

int result(int a, int b, char op) {
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    return -1;
}
int main() {
    char exp[20];
    cout << "Enter the expression :: ";
    cin >> exp;
    cout << exp << endl;
    int i = 0;

    while (exp[i] != '\0') {
        char e = exp[i];
        if (isalnum(e)) {
            int num = e - '0';
            // cout<<"num1 : "<<num<<endl;
            push(num);
        }
        else {
            int a = pop();
            int b = pop();
            int num = result(b, a, e);
            // cout<<"num2 : "<<num<<endl;
            push(num);
        }
        i++;
    }
    cout << "Result is : " << pop() << endl;

}


/*
Input :-
---------
23*456-*+
Output :-
--------
Enter the expression :: 23*456-*+
Result is : 2

*/
