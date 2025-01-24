#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

// Define a generic stack using void* for handling any data type
typedef void* stack_element;

typedef struct {
    stack_element e[MAX];
    int top;
} stack;

// Function declarations
void init(stack* sp);
void push(stack* sp, stack_element item);
stack_element pop(stack* sp);
stack_element peek(stack* sp);
int size(stack* sp);
int isfull(stack* sp);
int isempty(stack* sp);

// Initialize the stack
void init(stack* sp) {
    sp->top = -1;
}

// Push an element onto the stack
void push(stack* sp, stack_element item) {
    if (isfull(sp)) {
        puts("Stack is full!");
        return;
    }
    sp->e[++sp->top] = item;
}

// Pop an element from the stack
stack_element pop(stack* sp) {
    if (isempty(sp)) {
        puts("Stack is empty!");
        return NULL;
    }
    return sp->e[sp->top--];
}

// Peek the top element of the stack
stack_element peek(stack* sp) {
    if (isempty(sp)) {
        puts("Stack is empty!");
        return NULL;
    }
    return sp->e[sp->top];
}

// Return the size of the stack
int size(stack* sp) {
    return sp->top + 1;
}

// Check if the stack is full
int isfull(stack* sp) {
    return sp->top == MAX - 1;
}

// Check if the stack is empty
int isempty(stack* sp) {
    return sp->top == -1;
}

// Print the stack (Generic)
void print_stack(stack* sp, char type) {
    printf("Stack contents: ");
    for (int i = 0; i <= sp->top; i++) {
        if (type == 'i') {
            printf("%d ", *((int*)sp->e[i]));  // Cast and print as integer
        } else if (type == 'c') {
            printf("%c ", *((char*)sp->e[i]));  // Cast and print as character
        }
    }
    printf("\n");
}

