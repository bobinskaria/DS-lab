#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void add() {
    int item;
    if ((rear + 1) % SIZE == front) {
        printf("Queue is FULL\n");
        return;
    }
    printf("Enter element to add: ");
    scanf("%d", &item);

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = item;
    printf("Inserted %d\n", item);
}

void delete() {
    if (front == -1) {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void search() {
    if (front == -1) {
        printf("Queue is EMPTY\n");
        return;
    }

    int item, i;
    printf("Enter element to search: ");
    scanf("%d", &item);

    i = front;
    while (1) {
        if (queue[i] == item) {
            printf("Element %d found in queue\n", item);
            return;
        }
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("Element NOT found\n");
}

void display() {
    if (front == -1) {
        printf("Queue is EMPTY\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: delete(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
