#include "tree.c"
#include <conio.h>

void main()
{
  tree t;
  init(&t);
  int choice, item;
  node *ptr;
  while (1)
  {
    system("cls");
    puts("1. INSERT");
    puts("2. PREORDER");
    puts("3. INORDER");
    puts("4. POSTORDER");
    puts("5. MIRROR");
    puts("6. FIND MINIMUM");
    puts("7. FIND MAXIMUM");
    puts("8. SEARCH");
    puts("9. NODE COUNT");
    puts("10. FULLNODE COUNT");
    puts("11. LEAFNODE COUNT");
    puts("12. NON LEAFNODE COUNT");
    puts("13. HEIGHT");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter a Number: ");
      scanf("%d", &item);
      insert(&t, item);
      break;
    case 2:
      preorder(t.root);
      break;
    case 3:
      inorder(t.root);
      break;
    case 4:
      postorder(t.root);
      break;
    case 5:
      mirror(t.root);
      break;
    case 6:
      ptr = minnode(t.root);
      (!ptr) ? printf("the tree is empty") : printf("the minimum item is %d", ptr->info);
      break;
    case 7:
      ptr = maxnode(t.root);
      (!ptr) ? printf("the tree is empty") : printf("the maximum item is %d", ptr->info);
      break;
    case 8:
      printf("Enter the item to Search: ");
      scanf("%d", &item);
      ptr = search(t.root, item);
      (!ptr) ? printf("item not found") : printf("the item %d is found", ptr->info);
      break;
    case 9:
      printf("total node in tree is: %d", nodecount(t.root));
      break;
    case 10:
      printf("total full node in tree is: %d", fullnodec(t.root));
      break;
    case 11:
      printf("total leaf node in tree is: %d", leafnode(t.root));
      break;
    case 12:
      printf("Total non leaf node or parent node is: %d", nonleafnode(t.root));
      break;
    case 13:
      printf("the height of the tree is %d", height(t.root));
      break;
    default:
      exit(1);
    }
    getch();
  }
}