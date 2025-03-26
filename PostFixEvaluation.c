/*
    MENU-DRIVEN PROGRAM FOR POSTFIX EXPRESSION EVALUATION IN C
    CREATED BY - RAHUL TAWAR
    DESCRIPTION:
        - This program evaluates a given postfix expression using a stack.
        - It supports basic arithmetic operations: +, -, *, /
        - The user can enter a valid postfix expression, and the program will compute the result.
*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 20  // MAXIMUM STACK SIZE
int stack[SIZE]; // ARRAY TO STORE STACK ELEMENTS
int top = -1;    // STACK INITIALIZED AS EMPTY

void push(int element)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
    }
    else
    {
        stack[++top] = element;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Invalid expression.\n");
        return -1;
    }
    return stack[top--];
}

int evaluate(int operand1, int operand2, char operator)
{
    switch (operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0)
        {
            printf("Error: Division by zero!\n");
            return 0;
        }
        return operand1 / operand2;
    default:
        printf("Invalid operator: %c\n", operator);
        return 0;
    }
}

void evaluatePostfix(char expression[])
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(expression[i] - '0'); // Convert char to int
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            if (operand1 == -1 || operand2 == -1)
            {
                printf("Invalid postfix expression!\n");
                return;
            }
            push(evaluate(operand1, operand2, expression[i]));
        }
    }
    printf("\nResult of Postfix Evaluation: %d\n", stack[top]);
}

int main()
{
    char expression[SIZE];
    printf("\nEnter a valid postfix expression (single digits only): ");
    scanf("%s", expression);
    evaluatePostfix(expression);
    return 0;
}
