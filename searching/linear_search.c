#include <stdio.h>
#include <stdlib.h>

// Linear search function
int li_search(int a[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (a[i] == item)
            return i; // Return index
    }
    return -1; // Not found
}

// Function to input array elements
void arr_in(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", &a[i]);
    }
}

int main() {
    int *a, n, item, choice = 1;

    printf("Enter the Size of Array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size. Exiting program.\n");
        return 1;
    }

    a = (int *)malloc(sizeof(int) * n);
    if (!a) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    printf("\nEnter the Elements of the Array:\n");
    arr_in(a, n);

    while (choice == 1) {
        printf("\nEnter the Searching Element: ");
        scanf("%d", &item);

        int index = li_search(a, n, item);
        if (index != -1) {
            printf("\nThe Entered Value %d is Found at Index %d\n", item, index);
        } else {
            printf("\nThe Entered Value %d is Not Found\n", item);
        }

        printf("\nDo You Want to Continue Searching?\n");
        printf("Enter 1 for YES or 0 for NO: ");
        scanf("%d", &choice);
    }

    free(a); // Free allocated memory
    printf("\nProgram Terminated. Thank you!\n");
    return 0;
}
