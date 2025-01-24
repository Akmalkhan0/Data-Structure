#include"stack1.c"

int main(){
   stack s1;
   itype item;
   int ch,temp;
   init(&s1);

   while(1){
      system("cls");
      puts("-------Menu------");
      puts("  1 For push");
      puts("  2 For pop");
      puts("  3 For peek");
      puts("  4 For size");
      puts("  5 For check empty");
      puts("  6 For check full");
      puts("  7 For Exit");
      printf("Enter your choice: ");
      scanf("%d",&ch);

      switch (ch)
      {
         case 1:
            printf("Enter item for push: ");
            scanf("%d",&item);
            push(&s1,item);
            break;
         case 2:
            item = pop(&s1);
            if(item != 0)
               printf("%d is poped",item);
            break;
         case 3:
           item = peek(&s1);
           if(item != 0)
               printf("%d is peeked",item);
            break;
         case 4:
            printf("the %d elemnts found in stack",size(&s1));
            break;
         case 5:
            printf(isempty(&s1)?"The stack is empty\n":"the stack is not empty\n");
            break;
         case 6:
            printf(isfull(&s1)?"The stack is full\n":"the stack is not full\n");
            break;
         case 7:
            exit(0);
         default:
         puts("Enter a valid choice");
         break;
      }
      getch();
   }
}

