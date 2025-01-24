#include"stack.c"

int main() {
    stack s1;
    int choice, int_item;
    char char_item;
    char type;  // 'i' for integer, 'c' for character
    init(&s1);

    printf("Enter type of stack: 'i' for integer, 'c' for character: ");
    scanf(" %c", &type);

    while (1) {
        system("cls");  // Use system("clear") for Linux or MacOS

        printf("-------Menu------\n");
        printf("  1 For push\n");
        printf("  2 For pop\n");
        printf("  3 For peek\n");
        printf("  4 For size\n");
        printf("  5 For check empty\n");
        printf("  6 For check full\n");
        printf("  7 For Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (type == 'i') {
                    printf("Enter item for push (integer): ");
                    scanf("%d", &int_item);
                    int* item = (int*)malloc(sizeof(int));
                    *item = int_item;
                    push(&s1, item);
                } else if (type == 'c') {
                    printf("Enter item for push (character): ");
                    scanf(" %c", &char_item);
                    char* item = (char*)malloc(sizeof(char));
                    *item = char_item;
                    push(&s1, item);
                }
                break;

            case 2:
                if (type == 'i') {
                    int* popped_item = (int*)pop(&s1);
                    if (popped_item != NULL) {
                        printf("Popped item: %d\n", *popped_item);
                        free(popped_item);
                    }
                } else if (type == 'c') {
                    char* popped_item = (char*)pop(&s1);
                    if (popped_item != NULL) {
                        printf("Popped item: %c\n", *popped_item);
                        free(popped_item);
                    }
                }
                break;

            case 3:
                if (type == 'i') {
                    int* peeked_item = (int*)peek(&s1);
                    if (peeked_item != NULL) {
                        printf("Peeked item: %d\n", *peeked_item);
                    }
                } else if (type == 'c') {
                    char* peeked_item = (char*)peek(&s1);
                    if (peeked_item != NULL) {
                        printf("Peeked item: %c\n", *peeked_item);
                    }
                }
                break;

            case 4:
                printf("Stack size: %d\n", size(&s1));
                break;

            case 5:
                printf(isempty(&s1) ? "Stack is empty\n" : "Stack is not empty\n");
                break;

            case 6:
                printf(isfull(&s1) ? "Stack is full\n" : "Stack is not full\n");
                break;

            case 7:
                exit(0);

            default:
                puts("Invalid choice! Please enter a valid option.");
                break;
        }

        // Print the stack contents
        print_stack(&s1, type);

        getchar();  // To capture the extra newline character
        printf("\nPress any key to continue...");
        getchar();  // Wait for user input
    }

    return 0;
}
