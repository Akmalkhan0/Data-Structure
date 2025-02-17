#include <stdio.h>
#include <stdlib.h>

typedef int itype;

// node structure declaratioin
typedef struct node
{ 
  struct node *lptr, *rptr;
  itype info;
} node;

// tree structure declation
typedef struct{
node * root;
}tree;

// all funtion declaration
void init(tree * tptr);
void insert(tree * tp,itype item);
node * create(itype item);


void init(tree * tptr){
  tptr->root = NULL;
}

void insert(tree * tp,itype item){
  node * ptr = create(item),* gptr;
  if(ptr == NULL)
    return;
  gptr = tp->root;
  if(tp->root == NULL)
    tp->root = ptr;
  else{
    while(1){
      if(gptr->info>ptr->info){
        if(gptr->lptr == NULL){
          gptr->lptr = ptr;
          break;
        }
        gptr = gptr->lptr;
      }
      else if(gptr->info == ptr->info){
        return;
      }
      else{
        if(gptr->rptr == NULL){
          gptr->rptr = ptr;
          break;
        }
        gptr = gptr->rptr;
      }
    }
  }
}


void display(node * ptr){
  if(ptr){
    printf("%d ",ptr->info); 
    if(ptr->lptr)
      display(ptr->lptr);
    if(ptr->rptr)
      display(ptr->rptr);
  }
}

node * create(itype item){
  node * ptr = (node *) malloc(sizeof(node));
  if(ptr == NULL){
    puts("the memory is full");
    return NULL;
  }
  ptr->info = item;
  ptr->lptr = NULL;
  ptr->rptr = NULL;
  return ptr;
}