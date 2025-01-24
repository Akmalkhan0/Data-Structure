#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5

typedef int itype;
typedef struct { itype e[MAX];  int front,rear; }queue;

void inti(queue * qp);
void insert(queue * qp,itype item);
itype delete(queue * qp);
itype peek(queue * qp);
int size(queue * qp);
int isfull(queue * qp);
int isempty(queue * qp);
void display(queue * qp);

void inti(queue * qp){
    qp->front = 0;
    qp->rear = -1;
}

void insert(queue * qp,itype item){
    if(isfull(qp)){
        puts("The queue is full");
        return;
    }
    qp->e[++qp->rear] = item;
}

itype delete(queue * qp){
    itype temp;
    int n = size(qp);
    if(isempty(qp)){
        puts("The queue is empty");
        return (itype) 0;
    }
    temp = qp->e[qp->front];
    for(int i=qp->front ;i<=qp->rear;i++){
        qp->e[i] = qp->e[i+1];
    }
    qp->rear--;
    return temp;
}

itype peek(queue * qp){
    if(isempty(qp)){
        puts("The queue is empty");
        return (itype) 0;
    }
    return qp->e[qp->front];
}

int size(queue * qp){
    return qp->rear - qp->front + 1;
}

int isempty(queue * qp){
    return qp->front == qp-> rear + 1;
}

int isfull(queue * qp){
    return qp->rear == MAX - 1;
}

void display(queue * qp){
    for(int i = qp->front ; i <= qp->rear ; i++)
        printf("%d ",qp->e[i]);
    puts("");
}