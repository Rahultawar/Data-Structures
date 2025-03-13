/*
    MENU-DRIVEN PROGRAM FOR STACK USING ARRAY IN C
    CREATED BY - RAHUL TAWAR
    DESCRIPTION:
        - This program implements a menu-driven approach for
          stack operations using an array, including:
            * Push (Insert an element onto the stack)
            * Pop (Remove the top element from the stack)
            * Peek (View the top element without removing it)
            * Checking if the stack is empty
            * Checking if the stack is full
*/
#include <stdio.h>
#include <conio.h>
#define SIZE 5 // MAXIMUM SIZE OF STACK

int stack[SIZE]; // ARRAY TO STORE STACK ELEMENTS
int top = -1;    // TOP AS -1 (STACK IS EMPTY)

void menu() // MAIN MENU
{
    printf("\n==== STACK WITH ARRAY MENU ====\n");
    printf("1. Push Element on Stack\n");
    printf("2. Pop Element from Stack\n");
    printf("3. Peek Element on Stack\n");
    printf("4. Check if Stack is Empty\n");
    printf("5. Check if Stack is Full\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void push(int element) // FUNCTION TO PUSH AN ELEMENT ONTO THE STACK
{
    top++;
    stack[top] = element;
}

int pop() // FUNCTION TO POP AN ELEMENT FROM THE STACK
{
    int element = stack[top];
    top--;
    return element;
}

int peek() // FUNCTION TO PEEK AT THE TOPMOST ELEMENT
{
    return stack[top];
}

void main() {
    int choice, element;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: // PUSH ELEMENT ON STACK
            if (top == SIZE - 1) {
                printf("\nThe stack is already full. Please try again later.\n");
            }else {
                printf("Input the element you want to push onto the stack: ");
                scanf("%d", &element);
                push(element);
                printf("\n%d has been pushed successfully.\n", element);
            }
            break;

        case 2: // POP ELEMENT FROM STACK
            if (top == -1) {
                printf("\nThe stack is empty. Try again after pushing an element.\n");
            }else {
                element = pop();
                printf("\n%d was successfully popped from the stack.\n", element);
            }
            break;

        case 3: // PEEK ELEMENT ON STACK
            if (top == -1) {
                printf("\nThe stack is empty. Try again after pushing an element.\n");
            }else {
                element = peek();
                printf("\nThe topmost element on the stack is %d.\n", element);
            }
            break;

        case 4: // CHECK IF STACK IS EMPTY
            if (top == -1) {
                printf("\nYes, the stack is empty right now.\n");
            }else {
                printf("\nNo, the stack contains elements.\n");
            }
            break;

        case 5: // CHECK IF STACK IS FULL
            if (top == SIZE - 1) {
                printf("\nYes, the stack is full right now.\n");
            }else {
                printf("\nNo, the stack is not full yet.\n");
            }
            break;

        case 6: // EXIT
            printf("\nThank you for using the program.\n");
            break;

        default:
            printf("\nWrong choice. Try again!\n");
            break;
        }
    } while (choice != 6);
}