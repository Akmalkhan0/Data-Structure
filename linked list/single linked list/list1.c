#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int itype;
typedef struct node{
    itype info;
    struct node * next;
}node;
typedef struct{
    node * start,* end;
}list;


// ALL FUBTIONS DECLARATION


void inti(list* lp);
void inslast(list * lp,itype item);
void insfirst(list * lp , itype item);
void insaftergiven(list * lp, itype givenitem, itype item);
void insbeforegiven(list * lp, itype givenitem, itype item);
void insertatp(list * lp, itype item,int p);
void insertsort(list * lp,itype item);

node * search(list * lp,itype item);
node * create(itype item);
node * previous(list * lp,itype gitem);

int size(list * lp);
int isempty(list *lp);
int min(list * lp);
int max(list * lp);

itype deletefir(list * lp);
itype deletelas(list * lp);
itype deletegivenitem(list * lp,itype gitem);
itype deleteaftergiven(list * lp,itype gitem);
itype deletebeforegiven(list * lp,itype gitem);
itype deleteatposition(list * lp,itype item , int p);

// ALL OTHER FUNCTIONS

void init(list * lp){
    lp->start = NULL;
    lp->end = NULL;
}

void display(list * lp){
    node * ptr;
    
    for(ptr = lp->start ; ptr->next ; ptr = ptr->next )
        printf("[%d][%u] -> ",ptr->info,ptr->next);
    printf("[%d][NULL] ",ptr->info);
    puts("");
}

node * create(itype item){
    node * ptr;
    ptr = (node *) malloc(sizeof(node));
    if(ptr==NULL){
        puts("list is full");
        return NULL;
    }
    ptr->info = item;
    ptr->next = NULL;
    return ptr;
}

node * search(list * lp,itype item){
    node * ptr;
    for(ptr = lp->start ; ptr ; ptr = ptr->next){
        if(ptr->info == item)
        return ptr;
    }
    return NULL;
}

node * previous(list * lp,itype gitem){
      node *ptr,*pre=NULL;
      if(lp->start == lp->end){
        return NULL;
      }
      for(ptr = lp->start ; ptr != NULL ; pre = ptr,ptr = ptr->next){
        if(ptr->info == gitem)
            return pre;
      }
      return NULL;
}

// ALL INSERT FUNCTIONS

void insfirst(list * lp,itype item){
    node * ptr = create(item);
    if(ptr==NULL) return;

    if(isempty(lp))
        lp->end = ptr;
    else
        ptr->next = lp->start;
    lp->start = ptr;
}

void inslast(list * lp,itype item){
    node * ptr = create(item);
    if(ptr==NULL) return;

    if(isempty(lp))
        lp->start = ptr;
    else
        lp->end->next = ptr;
    
    lp->end = ptr;
}

void insaftergiven(list * lp, itype givenitem, itype item){
    node * gptr = search(lp,givenitem),*ptr;  
    if(ptr == NULL) return;
    if(gptr == NULL) {
        puts("the given item is not found");
        return;
    }
    if(lp->end == gptr)
        inslast(lp,item);
    else{ 
    ptr = create(item);
    ptr->next = gptr->next;
    gptr->next = ptr; 
    } 
}

void insbeforegiven(list * lp, itype givenitem, itype item){
    node * gptr = search(lp,givenitem),*ptr;  
    if(gptr == NULL) {
        puts("the given item is not found");
        return;
    }
    if(lp->start == gptr)
        insfirst(lp,item);
    else{ 
    ptr = create(item);
    if(ptr == NULL) return;
    gptr = previous(lp,givenitem);
    ptr->next = gptr->next;
    gptr->next = ptr; 
    } 
}

void insertatp(list * lp,itype item,int p){
    node * ptr,*gptr,*pre;
    int n = size(lp),i; 
    if(!(p>= 1 && p <= n+1)){
        puts("Entered position is invalid");
        return;
    }
    ptr = create(item);
    if(ptr == NULL) return;
    else if(isempty(lp) && p == 1){
        lp->start = ptr;
        lp->end = ptr;        
        return;
    }
    for(gptr = lp->start,i = 1,pre = NULL ; i < p  ; pre = gptr,gptr = gptr->next,i++);
    if(gptr == NULL){
        lp->end->next = ptr;
        lp->end = ptr;
    }else if(gptr == lp->start){
        ptr->next = lp->start;
        lp->start = ptr;
    }else{
        ptr->next = pre->next;
        pre->next = ptr;
    }
}   

