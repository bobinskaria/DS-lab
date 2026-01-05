#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertBegin() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at End
void insertEnd() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Position
void insertPosition() {
    int value, pos;
    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    struct Node *newNode = createNode(value);

    if (pos == 1) {
        insertBegin();
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from Beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Deleted from beginning.\n");
}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        printf("Deleted from end.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    printf("Deleted from end.\n");
}

// Delete at Position
void deletePosition() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    if (pos == 1) {
        deleteBegin();
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Deleted from position.\n");
}

// Search
void search() {
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value found at position %d.\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value not found.\n");
}

// Display
void display() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBegin(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
