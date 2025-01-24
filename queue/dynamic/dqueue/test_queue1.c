#include "queue1.c"

int main(){
    queue q;
    itype item;
    int ch;
    init(&q);
    while(1){
        system("cls");
        puts("1. for insert at front");
        puts("2. for insert at rear");
        puts("3. for delete at front");
        puts("4. for delete at rear");
        puts("5. for peek at front");
        puts("6. for peek at rear");
        puts("7. for size of the queue");
        puts("8. for display");
        puts("9. for exit");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                puts("Enter item");
                scanf("%d",&item);
                insertf(&q,item);
                break;
            case 2:
                puts("Enter item");
                scanf("%d",&item);
                insertl(&q,item);
                break;
            case 3:
                item = deletef(&q);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
            case 4:
                item = deletel(&q);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
            case 5:
                item = peekf(&q);
                if(item != 0){
                    printf("%d item is peeked",item);
                }
                break;
            case 6:
                item = peekl(&q);
                if(item != 0){
                    printf("%d item is peeked",item);
                }
                break;
            case 7:
                printf("%d is the size of queue",size(&q));
                break;
            case 8:
                display(&q);
                break;
            case 9:
                exit(0);
            default:
            printf("Entered choice is invalid\n");
        }
        getch();

    }
}