void insertsort(list * lp, itype item){
    node * ptr = create(item),*gptr = lp->start,*pre = NULL;
    if(ptr == NULL) return;
    else if(isempty(lp)){
        lp->start = ptr;
        lp->end = ptr;
    }else{
        while(gptr != NULL &&item >= gptr->info){
            pre = gptr;
            gptr= gptr->next;
        }
        if(gptr == lp->start){
            ptr->next = lp->start;
            lp->start = ptr;
        }else if(gptr == NULL){
            lp->end->next = ptr;
            lp->end = ptr;
        }else{
            ptr->next = pre->next;
            pre->next = ptr;
        }
    }
}

// ALL DELETE FUNTIONS

itype deletefir(list * lp){
    node * ptr = lp->start;
    itype temp;
    if(isempty(lp)){
     puts("list is empty");
     return (itype) 0;
    }
    temp = ptr->info;
    lp->start = ptr->next;
    if(lp->start == lp->end)
        lp->end = NULL;
    free(ptr);
    return temp;
}

itype deletelas(list * lp){
    node * ptr = lp->end;
    itype temp;
    if(isempty(lp)){
        puts("list is empty");
        return 0;
    } 
    temp = ptr->info;
    if(lp->start == lp->end)
        init(lp);
    else{
        ptr = previous(lp,ptr->info);
        lp->end = ptr;
        ptr = ptr->next;
        lp->end->next = NULL;
    }
    free(ptr);
    return temp;
}

itype deletegivenitem(list * lp,itype gitem){
    node * gptr = search(lp,gitem),* pptr;
    if(gptr == NULL) {
        puts("given item not found");
        return (itype)0;
    } 
    if(gptr == lp->start){
        return deletefir(lp);
    }
    else if(gptr == lp->end){
        return deletelas(lp);
    }
    else{
        pptr = previous(lp,gitem);
        pptr->next = gptr->next ;
    }
    free(gptr);
    return gitem;
}

itype deletebeforegiven(list * lp,itype gitem){
    node * gptr = previous(lp,gitem);
    if(gptr == NULL)
    {
        puts("item is not found");
        return 0;
    }
    return deletegivenitem(lp,gptr->info);

}

itype deleteaftergiven(list * lp,itype gitem){
    node * gptr = search(lp,gitem)->next;
    if(gptr == NULL) 
    {
        puts("the item is not found");
        return 0;
    }
    return deletegivenitem(lp,gptr->info);
}

itype deleteatposition(list * lp,itype item,int p){
    int n = size(lp),i;
    node * ptr,* pre,*temp;
    if(!(p>=1 && p<= n+1)){
        puts("position is invalid");
        return 0;
    }
    for( i=1,ptr=lp->start,pre = NULL ; i < p ; i++,pre = ptr,ptr = ptr->next);
    temp = create(item);
    if(isempty(lp)){
      lp->start = temp;
      lp->end = temp;
    }
    else if(ptr == lp->start){
        temp->next = lp->start;
        lp->start = temp;
    }
    else if(ptr == NULL ){
        lp->end->next = temp;
        lp->end = temp;
    }
    else{
        temp->next = pre->next;
        pre->next = ptr;
    }
}

int isempty(list * lp){
    if(lp->start == NULL)
        return 1;
    return 0;
}

int size(list * lp){
    node * ptr;
    int c = 0;
    ptr = lp->start;
    while(ptr){
        c++;
        ptr = ptr->next;
    }
    return c;
}

int min(list * lp){
    node * ptr = lp->start;
    int item;
    if(isempty(lp)) {
        puts("the list is empty");
        return 0;
    }
    item = ptr->info;
    ptr = ptr->next;
    while(ptr != NULL){
        if(item >= ptr->info)
            item = ptr->info;
        ptr = ptr->next;
    }
    return item;
}

int max(list * lp){
    node * ptr = lp->start;
    int item;
    if(isempty(lp)) {
        puts("the list is empty");
        return 0;
    }
    item = ptr->info;
    ptr = ptr->next;
    while(ptr != NULL){
        if(item <= ptr->info)
            item = ptr->info;
        ptr = ptr->next;
    }
    return item;
}