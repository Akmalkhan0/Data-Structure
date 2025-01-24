#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int p, int r) {
    int pivot = a[r];
    int i = p - 1;
    
    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    
    swap(&a[i + 1], &a[r]);
    return i + 1;
}

void q_sort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        q_sort(a, p, q - 1);
        q_sort(a, q + 1, r);
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}

void input_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

int main() {
    int *a, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;  // Exit if invalid size
    }

    a = (int *)malloc(sizeof(int) * n);
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation fails
    }

    printf("Enter the items of the array:\n");
    input_array(a, n);

    printf("Before sorting: ");
    print_array(a, n);

    q_sort(a, 0, n - 1);

    printf("After sorting: ");
    print_array(a, n);

    free(a);  // Free the allocated memory
    return 0;
}
