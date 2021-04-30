// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;
/*
1. Approach
-------------
A) first create an empty stack
B) reverse infix expression , rev_expr.
C) convert rev_expr into post_expr(postfix expression).
D) now convert postfix into prefix we just need to reverse postfix
E) reverse post_expr, rev_post_expr
F) Now print the rev_post_expr into console.
*/

// for reversing the expression with maintaining brackerts.
void reverseExpression(char arr[])
{
    int i = 0;
    int j = strlen(arr) - 1;

    while (i < j)
    {
        if (arr[i] == '(' and arr[j] == ')') {
            arr[i] = ')';
            arr[j] = '(';
            swap(arr[i], arr[j]);
        }
        else if (arr[i] == '(') {
            arr[i] = ')';
            swap(arr[i], arr[j]);
        }
        else if (arr[j] == ')') {
            arr[j] = '(';
            swap(arr[i], arr[j]);
        }
        else {
            swap(arr[i], arr[j]);
        }
        i++;
        j--;
    }
}

char my_stack[100];
int top = -1;
// push item in stack
void push(char x)
{
    my_stack[++top] = x;
}

// pop item from stack
char pop()
{
    if (top == -1)
        return -1;
    else
        return my_stack[top--];
}

// checking priority for given operators
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
int main() {
    char exp[20];
    cin >> exp;
    cout << "Infix Expression is : " << exp << endl;
    reverseExpression(exp);
    cout << "Reversed Infix Expression is : " << exp << endl;

    // creating new array for storing postfix expression
    char post_expr[20];
    int p_index = 0;

    // converting reverse infix expression into postfix expression
    char *e, x;
    e = exp;
    while (*e != '\0')
    {
        // operands, print
        if (isalnum(*e))
            post_expr[p_index++] = *e;
        else if (*e == '(') // for left paranthesis, then push
            push(*e);
        else if (*e == ')')
        {
            // right operator, then pop and print unitl found left paranthesis
            while ((x = pop()) != '(')
                post_expr[p_index++] = x;
        }
        else
        {
            // for operator
            // when operator is found then check priority of top and curr operator
            //when top is higher precedance,
            // if top>=curr =>then pop and print unitl found lower operator
            while (priority(my_stack[top]) >= priority(*e))
                post_expr[p_index++] = pop();
            // push the curr operator in stack
            push(*e);
        }

        // iterate over the next expression.
        e++;
    }

    // pop everythings from stack and print.
    while (top != -1)
    {
        post_expr[p_index++] = pop();
    }
    post_expr[p_index++] = '\0';

    cout << "postfix expression : " << post_expr << endl;
    // now reverse the postfix expression to gain prefix expression
    reverseExpression(post_expr);
    cout << "Prefix Expression is : " << post_expr << endl;
    return 0;
}

/*

Input :-
-------
(a+b)

Output :-
----------
Infix Expression is : (a+b)
Reversed Infix Expression is : (b+a)
postfix expression : ba+
Prefix Expression is : +ab

Input :-
-------
(2+(3*4)*6)

Output :-
---------
Infix Expression is : (2+(3*4)*6)
Reversed Infix Expression is : (6*(4*3)+2)
postfix expression : 643**2+
Prefix Expression is : +2**346

*/