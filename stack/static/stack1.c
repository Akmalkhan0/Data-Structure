#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 5
 
typedef int itype;
typedef struct
{
 itype e[MAX];
 int top;
}stack;

void inti(stack * sp);
void push(stack * sp,itype item);
itype pop(stack * sp);
itype peek(stack * sp);
int size(stack * sp);
int isfull(stack * sp);
int isempty(stack * sp);

void init(stack * sp){
    sp->top = -1;
}

void push(stack * sp,itype item){
    if(isfull(sp)){
        puts("stack is overflow");
        return;
    }
    sp->e[++sp->top] = item;
}

itype pop(stack * sp){
    if(isempty(sp)){
        puts("stack is underflow");
        return (itype) 0;
    }
    return sp->e[sp->top--];
}

itype peek(stack * sp){
    if(isempty(sp)){
        puts("stack is underflow");
        return (itype) 0;
    }
    return sp->e[sp->top];
}

int size(stack * sp){
    return sp->top+1;
}

int isfull(stack * sp){
    return sp->top == MAX-1;
}

int isempty(stack * sp){
    return sp->top == -1;
}
