#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// all structure declaration
typedef int itype;
typedef struct node{
    itype info;
    struct node *next,*pre;
}node;
typedef struct{
    node * start,*end;
}list;


// all funtion decaration

void init(list * lp);
void insertf(list * lp,itype item);
void insertl(list * lp, itype item);
void insertafg(list * lp,itype item,itype gitem);
void insertbfg(list * lp , itype item, itype gitem);
void insertatp(list * lp, itype item,int p);
void insertsort(list * lp,itype item);
void display(list * lp);
void revdisplay(list * lp);
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

// void swap(node ** pre,node ** next);

// all funtion defination

void init(list * lp){
    lp->start = NULL;
    lp->end = NULL;
}

void insertf(list * lp,itype item){
    node * ptr = create(item);
    if(ptr == NULL)
        return;
    else if(isempty(lp))
        lp->end = ptr;
    else{
        ptr->next = lp->start;
        lp->start->pre = ptr;
    }
    lp->start = ptr;
}

void insertl(list * lp,itype item){
    node * ptr = create(item);
    if(ptr == NULL)
        return;
    else if(isempty(lp))
        lp->start = ptr;
    else{
        ptr->pre = lp->end;
        lp->end->next = ptr;
    }
    lp->end = ptr;
}

void insertafg(list * lp,itype item,itype gitem){
    node * gptr = search(lp,gitem),* ptr;
    if(gptr == NULL){
        puts("given item is not found");
        return;
    }
    ptr = create(item);
    if(ptr == NULL)
        return;
    ptr->pre = gptr;
    if(gptr == lp->end){
        lp->end = ptr;
    }else{
        ptr->next = gptr->next;
        gptr->next->pre = ptr;
    }
    gptr->next = ptr;
}

void insertbfg(list * lp,itype item,itype gitem){
    node * gptr = search(lp,gitem),* ptr;
    if(gptr == NULL){
        puts("given item is not found");
        return;
    }
    ptr = create(item);
    if(ptr == NULL) return;
    ptr->next = gptr;
    ptr->pre = gptr->pre;
    if(lp->start == gptr)
        lp->start = ptr;
    else
        gptr->pre->next = ptr;
    gptr->pre = ptr;
}

void insertatp(list * lp,itype item,int p){
    node * gptr = lp->start,* ptr;
    int n = size(lp),i = 0;
    if(!(p>=1 && p<=n+1)){
        puts("given position is invalid");
        return;
    }
    for(i = 1; i <= n+1 && i != p ; i++  ){
        gptr = gptr->next;
    }
    ptr = create(item);

    if(gptr == NULL){
        ptr->pre = lp->end;
        lp->end->next = ptr;
        lp->end = ptr;
    }else if(!(lp->start == gptr)){
        ptr->pre = gptr->pre;
        ptr->next = gptr;
        gptr->pre->next = ptr;
        gptr->pre = ptr;
    }else{
        ptr->next = lp->start;
        gptr->pre = ptr;
        lp->start = ptr;
    }
}

void insertsortd(list * lp ,itype item){
    node * gptr = lp->start,* ptr = create(item);
    if(ptr == NULL) return;
    if(gptr == NULL){
        lp->start = lp->end = ptr;
        return;
    }
    while(gptr != NULL){
        if(gptr->info < item)
            gptr = gptr->next;
        else
            break;
    }
    if(gptr == NULL){
        lp->end->next = ptr;
        ptr->pre = lp->end;
        lp->end = ptr;
    }else if(gptr == lp->start){
        ptr->next = lp->start;
        lp->start->pre = ptr;
        lp->start = ptr;
    }else{
        ptr->next = gptr;
        ptr->pre = gptr->pre;
        gptr->pre->next = ptr;
        gptr->pre = ptr;
    }

}

void display(list * lp){
    node * ptr = lp->start;
    while(ptr != NULL){
        printf("%d ",ptr->info);
        ptr = ptr->next;
    }
}

void revdisplay(list * lp){
    node * ptr = lp->end;
    while(ptr != NULL){
        printf("%d ",ptr->info);
        ptr = ptr->pre;
    }
}

void reverse(list * lp){
    node * ptr = lp->start,*temp;
    if(lp->start == lp->end)
        return;
    while(ptr != NULL){
        temp = ptr->next;
        ptr->next = ptr->pre;
        ptr->pre = temp;
        
        ptr = ptr->pre;
    }
    temp = lp->start;
    lp->start = lp->end;
    lp->end = temp;
    
}


node * create(itype item){
    node * ptr = (node *) malloc(sizeof(node));
    if( ptr == NULL){
        puts("list is full");
        return NULL;
    }
    ptr->info = item;
    ptr->next = NULL;
    ptr->pre = NULL;
    return ptr;
}

