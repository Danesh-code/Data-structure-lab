
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create(struct node *head, int n) {
    struct node *newnode, *temp;

    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node* concatenate(struct node *head1,
                         struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n, choice;

    printf("NAME:Danesh M Misennavar\n");
    printf("USN:1WA25CS062\n");

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    head1 = create(head1, n);

    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &n);
    head2 = create(head2, n);

    do {
        printf("\n1. Display");
        printf("\n2. Sort");
        printf("\n3. Reverse");
        printf("\n4. Concatenate");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(head1);
                break;

            case 2:
                head1 = sort(head1);
                printf("Sorted list:\n");
                display(head1);
                break;

            case 3:
                head1 = reverse(head1);
                printf("Reversed list:\n");
                display(head1);
                break;

            case 4:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Concatenated list:\n");
                display(head1);
                break;

            case 5:
                printf("Exiting");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}

