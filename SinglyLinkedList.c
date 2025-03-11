/*
    MENU DRIVEN PROGRAM OF SINGLY LINKED LIST IN C
    CREATED BY - RAHUL TAWAR
    DESCRIPTION:
        - This program implements a menu-driven approach for
          singly linked list operations including:
            * Creation
            * Insertion (Start, End, Position)
            * Deletion (Start, End, Position)
            * Search
            * Reverse
            * Sorting
            * Merging
            * Finding Intersection
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// NODE STRUCTURE FOR SINGLY LINKED LIST
typedef struct Node{
    struct Node *next;
    int data;
} Node;

// GLOBAL LINKED LIST HEADS
Node *HEAD = NULL;          // COMMON HEAD
Node *head = NULL;          // HEAD OF PRIMARY LINKED LIST
Node *anotherHead = NULL;   // HEAD OF SECONDARY LINKED LIST
Node *thirdHead = NULL;     // HEAD OF UNION, MERGE LINKED LIST
Node *intersectHead = NULL; // HEAD OF INTERSECTION LINKED LIST

void menu() // MAIN MENU
{
    printf("\n==== Singly Linked List Menu ====\n");
    printf("1. Create Linked List : \n");
    printf("2. Display Linked List : \n");
    printf("3. Insert Operation : \n");
    printf("4. Delete Operation : \n");
    printf("5. Reverse Linked List : \n");
    printf("6. Search : \n");
    printf("7. Sort : \n");
    printf("8. Merge Two Linked List : \n");
    printf("9. Union Two Linked List : \n");
    printf("10. Intersection Two Linked List : \n");
    printf("11. Exit : \n\n");
    printf("Input your choice : ");
}

void createMenu() // CREATE MENU
{
    printf("1. Create Linked List : \n");
    printf("2. Create Another Linked List : \n");
    printf("3. Exit : \n\n");
    printf("Input your choice : ");
}

void displayMenu() // DISPLAY MENU
{
    printf("1. Display Linked List : \n");
    printf("2. Display Another Linked List : \n");
    printf("3. Exit : \n\n");
    printf("Input your choice : ");
}

void insertMenu() // INSERT OPERATION MENU
{
    printf("1. Insert At Start : \n");
    printf("2. Insert At End : \n");
    printf("3. Insert At Position : \n");
    printf("4. Exit : \n\n");
    printf("Input your choice : ");
}

void deleteMenu() // DELETE OPERATION MENU
{
    printf("1. Delete At Start : \n");
    printf("2. Delete At End : \n");
    printf("3. Delete At Position : \n");
    printf("4. Exit : \n\n");
    printf("Input your choice : ");
}

Node *create(Node *HEAD, int noOfElement) {
    Node *nextNode;
    for (int i = 0; i < noOfElement; i++){
        if (HEAD == NULL){
            HEAD = (Node *)malloc(sizeof(Node));
            printf("Input any integer data : ");
            scanf("%d", &HEAD->data);
            HEAD->next = NULL;
            nextNode = HEAD;
        }else {
            nextNode->next = (Node *)malloc(sizeof(Node));
            nextNode = nextNode->next;
            printf("Input any integer data : ");
            scanf("%d", &nextNode->data);
            nextNode->next = NULL;
        }
    }
    printf("\n");
    return HEAD;
}

void display(Node *HEAD) {
    Node *node;
    node = HEAD;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n\n");
}

Node *insertStart(Node *HEAD, int data) {
    Node *node;
    if (HEAD != NULL) {
        node = (Node *)malloc(sizeof(Node));
        node->next = HEAD;
        node->data = data;
        HEAD = node;
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *insertEnd(Node *HEAD, int data) {
    Node *node, *endNode;
    if (HEAD != NULL) {
        node = HEAD;
        while (node->next != NULL) {
            node = node->next;
        }
        endNode = (Node *)malloc(sizeof(Node));
        node->next = endNode;
        endNode->data = data;
        endNode->next = NULL;
    }else {
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
        }
        newNode = (Node *)malloc(sizeof(Node));
        printf("Input data you want to insert : \n");
        scanf("%d", &newNode->data);
        newNode->next = node->next;
        node->next = newNode;
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *deleteStart(Node *HEAD) {
    Node *node;
    if (HEAD != NULL) {
        node = HEAD;
        HEAD = node->next;
        free(node);
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

Node *deleteEnd(Node *HEAD)
{
    Node *node;
    if (HEAD != NULL) {
        node = HEAD;
        while (node->next->next != NULL) {
            node = node->next;
        }
        node->next = NULL;
    }else {
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
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

int search(Node *HEAD, int data) {
    Node *node;
    int position = 1;
    if (HEAD != NULL) {
        for (node = HEAD; node != NULL; node = node->next) {
            position++;
            if (node->data == data) {
                return position;
            }
        }
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
}

void sort(Node *HEAD) {
    Node *node, *nextNode;
    int temp = 0;
    if (HEAD != NULL) {
        for (node = HEAD; node != NULL; node = node->next) {
            for (nextNode = node->next; nextNode != NULL; nextNode = nextNode->next) {
                if (node->data > nextNode->data) {
                    temp = node->data;
                    node->data = nextNode->data;
                    nextNode->data = temp;
                }
            }
        }
        printf("\nLinked List Sorted Successfull...\n\n");
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
}

Node *copy(Node *HEAD) {
    Node *node, *nextNode;
    if (HEAD != NULL) {
        for (node = HEAD; node != NULL; node = node->next) {
            if (thirdHead == NULL) {
                thirdHead = (Node *)malloc(sizeof(malloc));
                thirdHead->data = node->data;
                thirdHead->next = NULL;
                nextNode = thirdHead;
            }else {
                nextNode->next = (Node *)malloc(sizeof(malloc));
                nextNode = nextNode->next;
                nextNode->data = node->data;
                nextNode->next = NULL;
            }
        }
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return thirdHead;
}

Node *reverse(Node *HEAD) {
    Node *prevNode, *currentNode, *nextNode;
    if (HEAD != NULL) {
        prevNode = NULL;
        currentNode = HEAD;
        nextNode = currentNode->next;
        while (currentNode != NULL) {
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
            if (nextNode != NULL) {
                nextNode = nextNode->next;
            }
        }
        HEAD = prevNode;
    }else {
        printf("Linked List is Empty. Insert some element and Try again..\n");
    }
    return HEAD;
}

void merge(Node *head, Node *anotherHead)
{
    if (head != NULL && anotherHead != NULL){
        thirdHead = copy(head);
        thirdHead = copy(anotherHead);
    }else {
        printf("One or both lists are empty. Merge operation failed!\n");
    }
}

Node *removeDuplicate(Node *HEAD){
    Node *node, *nextNode;
    int position, innerPosition;

    if (HEAD != NULL){
        for (node = HEAD, position = 1; node != NULL; node = node->next, position++){
            Node *prev = node;
            innerPosition = position + 1;

            for (nextNode = node->next; nextNode != NULL;){
                if (node->data == nextNode->data) {
                    HEAD = deletePosition(HEAD, innerPosition);
                    nextNode = prev->next;
                }else {
                    prev = nextNode;
                    nextNode = nextNode->next;
                    innerPosition++;
                }
            }
        }
    }else {
        printf("One or both lists are empty. Try again later!\n");
    }
    return HEAD;
}

void intersection(Node *head, Node *anotherHead) { 
    Node *node, *node2, *nextNode;
    if (head != NULL && anotherHead != NULL) {
        for (node = head; node != NULL; node = node->next) {
            for (node2 = anotherHead; node2 != NULL; node2 = node2->next) {
                if (node->data == node2->data) {
                    if (intersectHead == NULL) {
                        intersectHead = (Node *)malloc(sizeof(Node));
                        intersectHead->data = node->data;
                        intersectHead->next = NULL;
                        nextNode = intersectHead;
                    }else {
                        nextNode->next = (Node *)malloc(sizeof(Node));
                        nextNode = nextNode->next;
                        nextNode->data = node->data;
                        nextNode->next = NULL;
                    }
                }
            }
        }
    }else {
        printf("One or both lists are empty. Cannot find intersection!\n");
    }
}

void main() {
    int choice, insertChoice, deleteChoice, createChoice, displayChoice, data, position, noOfElement, choiceLL;
    do 
    {
        menu();
        scanf("%d", &choice);
        switch (choice) {
        case 1: // CREATE LINKED LIST
            do
            {
                createMenu();
                scanf("%d", &createChoice);
                switch (createChoice) {
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
                switch (displayChoice) {
                case 1: // DISPLAY LINKED LIST
                    if (head == NULL) {
                        printf("Linked List is empty!. Insert some element and Try again..\n");
                    }else {
                        printf("\nDisplaying Linked List : \n");
                        display(head);
                    }
                    break;
                case 2: // DISPLAY ANOTHER LINKED LIST
                    if (anotherHead == NULL) {
                        printf("Linked List is empty!. Insert some element and Try again..\n");
                    }else {
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
                switch (insertChoice) {
                case 1: // INSERT AT START
                    printf("Input data you want to insert at start of Linked List : \n");
                    scanf("%d", &data);
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = insertStart(head, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }else if (choiceLL == 2) {
                        anotherHead = insertStart(anotherHead, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }else {
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
                    }else if (choiceLL == 2) {
                        anotherHead = insertEnd(anotherHead, data);
                        printf("\nInsert Operation Successfull..\n\n");
                    }else {
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
                    }else if (choiceLL == 2) {
                        anotherHead = insertPosition(anotherHead, position);
                        printf("\nInsert Operation Successfull at Position %d\n\n", position);
                    }else {
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
                switch (deleteChoice) {
                case 1: // DELETE AT START
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = deleteStart(head);
                        printf("\nDelete Operation Successfull...\n\n");
                    }else if (choiceLL == 2) {
                        anotherHead = deleteStart(anotherHead);
                        printf("\nDelete Operation Successfull...\n\n");
                    }else {
                        printf("\nWrong choice. Try again later..\n\n");
                    }
                    break;
                case 2: // DELETE AT END
                    printf("Which Linked List you want to do insert operation \n1. Primary Linked List \n2. Seconday Linked List\n");
                    scanf("%d", &choiceLL);
                    if (choiceLL == 1) {
                        head = deleteEnd(head);
                        printf("\nDelete Operation Successfull...\n\n");
                    }else if (choiceLL == 2) {
                        anotherHead = deleteEnd(anotherHead);
                        printf("\nDelete Operation Successfull...\n\n");
                    }else {
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
                    }else if (choiceLL == 2) {
                        anotherHead = deletePosition(anotherHead, position);
                        printf("\nDelete Operation Successfull at Position %d\n\n", position);
                    }else {
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
                printf("\nReverse Successfull...\n\n");
            }else if (choiceLL == 2) {
                anotherHead = reverse(anotherHead);
                printf("\nReverse Successfull...\n\n");
            }else {
                printf("\nWrong choice. Try again later..\n\n");
            }
            break;
        case 6: // SEARCH
            printf("Which Linked List you want to do search operation \n1. Primary Linked List \n2. Seconday Linked List\n");
            scanf("%d", &choiceLL);
            printf("Input data you want to search : \n");
            scanf("%d", &data);
            if (choiceLL == 1) {
                position = search(head, data);
                printf("%d found in linked list at position %d\n\n", data, position - 1);
            }else if (choiceLL == 2) {
                position = search(anotherHead, data);
                printf("%d found in linked list at position %d\n\n", data, position - 1);
            }else {
                printf("\nWrong choice. Try again later..\n\n");
            }
            break;
        case 7: // SORT
            printf("Which Linked List you want to do sort \n1. Primary Linked List \n2. Seconday Linked List\n");
            scanf("%d", &choiceLL);
            if (choiceLL == 1) {
                sort(head);
            }else if (choiceLL == 2) {
                sort(anotherHead);
            }else {
                printf("\nWrong choice. Try again later..\n\n");
            }
            break;
        case 8: // MERGE TWO LINKED LIST
            merge(head, anotherHead);
            printf("\nMerged Linked list : \n");
            display(thirdHead);
            break;
        case 9: // UNION TWO LINKED LIST
            merge(head, anotherHead);
            thirdHead = removeDuplicate(thirdHead);
            printf("\nUnion : \n");
            display(thirdHead);
            break;
        case 10: // INTERSECTION TWO LINKED LIST
            intersection(head, anotherHead);
            printf("\nIntersection : \n");
            display(intersectHead);
            break;
        case 11: // EXIT
            printf("\nThank you for using program...\n");
            break;

        default:
            printf("\n\nWrong choice. Try again later\n\n");
            break;
        }
    } while (choice != 11);
}