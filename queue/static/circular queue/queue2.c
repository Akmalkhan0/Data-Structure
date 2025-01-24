#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#define MAX 5
typedef int itype;
typedef struct{
    itype e[MAX];
    int front,rear,flag;
}queue;

void init(queue * qp){
    qp->front = 0,
    qp->rear = -1,
    qp->flag = 0;
}

int isempty(queue * qp){
    return qp->front == (qp->rear+1) % MAX && qp->flag == 0;
}

int isfull(queue * qp){
    return qp->front == (qp->rear+1) % MAX && qp->flag == 1;
}

void insert(queue * qp , itype item){

    if(isfull(qp)){
        puts("queue is full");
        return;
    }
    qp->flag = 1;
    qp->rear = (qp->rear +1) % MAX;
    qp->e[qp->rear] = item;
}

itype delete(queue * qp){
    itype temp;

    if(isempty(qp)){
        puts("queue is empty");
        return (itype) 0;
    }
    qp->flag = 0;
    temp = qp->e[qp->front];
    qp->front = (qp->front+1) % MAX;
    return temp;
}

itype peek(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return (itype) 0;
    }
    return qp->e[qp->front];
}

int size(queue * qp){
    if(qp->front<=qp->rear){
        return qp->rear - qp->front + 1;
    }
    else{
        return MAX - qp->front + qp->rear + 1;
    }
}

void display(queue * qp){
    int i,j;
    i = qp->front;
    
    if(isempty(qp)){
        printf("queue is underflow");
        return;
    }

    for(j = 0 ; j < size(qp); j++){
        printf("%d ",qp->e[i]);
        i = (i+1) % MAX;
    }
}