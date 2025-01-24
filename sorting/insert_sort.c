#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort
void insert_sort(int a[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Function to display array elements
void arr_out(int a[], int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to input array elements
void arr_in(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

int main() {
    int *a, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size. Exiting program.\n");
        return 1; // Indicate an error
    }

    a = (int *)malloc(sizeof(int) * n);
    if (!a) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    printf("\nEnter the elements of the array:\n");
    arr_in(a, n);

    insert_sort(a, n);

    printf("\n");
    arr_out(a, n);

    free(a); // Free allocated memory
    return 0; // Indicate successful execution
}
