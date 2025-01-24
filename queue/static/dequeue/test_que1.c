//linear queue dequeue

#include "queue1.c"

int main(){
    queue q;
    itype item;
    int ch;

    init(&q);
     while(1){
        system("cls");
        puts("1 for insert front");
        puts("2 for insert rear");
        puts("3 for delete front");
        puts("4 for delete rear");
        puts("5 for peek front");
        puts("6 for peek rear");
        puts("7 for size");
        puts("8 for display");
        puts("9 for exit");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter the item: ");
            scanf("%d",&item);
            insfront(&q,item);
            break;
        case 2:
            printf("Enter the item: ");
            scanf("%d",&item);
            insrear(&q,item);
            break;
        case 3:
            item = dltfront(&q);
            if(item != 0){
                printf("%d item is deleted from front",item);
            }
            break;
        case 4:
            item = dltrear(&q);
            if(item != 0){
                printf("%d item is deleted from rear",item);
            }
            break;
        case 5:
            item = peekfr(&q);
            if(item != 0){
                printf("%d item is peek from front",item);
            }
            break;
        case 6:
            item = peekrr(&q);
            if(item != 0){
                printf("%d item is peek from rear",item);
            }
            break;
        case 7:
            printf("%d is a size of queue",size(&q));
            break;
        case 8:
            display(&q);
            break;
        case 9:
            exit(0);
        
        default:
            puts("ENtered choice is invalid");
            break;
        }
        getch();
     }
}