node * search(list * lp,itype item){
    node * ptr = lp->start;
    while(ptr != NULL){
        if(ptr->info == item)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

int isempty(list * lp){
    return lp->start == NULL;
}

int size(list * lp){
    node * ptr = lp->start;
    int c = 0;
    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    }
    return c;
}

int min(list * lp){
    node * p,*q;
    if(isempty(lp)){
        puts("the list is empty");
        return __INT_MAX__;
    }  
    p = lp->start, q = lp->start->next;
    while(q != NULL){
        if(p->info > q->info)
            p = q;
        q = q->next;
    }
    return p->info;
}

int max(list * lp){
    node * p,*q;
    if(isempty(lp)){
        puts("the list is empty");
        return __INT_MAX__;
    }  
    p = lp->start, q = lp->start->next;
    while(q != NULL){
        if(p->info < q->info)
            p = q;
        q = q->next;
    }
    return p->info;
}

int sum(list * lp){
    node * ptr;
    int r = 0;
    if(isempty(lp)){
        puts("The list is empty");
        return 0;
    }
    ptr = lp->start;
    while(ptr != NULL){
        r += ptr->info;
        ptr = ptr->next;
    }
    return r;
}


itype findmid(list * lp){
    node * ptr = lp->start;
    int n = size(lp),i;
    if(isempty(lp)) return 0;
    n=n/2;
    for(i = 0 ; i < n ; i++)
        ptr = ptr->next;
    return ptr->info;
}

itype deletef(list * lp){
    node * ptr = lp->start;
    itype item;
    if(ptr == NULL){
        puts("list is empty");
        return 0;
    }
    item = ptr->info;
    ptr->next->pre = NULL; 
    lp->start = lp->start->next;
    free(ptr);
    return item;
}

itype deletel(list * lp){
    node * ptr = lp->end;
    itype item;
    if(ptr == NULL){
        puts("list is empty");
        return 0;
    }
    item = ptr->info;
    ptr->pre->next = NULL;
    lp->end = lp->end->pre;
    free(ptr);
    return item;
}

itype deleteg(list * lp,itype item){
    node * ptr = search(lp,item);
    itype temp;
    if(ptr == NULL){
        puts("item is not found");
        return 0;
    }
    item = ptr->info;
    if(lp->start == lp->end){
        lp->start = lp->end = NULL;
    }
    else if(ptr ==  lp->start){
        lp->start = lp->start->next;
        lp->start->pre = NULL;
    }
    else if(ptr == lp->end){
        lp->end = lp->end->pre;
        lp->end->next = NULL;
    }
    else{
        ptr->next->pre = ptr->pre;
        ptr->pre->next = ptr->next;
    }
    free(ptr);
    return temp;
}

itype deleteafg(list * lp,itype item){
    node * ptr = search(lp,item);
    itype temp;
    if(ptr == NULL){
        puts("the item is not found");
        return 0;
    }
    ptr = ptr->next;
    if(ptr == NULL){
        puts("item not have any after element");
        return 0;
    }
    temp = ptr->info;
    if(ptr == lp->end){
        lp->end = lp->end->pre;
        lp->end->next = NULL;
    }else{
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
    }
    free(ptr);
    return temp;
}

itype deletebfg(list * lp,itype item){
    node * ptr = search(lp,item);
    itype temp;
    if(ptr == NULL){
        puts("the item is not found");
        return 0;
    }
    ptr = ptr->pre;
    if(ptr == NULL){
        puts("item not have any before element");
        return 0;
    }
    temp = ptr->info;
    if(ptr == lp->start){
        lp->start = lp->start->next;
        lp->start->pre = NULL;
    }else{
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
    }
    free(ptr);
    return temp;
}

itype deleteatp(list * lp,int p){
    node * ptr = lp->start;
    itype temp;
    int n = size(lp),i;
    if(ptr == NULL){
        puts("list is empty");
        return 0;
    }
    else if(!(p>=1 && p<=n)){
        puts("position is invalid");
        return 0;
    }
    for(i = 1 ; i < p; i++)
        ptr = ptr->next;
    temp = ptr->info;
    if(ptr == lp->end){
        lp->end = lp->end->pre;
        lp->end->next = NULL;
    }
    else if(ptr == lp->start){
        lp->start = lp->start->next;
        lp->start->pre = NULL;
    }
    else{
        ptr->next->pre = ptr->pre;
        ptr->pre->next = ptr->next;
    }
    free(ptr);
    return temp;
}



/* void reverse(list * lp){
    node * ptr = lp->start;
    if(lp->start == lp->end)
        return;
    while(ptr != NULL){
        swap(&ptr->next,&ptr->pre);
        ptr = ptr->pre;
    }
    swap(&lp->start,&lp->end);   
}

void swap(node ** pre,node ** next){
    node * temp = *pre;
    *pre = *next;
    *next = temp;
}
*/


list * mergelist(list * lp,list * lp2){
    list merge;
    init(&merge);
    node * ptr1 = lp->start,* ptr2 = lp2->start;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->info <= ptr2->info){
            if(merge.start == NULL){
                ptr2->pre = NULL;
                merge.end = ptr2;
                merge.start = ptr2;
                ptr2 = ptr2->next;
            }
            else{
                merge.end->next = ptr2;
                ptr2->pre = merge.end;
                merge.end = ptr2;
                ptr2 = ptr2->next;
            }
        }else{
            if(merge.start == NULL){
                ptr1->pre = NULL;
                merge.end = ptr1;
                merge.start = ptr1;
                ptr1 = ptr1->next;
            }else{
                merge.end->next = ptr1;
                ptr1->pre = merge.end;
                merge.end = ptr1;
                ptr1 = ptr1->next;
            }
        }
    }
    
    while(ptr1 != NULL){
        merge.end->next = ptr1;
        ptr1->pre = merge.end;
        merge.end = ptr1;
        ptr1 = ptr1->next;
    }

    while(ptr2 != NULL){
        merge.end->next = ptr2;
        ptr2->pre = merge.end;
        merge.end = ptr2;
        ptr2 = ptr2->next;
    }
    free(ptr2);
    lp->start = merge.start;
    lp->end = merge.end;
    return lp;
}