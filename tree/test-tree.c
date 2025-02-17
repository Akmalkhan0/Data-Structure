#include "tree.c"

void main(){
  tree t;
  init(&t);
  insert(&t,10);
  insert(&t,11);
  insert(&t,18);
  insert(&t,6);
  insert(&t,9);
  insert(&t,100);
  display(t.root);
}