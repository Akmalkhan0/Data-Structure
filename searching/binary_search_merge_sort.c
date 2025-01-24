#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted halves
void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int i, j, k;
    int *l = (int *)malloc(sizeof(int) * n1);
    int *ir = (int *)malloc(sizeof(int) * n2);

    if (!l || !ir) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (i = 0; i < n1; i++) l[i] = a[p + i];
    for (j = 0; j < n2; j++) ir[j] = a[q + 1 + j];

    i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (l[i] <= ir[j]) {
            a[k++] = l[i++];
        } else {
            a[k++] = ir[j++];
        }
    }

    while (i < n1) a[k++] = l[i++];
    while (j < n2) a[k++] = ir[j++];

    free(l);
    free(ir);
}

// Recursive merge sort function
void m_s(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        m_s(a, p, q);
        m_s(a, q + 1, r);
        merge(a, p, q, r);
    }
}

// Function for binary search
int bin_search(int a[], int n, int item) {
    int l = 0, h = n - 1, m;
    while (l <= h) {
        m = (l + h) / 2;
        if (a[m] == item) return 1;
        else if (item < a[m]) h = m - 1;
        else l = m + 1;
    }
    return 0;
}

// Function to display the array
void arr_out(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    puts("");
}

// Function to input the array
void arr_in(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", &a[i]);
    }
    m_s(a, 0, n - 1);
    printf("\n------ After Sorting the Array ------\n");
    arr_out(a, n);
}

int main() {
    int *a, n, item, choice = 1;

    printf("Enter the Size of the Array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nInvalid array size. Exiting...\n");
        return 1;
    }

    a = (int *)malloc(sizeof(int) * n);
    if (!a) {
        printf("\nMemory allocation failed. Exiting...\n");
        return 1;
    }

    arr_in(a, n);

    while (choice == 1) {
        printf("\nEnter the Element to Search: ");
        scanf("%d", &item);

        if (bin_search(a, n, item)) {
            printf("\n\"The Entered Value %d is Found\"\n", item);
        } else {
            printf("\n\"The Entered Value %d is Not Found\"\n", item);
        }

        printf("\n----- Do You Want to Continue Searching? -----\n");
        printf("Enter '1' for YES or '0' for NO: ");
        if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 0)) {
            printf("\nInvalid input. Exiting search...\n");
            break;
        }
    }

    free(a);
    puts("\nProgram Exited Successfully.");
    return 0;
}
