#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int itype;
typedef struct {
 itype * e;
 int f,r,n;
}queue;


int size(queue * qp);
int isempty(queue * qp);
int isfull(queue * qp);
int capacity(queue * qp);

void init(queue * qp,int n);
void display(queue * qp);
void insert(queue * qp,itype item);

itype delete(queue * qp);
itype peek(queue * qp);


int capacity(queue * qp){
    return qp->n;
}

int size(queue * qp){
    return qp->r - qp->f + 1;
}

int isfull(queue * qp){
    return qp->r+1 == qp->n;
}

int isempty(queue * qp){
    return qp->r == -1;
}

void init(queue * qp,int n){
    qp->f = 0;
    qp->r = -1;
    qp->n = n;
    qp->e = (itype *) malloc(n*sizeof(itype));
    if(qp->e == NULL){
        puts("queue is full");
        return;
    }
}

void display(queue * qp){
    if(isempty(qp))
    {
        puts("queue is empty");
        return;
    }
    printf("\n[");
    for(int i = 0;i <= qp->r ; i++){
        printf(" %d ",qp->e[i]);
    }
    printf("]\n\n");
}

void insert(queue * qp, itype item ){
    if(isfull(qp)){
        itype * a = (itype *) malloc(qp->n*2*sizeof(itype));
        if(a == NULL){
            puts("queue is full");
            return;
        }
        for(int i = 0;i < qp->n ; i++)
            a[i] = qp->e[i];
        free(qp->e);
        qp->e = a;
        qp->n = qp->n*2;
    }
    qp->e[++qp->r] = item;
}

itype delete(queue * qp){
    itype item;
    if(isempty(qp)){
        puts("queue is empty");
        return -1;
    }
    item = qp->e[qp->f];
    for(int i = 0;i < qp->r+1 && !(isempty(qp)) ; i++)
        qp->e[i] = qp->e[i+1];    
    qp->r--;
    return item;
}

itype peek(queue * qp){
     if(isempty(qp)){
        puts("queue is empty");
        return -1;
    }
    return qp->e[qp->f];
}
