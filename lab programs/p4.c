#include <stdio.h>
#define SIZE 10
char stack[SIZE];
int top = -1;
void push(char elem)
{
	++top;
	stack[top] = elem;
}
char pop()
{
	return (stack[top--]);
}
int precedence(char elem) /* Function for precedence */
{
	switch (elem)
	{
		case '#': return 0;
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/':
		case '%': return 3;
		case '$':
		case '^': return 4;
	}
return elem; 
}
void main() {
	char infix[50], postfix[50], ch, elem;
	int i = 0, k = 0;
    printf("Name-ATUL RAJ \n USN-1AY23BECS045\n");
	printf("\n\nEnter the Infix Expression: ");
	scanf("%s", infix);
	push('#'); //first item we have to push is # to show empty stack 
	while ((ch = infix[i++]) != '\0')
	{
		if (ch == '(')
			push(ch);
		else if (isalnum(ch))
			postfix[k++] = ch;
		else if (ch == ')')
		{
			while (stack[top] != '(')
				postfix[k++] = pop();
			elem = pop(); /* Remove ( */
		}
		else /* Operator */
		{
		while (precedence(stack[top]) >= precedence(ch))
			postfix[k++] = pop();
			push(ch);
		}
	}
	while (stack[top] != '#'){ /* Pop from stack till empty */
		postfix[k++] = pop();
	}
	postfix[k] = '\0'; /* Make pofx as valid string */
	printf("\nGiven Infix Expression is: %s\n",infix);
	printf("\nPostfix Expression is: %s\n", postfix);

}