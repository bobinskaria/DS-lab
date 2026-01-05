#include <stdio.h>

#define MAX 100    

int arr[MAX];
int n = 0;   

void insert() {
    if (n == MAX) {
        printf("Array is full! Cannot insert.\n");
        return;
    }

    int pos, value;
    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = value;
    n++;

    printf("Value inserted successfully.\n");
}

void delete() {
    if (n == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }

    int pos;
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Value deleted successfully.\n");
}

void search() {
    if (n == 0) {
        printf("Array is empty. Nothing to search.\n");
        return;
    }

    int value, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Value found at index %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Value not found.\n");
}

void traverse() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: search(); break;
        case 4: traverse(); break;
        case 5: return 0;
        default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
