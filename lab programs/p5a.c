#include <stdio.h>
#include<math.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int val)
{
    if (top >= MAX)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
int pop()
{
    int x;
    if (top <= -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}
int main()
{
    printf("Name-Atul Raj\nUSN-1AY23CS045\n");
    char *exp = "625*7/84+39-2%3^28";
    int i, val1, val2;
    for (i = 0; exp[i] != '\0'; i++)
    {
        printf("%c", exp[i]);
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '^')
        {
            val1 = pop();
            val2 = pop();
            if (exp[i] == '+')
            {
                push(val2 + val1);
            }
            if (exp[i] == '-')
            {
                push(val2 - val1);
            }
            if (exp[i] == '*')
            {
                push(val2 * val1);
            }
            if (exp[i] == '/')
            {
                push(val2 / val1);
            }
            if (exp[i] == '%')
            {
                push(val2 % val1);
            }
            if (exp[i] == '^')
            {
                push(pow(val2, val1));
            }
        }
        else
        {
            push(exp[i] - '0');
        }
    }
    printf("\n Answer=%d", stack[top]);
    return 0;
}
