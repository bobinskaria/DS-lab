#include <stdio.h>

#define SIZE 10

int A[SIZE], B[SIZE], C[SIZE];   // Global bit strings
int i, n, x;

// Read Set A
void readA() {
    for (i = 0; i < SIZE; i++)
        A[i] = 0;

    printf("Enter number of elements in Set A: ");
    scanf("%d", &n);

    printf("Enter elements of A (0 to 9): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 0 && x < SIZE) A[x] = 1;
    }
}

// Read Set B
void readB() {
    for (i = 0; i < SIZE; i++)
        B[i] = 0;

    printf("Enter number of elements in Set B: ");
    scanf("%d", &n);

    printf("Enter elements of B (0 to 9): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 0 && x < SIZE) B[x] = 1;
    }
}

// Display Set C
void displayC() {
    printf("{ ");
    for (i = 0; i < SIZE; i++)
        if (C[i] == 1)
            printf("%d ", i);
    printf("}\n");
}

// Union: C = A ∪ B
void Union() {
    for (i = 0; i < SIZE; i++)
        C[i] = A[i] | B[i];

    printf("A u B = ");
    displayC();
}

// Intersection: C = A ∩ B
void Intersection() {
    for (i = 0; i < SIZE; i++)
        C[i] = A[i] & B[i];

    printf("A n B = ");
    displayC();
}

// Difference: C = A – B
void Difference() {
    for (i = 0; i < SIZE; i++)
        if (A[i] == 1 && B[i] == 0)
            C[i] = 1;
        else
            C[i] = 0;

    printf("A - B = ");
    displayC();
}

int main() {
    int choice;

    while (1) {
        printf("\n--- SET OPERATIONS USING BIT STRING ---\n");
        printf("1. Enter Set A\n");
        printf("2. Enter Set B\n");
        printf("3. Union\n");
        printf("4. Intersection\n");
        printf("5. Difference\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: readA(); break;
            case 2: readB(); break;
            case 3: Union(); break;
            case 4: Intersection(); break;
            case 5: Difference(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
