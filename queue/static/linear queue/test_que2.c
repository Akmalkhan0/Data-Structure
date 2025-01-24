#include<stdio.h>
#include "queue1.c"
int main(){
    queue q1;
    itype item;
    int ch;
    inti(&q1);

    while(1){
        system("cls");
        puts("1 for insert");
        puts("2 for delete");
        puts("4 for peek");
        puts("4 for size");
        puts("5 for display");
        puts("6 for exit");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d",&item);
                insert(&q1,item);
                break;
            case 2:
                item = delete(&q1);
                if(item != 0){
                    printf("%d is deleted",item);
                }
                break;
            case 3:
                item = delete(&q1);
                if(item != 0){
                    printf("%d is peeked",item);
                }
                break;
            case 4:
                printf("the sizeof queue is %d",size(&q1));
                break;
            case 5:
                display(&q1);
                break;
            case 6:
                exit(0);
            default:
                puts("Enter a valid choice");
        }
        getch();
    }
}