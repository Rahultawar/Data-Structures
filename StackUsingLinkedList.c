/*
    MENU-DRIVEN PROGRAM FOR STACK USING LINKED LIST IN C
    CREATED BY - RAHUL TAWAR
    DESCRIPTION:
        - This program implements a menu-driven approach for
          stack operations using a linked list, including:
            * Push (Insert an element onto the stack)
            * Pop (Remove the top element from the stack)
            * Peek (View the top element without removing it)
            * Checking if the stack is empty
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct LinkedList // STRUCT OF A NODE IN THE LINKED LIST
{
    struct LinkedList *next;
    int data;
} LinkedList;

LinkedList *top = NULL; // POINTER TO THE TOP OF STACK

void menu() // MAIN MENU
{
    printf("\n==== STACK USING LINKED LIST MENU ====\n");
    printf("1. Push Element on Stack\n");
    printf("2. Pop Element from Stack\n");
    printf("3. Peek Element on Stack\n");
    printf("4. Check if Stack is Empty\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// FUNCTION TO PUSH AN ELEMENT ONTO THE STACK
void push(int element)
{
    LinkedList *node;
    node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = element;
    node->next = top;
    top = node;
}

// FUNCTION TO POP AN ELEMENT FROM THE STACK
int pop()
{
    int element;
    element = top->data;
    top = top->next;
    return element;
}

// FUNCTION TO PEEK AT THE TOPMOST ELEMENT
int peek()
{
    return top->data;
}

void main()
{
    int choice, element;

    do
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // PUSH ELEMENT ON STACK
            printf("Input the element you want to push onto the stack: ");
            scanf("%d", &element);
            push(element);
            printf("\n%d has been pushed successfully.\n", element);
            break;

        case 2: // POP ELEMENT FROM STACK
            if (top == NULL) {
                printf("\nThe stack is empty. Try again after pushing an element.\n");
            }else {
                element = pop();
                printf("\n%d was successfully popped from the stack.\n", element);
            }
            break;

        case 3: // PEEK ELEMENT ON STACK
            if (top == NULL) {
                printf("\nThe stack is empty. Try again after pushing an element.\n");
            }else {
                element = peek();
                printf("\nThe topmost element on the stack is %d.\n", element);
            }
            break;

        case 4: // CHECK IF STACK IS EMPTY
            if (top == NULL) {
                printf("\nYes, the stack is empty right now.\n");
            }else {
                printf("\nNo, the stack contains elements.\n");
            }
            break;

        case 5: // EXIT
            printf("\nThank you for using the program.\n");
            break;

        default:
            printf("\nWrong choice. Try again!\n");
            break;
        }
    } while (choice != 5);
}