
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice == 1) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

void deleteSpecified() {
    struct node *temp, *prev;
    int value;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;
    prev = NULL;

    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;
    printf("NAME:DANESH M MISENNAVAR\n");
    printf("USN:1WA25CS062\n");

    while (1) {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

