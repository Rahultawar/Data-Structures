/*
    MENU-DRIVEN PROGRAM FOR A CIRCULAR QUEUE USING LINKED LIST IN C
    CREATED BY - RAHUL TAWAR

    DESCRIPTION:
    - This program implements a menu-driven approach for performing
      basic queue operations using a linked list.

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

typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

void menu() {
    printf("==== Simple Queue Menu ====\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Check if Queue is Empty\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

int enqueue(int element) {
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return 0;
    }
    newNode->data = element;
    newNode->next = front;

    if (rear == NULL) {
        front = rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    }
    return 1;
}

int dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty. Nothing to dequeue!\n");
        return ERROR_VALUE;
    }
    else {
        Queue *node = front;
        int element = node->data;
        
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }
        free(node);
        return element;
    }
}

void display() {
    Queue *node;
    if (front == NULL) {
        printf("\nQueue is empty. Nothing to display!\n");
    }
    else {
        printf("\nQueue elements: ");
        node = front;
        do {
            printf("%d ", node->data);
            node = node->next;
        } while (node != front);
        printf("\n"); 
    }
}


int isEmpty() {
    return (front == NULL);
}

void freeQueue() {
    if (front == NULL)
        return;

    Queue *current = front;
    Queue *nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != front);

    front = rear = NULL;
}


int main() {
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
            if (enqueue(element)) {
                printf("\n%d enqueued successfully!\n", element);
            }
            else {
                printf("\nEnqueue operation failed.\n");
            }
            break;
        case 2: // DEQUEUE
            element = dequeue();
            if (element == ERROR_VALUE) {
                printf("\nDequeue operation failed.\n");
            }
            else {
                printf("\n%d dequeued successfully!\n", element);
            }
            break;
        case 3: // DISPLAY
            display();
            break;
        case 4: // IS EMPTY
            printf("\nThe queue is %s.\n", isEmpty() ? "empty" : "not empty");
            break;
        case 5: // EXIT
            printf("\nCleaning up memory before exiting...\n");
            freeQueue();
            printf("Thank you for using this program!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}