/*
    MENU DRIVEN PROGRAM OF CIRCULAR LINKED LIST IN C
    CREATED BY - RAHUL TAWAR
    DESCRIPTION:
        - This program implements a menu-driven approach for
          circular linked list operations including:
            * Creation
            * Insertion (Start, End, Position)
            * Deletion (Start, End, Position)
            * Search
            * Reverse
*/
#include <stdio.h>
#include <stdlib.h>

// NODE STRUCTURE FOR CURCULAR LINKED LIST
typedef struct Node {
    struct Node *next;
    int data;
} Node;

// GLOBAL LINKED LIST HEADS
Node *HEAD = NULL;        // COMMON HEAD
Node *head = NULL;        // HEAD OF PRIMARY LINKED LIST
Node *anotherHead = NULL; // HEAD OF SECONDARY LINKED LIST

void menu() {   // MAIN MENU 
    printf("\n==== Circular Linked List Menu ====\n");
    printf("1. Create Linked List : \n");
    printf("2. Display Linked List : \n");
    printf("3. Insert Operation : \n");
    printf("4. Delete Operation : \n");
    printf("5. Reverse Linked List : \n");
    printf("6. Search : \n");
    printf("7. Exit : \n\n");
    printf("Input your choice : ");
}

void createMenu() { // CREATE MENU
    printf("1. Create Linked List : \n");
    printf("2. Create Another Linked List : \n");
    printf("3. Exit : \n\n");
    printf("Input your choice : ");
}

void displayMenu() { // DISPLAY MENU
    printf("1. Display Linked List : \n");
    printf("2. Display Another Linked List : \n");
    printf("3. Exit : \n\n");
    printf("Input your choice : ");
}

void insertMenu() { // INSERT OPERATION MENU
    printf("1. Insert At Start : \n");
    printf("2. Insert At End : \n");
    printf("3. Insert At Position : \n");
    printf("4. Exit : \n\n");
    printf("Input your choice : ");
}

void deleteMenu() { // DELETE OPERATION MENU
    printf("1. Delete At Start : \n");
    printf("2. Delete At End : \n");
    printf("3. Delete At Position : \n");
    printf("4. Exit : \n\n");
    printf("Input your choice : ");
}

Node *create(Node *HEAD, int noOfElement) {
    Node *nextNode;
    for (int i = 0; i < noOfElement; i++) {
        if (HEAD == NULL) {
            HEAD = (Node *)malloc(sizeof(Node));
            printf("Input any integer data : ");
            scanf("%d", &HEAD->data);
            HEAD->next = HEAD;
            nextNode = HEAD;
        }
        else {
            nextNode->next = (Node *)malloc(sizeof(Node));
            nextNode = nextNode->next;
            printf("Input any integer data : ");
            scanf("%d", &nextNode->data);
            nextNode->next = HEAD;
        }
    }
    printf("\n");
    return HEAD;
}

void display(Node *HEAD) {
    Node *node;
    node = HEAD;
    do {
        printf("%d ", node->data);
        node = node->next;
    } while (node != HEAD);
    printf("\n\n");
}

