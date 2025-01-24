#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int itype;
typedef struct node{
    itype info;
    struct node * next ;
}node;

typedef struct{
    node * front;
    node * rear;
}queue;

int size(queue * qp);
int isempty(queue * qp);

void init(queue * qp);
void insert(queue * qp,itype item);

itype delete(queue * qp);
itype peek(queue * qp);

void display(queue * qp);


int size(queue * qp){
    node * ptr = qp->front;
    int c = 0;
    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    } 
    return c;
}

int isempty(queue * qp){
    return qp->front == NULL;
}

void init(queue * qp){
    qp->front = NULL;
    qp->rear = NULL;
}


void insert(queue * qp,itype item){
    node * ptr = (node*) malloc(sizeof(node));
    if(ptr == NULL){
        puts("queue is full");
        return;
    }
    ptr->info = item;
    ptr->next = NULL;
    if(isempty(qp))
        qp->front = ptr;
    else
        qp->rear->next = ptr;
    qp->rear = ptr;
}

itype delete(queue * qp){
    node * ptr = qp->front;
    itype item;
    if(isempty(qp)){
        puts("queue is empty");
        return 0;
    }    
    item = qp->front->info;
    qp->front = ptr->next;
    if(qp->front == qp->rear)
        qp->rear = NULL;
    free(ptr);
    return item;
}

itype peek(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return 0;
    }    
    return qp->front->info;
}

void display(queue * qp){
    node * ptr = qp->front;
    printf("\n[");
    while(ptr != NULL){
        printf(" %d ",ptr->info);
        ptr = ptr->next;
    }
    printf("]\n\n");
}