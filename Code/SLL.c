#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

typedef struct Node *NODE;

NODE getNode(int value) {
    NODE new;
    new = (NODE)malloc(sizeof(struct Node));
    if (new == NULL) {
        printf("No Memory\n");
        return NULL;
    }
    new->value = value;
    new->next = NULL;
    return new;
}

NODE insert(NODE first, int item, int atFront) {
    NODE new = getNode(item), temp = first;
    if (first == NULL) return new;
    if (atFront) {
        new->next = first;
        return new;
    }
    else {
        while (temp->next != NULL) temp = temp->next;
        temp->next = new;
        return first;
    }
}

NODE insertAtPosition(NODE first, int item, int position) {
    NODE new = getNode(item);
    if (position < 1) {
        printf("Invalid position! Position should be 1 or greater.\n");
        return first;
    }

    if (position == 1) {
        new->next = first;
        return new;
    }

    NODE temp = first;
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;  
    }

    if (temp == NULL) {
        printf("Position exceeds the length of the list. Adding at the end.\n");
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    } else {
        new->next = temp->next;
        temp->next = new;
    }

    return first;
}

NODE delete(NODE first, int atFront) {
    NODE temp;
    if (first == NULL) {
        printf("Linked List is Empty : [UNDERFLOW!]\n");
        return NULL;
    }
    if (first->next == NULL) {
        free(first);
        return NULL;
    }
    if (atFront) {
        temp = first;
        first = first->next;
        free(temp);
        return first;
    }
    else {
        NODE prev = NULL;
        temp = first;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        if (prev != NULL) prev->next = NULL;
        else return NULL;
        return first;
        }
}

NODE deleteByValue(NODE first, int value) {
    if (first == NULL) {
        printf("Linked List is Empty : [UNDERFLOW!]\n");
        return NULL;
    }

    if (first->value == value) {
        NODE temp = first;
        first = first->next;
        free(temp);
        return first;
    }

    NODE temp = first, prev = NULL;

    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list. Nothing to delete.\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }

    return first;
}

int count(NODE first) {
    NODE temp = first;
    int count = 0;
    while (temp != NULL) {
        ++count;
        temp = temp->next;
    }
    return count;
}

void display(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    printf("The elements in the list are :\n");
    temp = first;
    while (temp != NULL) {
        printf("%d   ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int choice, item, atFront;

    while (1) {
        printf("\n-------------MENU-------------");
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("\n------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                printf("Insert at front or rear or any position? (1 for front, 0 for rear, 2 for any position): ");
                scanf("%d", &atFront);
                if (atFront == 0 || atFront == 1) first = insert(first, item, atFront);
                else {
                    int pos;
                    printf("\nEnter the position where you want to insert : ");
                    scanf("%d", &pos);
                    first = insertAtPosition(first, item, pos);
                }
                break;

            case 2:
                printf("Delete at front or rear or by value? (1 for front, 0 for rear, 2 for value): ");
                scanf("%d", &atFront);
                if (atFront == 0 || atFront == 1) first = delete(first, atFront);
                else {
                    int value;
                    printf("\nEnter the value to be deleted from Linked list: ");
                    scanf("%d", &value);
                    first = deleteByValue(first, value);
                }
                break;

            case 3:
                display(first);
                break;

            case 4:
                printf("Number of elements in the list: %d\n", count(first));
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice! Please enter a valid option.\n");
        }
    }

    return 0;
}