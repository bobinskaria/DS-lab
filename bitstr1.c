#include <stdio.h>

#define MAX 20

int U[MAX], A[MAX], B[MAX], C[MAX];
int n;

int isInUniversal(int x) {
    for (int i = 0; i < n; i++) {
        if (U[i] == x) return i;
    }
    return -1;
}

void readSets() {
    int x, index, a_size, b_size;

    printf("Enter size of Universal Set: ");
    scanf("%d", &n);

    printf("Enter Universal Set elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &U[i]);

    for (int i = 0; i < n; i++) {
        A[i] = 0;
        B[i] = 0;
    }

    printf("Enter number of elements in Set A: ");
    scanf("%d", &a_size);
    printf("Enter elements of Set A (must be in Universal Set):\n");
    int countA = 0;
    while (countA < a_size) {
        scanf("%d", &x);
        index = isInUniversal(x);
        if (index == -1) {
            printf("Element not in Universal Set. Enter again: ");
            continue;
        }
        if (A[index] == 1) {
            printf("Element already in Set A, enter another: ");
            continue;
        }
        A[index] = 1;
        countA++;
    }

    printf("Enter number of elements in Set B: ");
    scanf("%d", &b_size);
    printf("Enter elements of Set B (must be in Universal Set):\n");
    int countB = 0;
    while (countB < b_size) {
        scanf("%d", &x);
        index = isInUniversal(x);
        if (index == -1) {
            printf("Element not in Universal Set. Enter again: ");
            continue;
        }
        if (B[index] == 1) {
            printf("Element already in Set B, enter another: ");
            continue;
        }
        B[index] = 1;
        countB++;
    }
}


void printBitString(int set[]) {
    for (int i = 0; i < n; i++)
        printf("%d ", set[i]);
    printf("\n");
}

// Print Universal Set, Set A, Set B
void printSets() {
    printf("\nUniversal Set: ");
    for (int i = 0; i < n; i++)
        printf("%d ", U[i]);
    printf("\nSet A:         ");
    printBitString(A);
    printf("Set B:         ");
    printBitString(B);
}

// Set operations
void setUnion() {
    for (int i = 0; i < n; i++)
        C[i] = A[i] | B[i];
    printf("       Union (A u B):");
    printBitString(C);
}

void setIntersection() {
    for (int i = 0; i < n; i++)
        C[i] = A[i] & B[i];
    printf("Intersection (A n B): ");
    printBitString(C);
}

void setDifference() {
    for (int i = 0; i < n; i++)
        C[i] = A[i] & (!B[i]);
    printf("Difference (A - B):  ");
    printBitString(C);
}

int main() {
    readSets();

    // Print sets
    printSets();

    // Perform operations
    setUnion();
    setIntersection();
    setDifference();

    return 0;
}
