#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int itype;
typedef struct node{
    itype info;
    struct node * next;
}node;
typedef struct{
    node * start;
    node * end;
}list;


void init(list * lp);
void insertf(list * lp,itype item);
void insertl(list * lp, itype item);
void insertafg(list * lp,itype item,itype gitem);
void insertbfg(list * lp , itype item, itype gitem);
void insertatp(list * lp, itype item,int p);
void insertsort(list * lp,itype item);
void display(list * lp);
void revdisplay(node * ptr,list * lp);
void reverse(list * lp);

node * search(list * lp,itype item);
node * create(itype item);

int isempty(list * lp);
int size(list * lp);
int min(list * lp);
int max(list * lp);
int sum(list * lp);

itype findmid(list * lp);
itype deletef(list * lp);
itype deletel(list * lp);
itype deleteg(list * lp , itype item);
itype deleteafg(list * lp,itype item);
itype deletebfg(list * lp,itype item);
itype deleteatp(list * lp,int p);



void init(list * lp){
    lp->start = NULL;
    lp->end = NULL;
}

void insertf(list * lp,itype item){
    node * ptr = create(item);
    if(ptr == NULL) return;
    if(isempty(lp)){
        lp->end = ptr;
        ptr->next = ptr;
    }
    else{
        ptr->next = lp->start;
        lp->end->next = ptr;
    }
    lp->start = ptr;

}

void insertl(list * lp, itype item){
    node * ptr = create(item);
    if(ptr == NULL) return;
    if(isempty(lp)){
        lp->start = ptr;
        ptr->next = ptr;
    }else{
        lp->end->next = ptr;
        ptr->next = lp->start;
    }
    lp->end = ptr;

}
void insertafg(list * lp,itype item,itype gitem);
void insertbfg(list * lp , itype item, itype gitem);
void insertatp(list * lp, itype item,int p);
void insertsort(list * lp,itype item);


void display(list * lp){
    node * ptr = lp->start;
    puts("");
    while(ptr->next != lp->start){
        printf("[%d][%u] -> ",ptr->info,ptr->next);
        ptr = ptr->next;
    }
    printf("[%d][%u]->(head)\n",ptr->info,ptr->next);
    puts("");
}

void revdisplay(node *ptr, list *lp) {
    if (lp->start == NULL){ 
        printf("List is empty.\n");
        return;
    }

    if (ptr->next != lp->start) { 
        revdisplay(ptr->next, lp);
    }
    else{
        puts("");
    }
    printf(" <- [%u][%d]", ptr->next,ptr->info); 
   
}
void reverse(list * lp);


node * create(itype item){
    node * ptr = (node *) malloc(sizeof(node));
    if(ptr == NULL){
        puts("the list is full");
        return NULL;
    }
    ptr->info = item;
    ptr->next = NULL;
    return ptr;
}


int isempty(list * lp){
    return lp->start == NULL;
}