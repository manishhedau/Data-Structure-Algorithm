
// Prefix expression evaluation.
#include<iostream>
#include<cstring>
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
    int i = strlen(exp) - 1;

    while (i >= 0) {
        char e = exp[i];
        if (isalnum(e)) {
            int num = e - '0';
            // cout<<"num1 : "<<num<<endl;
            push(num);
        }
        else {
            int a = pop();
            int b = pop();
            int num = result(a, b, e);
            // cout<<"num2 : "<<num<<endl;
            push(num);
        }
        i--;
    }
    cout << "Result is : " << pop() << endl;

}


/*
Input :-
---------
+2**346
Output :-
--------
Enter the expression :: +2**346
Result is : 74

Explaination :-
--------------
Infix Expression is : (2+(3*4)*6)
                    = (2+(12)*6)
                    = (2+(12*6))
                    = (2+(72))
                    = 72

Input :-
-----------
+*23*4-56

Output :-
----------
Enter the expression :: +*23*4-56
Result is : 2

Explaination :-
-------------------
Infix expression is : (2*3+4*(5-6))
                    = ((2*3)+(4*(5-6)))
                    = ((6)+(4*(-1)))
                    = (6+(4*-1))
                    = (6+(-4))
                    = 6-4
                    = 2

*/
