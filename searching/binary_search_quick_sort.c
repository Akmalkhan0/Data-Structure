#include <stdio.h>
#include <stdlib.h>

// Function to swap to items
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Funtion To Partition a array
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

//Funstion To quick Sort
void q_sort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        q_sort(a, p, q - 1);
        q_sort(a, q + 1, r);
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
    q_sort(a, 0, n - 1);
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
