/*
    MENU-DRIVEN PROGRAM FOR A SIMPLE QUEUE USING AN ARRAY IN C
    CREATED BY - RAHUL TAWAR

    DESCRIPTION:
    - This program implements a menu-driven approach for performing
      basic queue operations using an array.

    - Supported operations:
        * Enqueue  (Insert an element into the queue)
        * Dequeue  (Remove an element from the queue)
        * Display  (Show all elements in the queue)
        * Check if the queue is Empty
        * Check if the queue is Full

    - The queue follows FIFO (First In, First Out) principle.
    - It has a fixed maximum size defined by SIZE.
*/

#include <stdio.h>
#define SIZE 20
#define ERROR_VALUE -99999 // Unique error value for dequeue

int queue[SIZE];
int front = -1, rear = -1;

void menu()
{
    printf("==== Simple Queue Menu ====\n");
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
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full. Try again later!\n");
        return -1;
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = element;
        return 1;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty. Try again later!\n");
        return ERROR_VALUE;
    }
    else
    {
        int element = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;

        printf("\nDequeued successfully: %d\n", element);
        return element;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty. Nothing to display!\n");
    }
    else
    {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return (rear == SIZE - 1);
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
            if (enqueue(element) == 1)
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
            break;
        case 3: // DISPLAY
            display();
            break;
        case 4: // IS EMPTY
            if (isEmpty())
                printf("\nThe queue is empty.\n");
            else
                printf("\nThe queue is not empty.\n");
            break;
        case 5: // IS FULL
            if (isFull())
                printf("\nThe queue is full.\n");
            else
                printf("\nThe queue is not full.\n");
            break;
        case 6: // EXIT
            printf("\nThank you for using this program!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}