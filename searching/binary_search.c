#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int bin_search(int a[], int n, int item) {
    int l = 0, h = n - 1, m;
    while (l <= h) {
        m = (l + h) / 2;
        if (item == a[m]) {
            return 1;
        } else if (item < a[m]) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return 0;
}

// Function to input array elements
void arr_in(int a[], int n) {
    printf("\n--------- Enter the Elements in Sorted Order ----------\n\n");
    for (int i = 0; i < n; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Main program
int main() {
    int *a, n, item, choice = 1;

    printf("Enter the Size of the Array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nInvalid size. Exiting program.\n");
        return 1;
    }

    a = (int *)malloc(sizeof(int) * n);
    if (!a) {
        printf("\nMemory allocation failed. Exiting program.\n");
        return 1;
    }

    arr_in(a, n);

    while (choice == 1) {
        printf("\nEnter the Element to Search: ");
        scanf("%d", &item);

        if (bin_search(a, n, item)) {
            printf("\n\"The Entered Value %d is Found\"\n", item);
        } else {
            printf("\n\"!The Entered Value %d is Not Found\"\n", item);
        }

        printf("\n----- Do You Want to Continue Searching? -----\n");
        printf("Enter '1' for YES or '0' for NO: ");
        scanf("%d", &choice);

        // Validate input for choice
        while (choice != 1 && choice != 0) {
            printf("\nInvalid choice. Please enter '1' or '0': ");
            scanf("%d", &choice);
        }
    }

    free(a); // Free allocated memory
    printf("\nProgram Exited Successfully.\n");
    return 0;
}