Node *insertStart(Node *HEAD, int data) {
    Node *newNode, *node;
    if (HEAD != NULL) {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = HEAD;
        node = HEAD;
        while (node->next != HEAD) {
            node = node->next;
        }
        node->next = newNode;
        HEAD = newNode;
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *insertEnd(Node *HEAD, int data) {
    Node *endNode;
    if (HEAD != NULL) {
        endNode = HEAD;
        while (endNode->next != HEAD) {
            endNode = endNode->next;
        }
        endNode->next = (Node *)malloc(sizeof(Node));
        endNode->next->data = data;
        endNode->next->next = HEAD;
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *insertPosition(Node *HEAD, int position) {
    Node *node, *newNode;
    if (HEAD != NULL) {
        node = HEAD;
        for (int i = 1; i < position - 1; i++) {
            node = node->next;
            if (node->next == HEAD)
                break;
        }
        newNode = (Node *)malloc(sizeof(Node));
        printf("Input data you want to insert : \n");
        scanf("%d", &newNode->data);
        newNode->next = node->next;
        node->next = newNode;
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *deleteStart(Node *HEAD) {
    Node *node, *endNode;
    if (HEAD != NULL) {
        node = HEAD;
        endNode = HEAD;
        while (endNode->next != HEAD) {
            endNode = endNode->next;
        }
        HEAD = node->next;
        endNode->next = HEAD;
        free(node);
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *deleteEnd(Node *HEAD) {
    Node *endNode;
    if (HEAD != NULL) {
        endNode = HEAD;
        while (endNode->next->next != HEAD) {
            endNode = endNode->next;
        }
        endNode->next = HEAD;
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *deletePosition(Node *HEAD, int position) {
    Node *node;
    if (HEAD != NULL) {
        node = HEAD;
        for (int i = 1; i < position - 1; i++) {
            node = node->next;
        }
        node->next = node->next->next;
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

int search(Node *HEAD, int data) {
    Node *node;
    int position = 1;
    if (HEAD != NULL) {
        node = HEAD;
        do {
            position++;
            if (node->data == data) {
                return position;
            }
            node = node->next;
        } while (node != HEAD);
    }
    else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
}

Node *reverse(Node *HEAD) {
    if (HEAD != NULL) {
        Node *prevNode = NULL;
        Node *currentNode = HEAD;
        Node *nextNode = NULL;
        Node *lastNode = HEAD;

        while (lastNode->next != HEAD) {
            lastNode = lastNode->next;
        }

        do {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        } while (currentNode != HEAD);

        HEAD->next = prevNode;
        HEAD = prevNode;
    }
    else{
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

void main() {
    int choice, insertChoice, deleteChoice, createChoice, displayChoice, data, position, noOfElement, choiceLL;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // CREATE LINKED LIST
            do
            {
                createMenu();
                scanf("%d", &createChoice);
                switch (createChoice)
                {
                case 1: // CREATE LINKED LIST
                    printf("How many element you want to create a linked list : \n");
                    scanf("%d", &noOfElement);
                    head = create(head, noOfElement);
                    break;
                case 2: // CREATE ANOTHER LINKED LIST
                    printf("How many element you want to create a linked list : \n");
                    scanf("%d", &noOfElement);
                    anotherHead = create(anotherHead, noOfElement);
                    break;
                case 3: // EXIT
                    printf("\nThank you for using creation of linked list...\n\n");
                    break;
                default:
                    printf("\nWrong choice. Try again later\n\n");
                    break;
                }
            } while (createChoice != 3);
            break;
        case 2: // DISPLAY LINKED LIST
            do
            {
                displayMenu();
                scanf("%d", &displayChoice);
                switch (displayChoice)
                {
                case 1: // DISPLAY LINKED LIST
                    if (head == NULL) {
                        printf("Linked List is empty!. Insert some element and Try again..\n");
                    }
                    else {
                        printf("\nDisplaying Linked List : \n");
                        display(head);
                    }
                    break;
                case 2: // DISPLAY ANOTHER LINKED LIST
                    if (anotherHead == NULL) {
                        printf("Linked List is empty!. Insert some element and Try again..\n");
                    }
                    else {
                        printf("\nDisplaying Another Linked List : \n");
                        display(anotherHead);
                    }
                    break;
                case 3: // EXIT
                    printf("\nThank you for using displaying linked list...\n\n");
                    break;
                default:
                    printf("\nWrong choice. Try again later\n\n");
                    break;
                }
            } while (displayChoice != 3);
            break;
        case 3: // INSERT OPERATION
            do
            {
                insertMenu();
                scanf("%d", &insertChoice);
                switch (insertChoice)
                {
                case 1: // INSERT AT START
                    printf("Input data you want to insert at start of Linked List : \n");
                    scanf("%d", &data);
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = insertStart(head, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }
                    else if (choiceLL == 2) {
                        anotherHead = insertStart(anotherHead, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }
                    else {
                        printf("Wrong choice. Try again later..\n\n");
                    }
                    break;
                case 2: // INSERT AT END
                    printf("Input data you want to insert at end of Linked List : \n");
                    scanf("%d", &data);
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = insertEnd(head, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }
                    else if (choiceLL == 2) {
                        anotherHead = insertEnd(anotherHead, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }
                    else {
                        printf("\nWrong choice. Try again later..\n\n");
                    }
                    break;
                case 3: // INSERT AT POSITION
                    printf("Input position you want to insert : \n");
                    scanf("%d", &position);
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = insertPosition(head, position);
                        printf("\nInsert Operation Successfull at Position %d\n\n", position);
                    }
                    else if (choiceLL == 2) {
                        anotherHead = insertPosition(anotherHead, position);
                        printf("\nInsert Operation Successfull at Position %d\n\n", position);
                    }
                    else {
                        printf("Wrong choice. Try again later..\n\n");
                    }
                    break;
                case 4: // EXIT
                    printf("\nThank you for using insert operation...\n\n");
                    break;
                default:
                    printf("\nWrong choice. Try again later\n\n");
                    break;
                }
            } while (insertChoice != 4);
            break;
        case 4: // DELETE OPERATION
            do
            {
                deleteMenu();
                scanf("%d", &deleteChoice);
                switch (deleteChoice)
                {
                case 1: // DELETE AT START
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = deleteStart(head);
                        printf("\nDelete Operation Successfull...\n\n");
                    }
                    else if (choiceLL == 2) {
                        anotherHead = deleteStart(anotherHead);
                        printf("\nDelete Operation Successfull...\n\n");
                    }
                    else {
                        printf("\nWrong choice. Try again later..\n\n");
                    }
                    break;
                case 2: // DELETE AT END
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = deleteEnd(head);
                        printf("\nDelete Operation Successfull...\n\n");
                    }
                    else if (choiceLL == 2) {
                        anotherHead = deleteEnd(anotherHead);
                        printf("\nDelete Operation Successfull...\n\n");
                    }
                    else {
                        printf("\nWrong choice. Try again later..\n\n");
                    }
                    break;
                case 3: // DELETE AT POSITION
                    printf("Input position you want to delete : \n");
                    scanf("%d", &position);
                    printf("Which Linked List you want to do delete operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = deletePosition(head, position);
                        printf("\nDelete Operation Successfull at Position %d\n\n", position);
                    }
                    else if (choiceLL == 2) {
                        anotherHead = deletePosition(anotherHead, position);
                        printf("\nDelete Operation Successfull at Position %d\n\n", position);
                    }
                    else {
                        printf("\nWrong choice. Try again later..\n\n");
                    }
                    break;
                case 4: // EXIT
                    printf("\nThank you for using delete operation...\n\n");
                    break;
                default:
                    printf("\n\nWrong choice. Try again later\n\n");
                    break;
                }
            } while (deleteChoice != 4);
            break;
        case 5: // REVERSE
            printf("Which Linked List you want to reverse \n1. Primary Linked List \n2. Seconday Linked List\n");
            scanf("%d", &choiceLL);
            if (choiceLL == 1) {
                head = reverse(head);
                printf("\nReverse Successfull...\n");
            }
            else if (choiceLL == 2) {
                anotherHead = reverse(anotherHead);
                printf("\nReverse Successfull...\n");
            }
            else {
                printf("\nWrong choice. Try again later..\n");
            }
            break;
        case 6: // SEARCH
            printf("Which Linked List you want to do search operation \n1. Primary Linked List \n2. Seconday Linked List\n");
            scanf("%d", &choiceLL);
            printf("Input data you want to search : \n");
            scanf("%d", &data);
            if (choiceLL == 1) {
                position = search(head, data);
                printf("\n%d found in linked list at position %d\n", data, position - 1);
            }
            else if (choiceLL == 2) {
                position = search(anotherHead, data);
                printf("\n%d found in linked list at position %d\n", data, position - 1);
            }
            else {
                printf("\nWrong choice. Try again later..\n");
            }
            break;
        case 7: // EXIT
            printf("\nThank you for using program...\n");
            break;

        default:
            printf("\n\nWrong choice. Try again later\n\n");
            break;
        }
    } while (choice != 7);
}