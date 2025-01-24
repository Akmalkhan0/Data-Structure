// linear queue dequeue

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

typedef int itype;
typedef struct{
    itype e[MAX];
    int front,rear;
}queue;

void init(queue * qp);
int isfull(queue* qp);
int isempty(queue * qp);
void insfront(queue * qp , itype item);
void insrear(queue * qp,itype item);
itype dltfront(queue * qp);
itype dltrear(queue * qp);
itype peekfr(queue * qp);
itype peekrr(queue * qp);
int size(queue * qp) ;
void display(queue * qp);

void init(queue * qp){
    qp->front = 0;
    qp->rear = -1;
}

int isfull(queue* qp){
    return qp->front == (qp->rear+2)% MAX;
}

int isempty(queue * qp){
   return qp->front == (qp->rear+1) % MAX;
}

void insfront(queue * qp , itype item){
    if(isfull(qp)){
        puts("the front id full");
        return;
    }
    qp->front=(qp->front-1)%MAX;
    qp->e[qp->front] = item; 
}

void insrear(queue * qp,itype item){
    if(isfullfr(qp)){
        puts("the rear is full");
        return;
    }
    qp->rear = (qp->rear+1)%MAX;
    qp->e[qp->rear] = item;
}

itype dltfront(queue * qp){
    itype item;
    if(isempty(qp)){
        puts("queue is empty");
        return (itype) 0;
    }
    item = qp->e[qp->front];
    qp->front = (qp->front +1) % MAX;
    return item;
}

itype dltrear(queue * qp){
    itype item;
    if(isempty(qp)){
        puts("queue is empty");
        return(itype) 0;
    }
    item = qp->e[qp->rear];
    qp->rear = (qp->rear-1) % MAX;
    return item;
}

itype peekfr(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return(itype) 0;
    }
    return qp->e[qp->front];
}

itype peekrr(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return(itype) 0;
    }
    return qp->e[qp->rear];
}

int size(queue * qp){
    if(qp->front < qp->rear || isempty(qp)){
        return qp->rear - qp->front + 1;
    }
    else{
        return MAX - qp->front + qp->rear + 1;
    }
}

void display(queue * qp){
    int n = size(qp),i=qp->front,j;
    if(isempty(qp)){
        puts("the queue is empty");
        return;
    }

    for(j = 0; j < n ; j++){
        printf("%d ",qp->e[i]);
        i = (i+1) % MAX;
    }
}
