#include <stdio.h>
#include <stdlib.h>

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

int bin_search(int a[], int n, int item) {
    int l = 0, m, h = n - 1;
    while (l <= h) {
        m = (l + h) / 2;
        if (item == a[m]) {
            return m;  // Return the index of the found item
        } else if (item < a[m]) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;  // Return -1 if the item is not found
}

void arr_out(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    puts("");
}

void arr_in(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", &a[i]);
    }
    insert_sort(a, n);
    printf("\n------ After Applying Sorting To The Array ------\n\n");
    arr_out(a, n);
}

int main() {
    int *a, n, item, choice = 1;
    
    // Validate array size input
    printf("Enter the Size of the Array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size. Exiting...\n");
        return 1;
    }

    // Memory allocation and validation
    a = (int *)malloc(sizeof(int) * n);
    if (a == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    arr_in(a, n);

    // Perform search loop
    while (choice == 1) {
        printf("\nEnter the Searching Element: ");
        scanf("%d", &item);
        
        int result = bin_search(a, n, item);
        if (result != -1) {
            printf("\n\"The Entered Value %d is Found at Index %d\"\n", item, result);
        } else {
            printf("\n\"The Entered Value %d is Not Found\"\n", item);
        }

        printf("\n----- If You Want To Continue Search -----\n\n");
        printf("Enter '1' OR '0' (YES/NO): ");
        scanf("%d", &choice);
        
        // Handle invalid choice input
        if (choice != 1 && choice != 0) {
            printf("\n!Entered choice should be 1 or 0\n\n");
        }
    }

    // Free memory and exit
    free(a);
    puts("");
    return 0;
}
