// Code By - Manish Hedau
#include<bits/stdc++.h>
using namespace std;


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

int main()
{
    char exp[100];
    char *e, x;
    cout << "Enter the expression :: ";
    cin >> exp;
    cout << exp << endl;
    e = exp;
    while (*e != '\0')
    {
        // operands, print
        if (isalnum(*e))
            cout << *e << " ";
        else if (*e == '(') // for left paranthesis, then push
            push(*e);
        else if (*e == ')')
        {
            // right operator, then pop and print unitl found left paranthesis
            while ((x = pop()) != '(')
                cout << x << " ";
        }
        else
        {
            // for operator
            // when operator is found then check priority of top and curr operator
            //when top is higher precedance,
            // if top>=curr =>then pop and print unitl found lower operator
            while (priority(my_stack[top]) >= priority(*e))
                cout << pop() << " ";
            // push the curr operator in stack
            push(*e);
        }

        // iterate over the next expression.
        e++;
    }

    // pop everythings from stack and print.
    while (top != -1)
    {
        cout << pop() << " ";
    }
    cout << endl;
    return 0;
}


/*
Input :-
---------
(2*3+4*(5-6))

Output :-
-------
Enter the expression :: (2*3+4*(5-6))
2 3 * 4 5 6 - * +

*/