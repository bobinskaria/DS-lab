#include <stdio.h>

// Bubble sort function
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[100], b[100], c[200];
    int n1, n2, i, j, k;

    // Read first array
    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements:\n", n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    // Read second array
    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements:\n", n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    // Sort both arrays
    sort(a, n1);
    sort(b, n2);

    printf("\nSorted First Array: ");
    for (i = 0; i < n1; i++)
        printf("%d ", a[i]);

    printf("\nSorted Second Array: ");
    for (i = 0; i < n2; i++)
        printf("%d ", b[i]);

    // Merge into third array
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // Copy remaining elements
    while (i < n1)
        c[k++] = a[i++];

    while (j < n2)
        c[k++] = b[j++];

    // Print merged array
    printf("\nMerged Sorted Array: ");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);

    return 0;
}
