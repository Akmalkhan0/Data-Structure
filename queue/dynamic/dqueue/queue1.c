#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
typedef int itype;
typedef struct node{
  itype info;
   struct node * next,* pre;
}node;
typedef struct{
   node * front;
   node * rear;
}queue;


int size (queue * qp);
int isempty(queue * qp);

void init(queue * qp);
void display(queue * qp);
void insertf(queue * qp,itype item);
void insertl(queue * qp,itype item);

itype peekl(queue * qp);
itype peekf(queue * qp);

itype deletef(queue * qp);
itype deletel(queue * qp);


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

void display(queue * qp){
    node * ptr = qp->front;
    printf("\n[");
    while(ptr != NULL){
        printf(" %d ",ptr->info);
        ptr = ptr->next;
    }
    printf("]\n\n");
}

void insertf(queue * qp , itype item){
    node * ptr = (node *) malloc(sizeof(node));
    if(ptr == NULL){
        puts("queue is full");
        return;
    }
    ptr->info = item;
    ptr->next = NULL;
    ptr->pre = NULL;
    if(isempty(qp))
        qp->rear = ptr;
    else
    {
        qp->front->pre = ptr;
        ptr->next = qp->front;
    }
    qp->front = ptr;
}

void insertl(queue * qp , itype item){
    node * ptr = (node *) malloc(sizeof(node));
    if(ptr == NULL){
        puts("queue is full");
        return;
    }
    ptr->info = item;
    ptr->next = NULL;
    ptr->pre = NULL;
    if(isempty(qp))
        qp->front = ptr;
    else
    {
        qp->rear->next = ptr;
        ptr->pre = qp->rear;
    }
    qp->rear = ptr;
}

itype peekl(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return 0;
    }
    return qp->rear->info;
}

itype peekf(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return 0;
    }
    return qp->front->info;
}

itype deletef(queue * qp){
    node * ptr = qp->front;
    itype item;
    if(isempty(qp)){
        puts("queue is empty");
        return 0;
    }
    item = ptr->info;
    if(qp->front == qp->rear)
        qp->rear = NULL;
    else
        ptr->next->pre = NULL;    
    qp->front = ptr->next;
    free(ptr);
    return item;
}

itype deletel(queue * qp){
    node * ptr = qp->rear;
    itype item;
    if(isempty(qp)){
        puts("queue is empty");
        return 0;
    }
    item = ptr->info;
    if(qp->front == qp->rear)
        qp->front = NULL;
    else
        ptr->pre->next = NULL;    
    qp->rear = ptr->pre;
    free(ptr);
    return item;
}
