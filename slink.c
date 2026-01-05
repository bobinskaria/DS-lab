#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// ---------------- INSERT AT BEGINNING ----------------
void insert_begin() {
    int value;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    printf("Node inserted at beginning.\n");
}

// ---------------- INSERT AT END ----------------
void insert_end() {
    int value;
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Node inserted at end.\n");
}

// ---------------- INSERT AT POSITION ----------------
void insert_pos() {
    int value, pos, i;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted at position %d.\n", pos);
    }
}

// ---------------- DELETE AT BEGINNING ----------------
void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted node = %d\n", temp->data);
    free(temp);
}

// ---------------- DELETE AT END ----------------
void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    if (head->next == NULL) {
        printf("Deleted node = %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted node = %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// ---------------- DELETE AT POSITION ----------------
void delete_pos() {
    int pos, i;
    struct node *temp, *prev;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        temp = head;
        head = head->next;
        printf("Deleted node = %d\n", temp->data);
        free(temp);
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        prev->next = temp->next;
        printf("Deleted node = %d\n", temp->data);
        free(temp);
    }
}


void search() {
    int key, pos = 1, found = 0;
    struct node *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Element %d not found in the list.\n", key);
}



void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
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

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: display(); break;
            case 8: search();break;
            case 9: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
