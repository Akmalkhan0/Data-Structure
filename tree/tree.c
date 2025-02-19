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
void mirror(node * ptr);
void preorder(node * ptr);
void inorder(node * ptr);
void postorder(node * ptr);

int nodecount(node * ptr);
int fullnodec(node * ptr);
int leafnode(node * ptr);
int nonleafnode(node * ptr);
int height(node * ptr);

node * search(node * ptr,itype item);
node * maxnode(node * ptr);
node * minnode(node * ptr);
node * create(itype item);
itype delete(tree * tp,itype item);



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


void preorder(node * ptr){
  if(ptr){
    printf("%d ",ptr->info); 
    preorder(ptr->lptr);
    preorder(ptr->rptr);
  }
}
void inorder(node * ptr){
  if(ptr){
    inorder(ptr->lptr);
    printf("%d ",ptr->info); 
    inorder(ptr->rptr);
  }
}
void postorder(node * ptr){
  if(ptr){
    postorder(ptr->lptr);
    postorder(ptr->rptr);
    printf("%d ",ptr->info); 
  }
}

void mirror(node * ptr){
  if(ptr){
    node * temp = ptr->lptr;
    ptr->lptr = ptr->rptr;
    ptr->rptr = temp;
    mirror(ptr->lptr);
    mirror(ptr->rptr);
  }
}

int nodecount(node * ptr){
  if(ptr == NULL)
    return 0;
  else
    return 1+nodecount(ptr->lptr)+nodecount(ptr->rptr);
}

int fullnodec(node * ptr){
  if((ptr == NULL) || (ptr->lptr == ptr->rptr))
    return 0;
  else if (ptr->lptr != NULL && ptr->rptr != NULL)
    return 1+fullnodec(ptr->lptr)+fullnodec(ptr->rptr);
  else
    return fullnodec(ptr->lptr)+fullnodec(ptr->rptr);
}

int leafnode(node * ptr){
  if(ptr == NULL)
    return 0;
  else if(ptr->lptr == ptr->rptr)
    return 1;
  else
    return leafnode(ptr->lptr)+leafnode(ptr->rptr);
}

int nonleafnode(node * ptr){
  if(ptr == NULL || ptr->lptr == ptr->rptr)
    return 0;
  else if(ptr->lptr|| ptr->rptr)
    return 1+nonleafnode(ptr->lptr)+nonleafnode(ptr->rptr);
}

// int height(node * ptr){
//   int l,r;
//   if(ptr == NULL || ptr->lptr == ptr->rptr)
//     return 0;
//   l = height(ptr->lptr);
//   r = height(ptr->rptr);
//   return 1+(r>l)?r:l;
// }

int height(node * ptr){
  if(!ptr || ptr->lptr == ptr->rptr)
    return -1;
  else{
    int l = height(ptr->lptr),r = height(ptr->rptr);
    return 1+(l>r)?l:r;
  }
}

node * minnode(node * ptr){
  if(ptr == NULL)
    return NULL;
  else if(ptr->lptr == NULL)
    return ptr;
  else 
    return minnode(ptr->lptr);
}

node * maxnode(node * ptr){
  if(ptr == NULL)
    return NULL;
  else if(ptr->rptr == NULL)
    return ptr;
  else 
    return maxnode(ptr->rptr);
}

node * search(node * ptr,itype item){
  if(ptr){
    if(ptr->info == item)
      return ptr;
    else if(ptr->info > item)
      return search(ptr->lptr,item);
    else
      return search(ptr->rptr,item);
  }
  return NULL;
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