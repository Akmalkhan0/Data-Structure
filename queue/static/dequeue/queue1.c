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

void init(queue * qp){
    qp->front = 0;
    qp->rear = -1;
}

int isrearfull(queue * qp){
    return qp->rear == MAX-1;
}

int isfrontfull(queue * qp){
    return qp->front == 0;
}

int isempty(queue * qp){
    return qp->front == qp->rear+1;
}

void insfront(queue * qp , itype item){
    if(isfrontfull(qp)){
        puts("the front id full");
        return;
    }
    qp->e[--qp->front] = item; 
}

void insrear(queue * qp,itype item){
    if(isrearfull(qp)){
        puts("the rear is full");
        return;
    }
    qp->e[++qp->rear] = item;
}

itype dltfront(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return (itype) 0;
    }
    return qp->e[qp->front++];
}

itype dltrear(queue * qp){
    if(isempty(qp)){
        puts("queue is empty");
        return(itype) 0;
    }
    return qp->e[qp->rear--];
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
    return qp->rear - qp->front + 1;
}

void display(queue * qp){
    if(isempty(qp)){
        puts("the queue is empty");
        return;
    }

    for(int i=qp->front ; i <= qp->rear ; i++){
        printf("%d ",qp->e[i]);
    }
}
