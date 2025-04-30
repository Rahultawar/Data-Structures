/*
    MENU-DRIVEN PROGRAM FOR A CIRCULAR QUEUE USING ARRAY IN C
    CREATED BY - RAHUL TAWAR

    DESCRIPTION:
    - This program implements a menu-driven approach for performing
      basic queue operations using an array.

    - Supported operations:
        * Enqueue  (Insert an element into the queue)
        * Dequeue  (Remove an element from the queue)
        * Display  (Show all elements in the queue)
        * Check if the queue is empty

    - The queue follows the FIFO (First In, First Out) principle.
*/

#include <stdio.h>
#include <stdlib.h>
#define ERROR_VALUE -99999 // Unique error value for dequeue
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void menu()
{
    printf("==== Circular Queue Menu ====\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Check if Queue is Empty\n");
    printf("5. Check if Queue is Full\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
}

int enqueue(int element)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("\nQueue is full. Try again later!\n");
        return 0;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = element;
        return 1;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
        return 1;
    }
}

int dequeue()
{
    int element;
    if (front == -1)
    {
        printf("\nQueue is empty. Nothing to dequeue!\n");
        return ERROR_VALUE;
    }
    else if (rear == front)
    {
        element = queue[front];
        front = rear = -1;
    }
    else
    {
        element = queue[front];
        front = (front + 1) % SIZE;
    }
    return element;
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty. Nothing to display!\n");
    }
    else
    {
        printf("\nQueue elements: ");
        int i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        printf("\n");
    }
}

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return ((rear + 1) % SIZE == front);
}

int main()
{
    int choice, element;
    do
    {
        printf("\n");
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // ENQUEUE
            printf("\nEnter the element to enqueue: ");
            scanf("%d", &element);
            if (enqueue(element))
            {
                printf("\n%d enqueued successfully!\n", element);
            }
            else
            {
                printf("\nEnqueue operation failed.\n");
            }
            break;
        case 2: // DEQUEUE
            element = dequeue();
            if (element == ERROR_VALUE)
            {
                printf("\nDequeue operation failed.\n");
            }
            else
            {
                printf("\n%d dequeued successfully!\n", element);
            }
            break;
        case 3: // DISPLAY
            display();
            break;
        case 4: // IS EMPTY
            printf("\nThe queue is %s.\n", isEmpty() ? "empty" : "not empty");
            break;
        case 5: // IS FULL
            printf("\nThe queue is %s.\n", isFull() ? "full" : "not full");
            break;
        case 6: // EXIT
            printf("Thank you for using this program!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}