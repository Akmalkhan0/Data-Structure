#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//structure declaration
typedef int itype;

typedef struct node{
     itype info;
     struct node * next;
}node;

typedef struct{
    node * top;
}stack;


// funtions diclarations

int size(stack * sp);
int isempty(stack * sp);

itype pop(stack * sp);
itype peek (stack * sp);

void init(stack * sp);
void push(stack * sp,itype item);
void display(stack * sp);

// funtions definations

void init(stack * sp){
   sp->top = NULL;
}

int isempty(stack * sp){
    return sp->top == NULL;
}

void push(stack * sp,itype item){
    node * ptr = (node *) malloc(sizeof(node));
    if(ptr == NULL){
        puts("stack is full");
        return;
    }
    ptr->info = item;
    ptr->next = NULL;
    if(!(isempty(sp)))
        ptr->next = sp->top;
    sp->top = ptr;
}

itype pop(stack * sp){
    node * ptr = sp->top;
    itype item;
    
    if(ptr == NULL){
        puts("Stack is Unnderflow");
        return 0;
    }
    
    item = ptr->info;
    sp->top = sp->top->next;
    free(ptr);
    return item;
}


itype peek(stack * sp){
    
    if(isempty(sp)){
        puts("Stack is Unnderflow");
        return 0;
    }
    return sp->top->info;
}

int size(stack * sp){
    node * ptr = sp->top;
    int c = 0;
    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    }
    return c;
}

void display(stack * sp){
    node * ptr = sp->top;
    if(ptr == NULL){
        puts("stack is underflow");
        return;
    }
    puts("");    
    while(ptr != NULL){
        printf("|%8d |\n",ptr->info);
        ptr = ptr->next;
    }
    printf("----------");
}