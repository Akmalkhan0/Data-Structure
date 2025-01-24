#include "queue1.c"

int main(){
    queue q;
    itype item;
    int ch;
    init(&q);
    while(1){
        system("cls");
        puts("1. for insert");
        puts("2. for delete");
        puts("3. for peek");
        puts("4. for size");
        puts("5. for display");
        puts("6. for exit");
        printf("Enter you choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                puts("Enter item");
                scanf("%d",&item);
                insert(&q,item);
                break;
            case 2:
                item = delete(&q);
                if(item != 0)
                    printf("%d item is deleted",item);
                break;
            case 3:
                item = peek(&q);
                if(item != 0)
                    printf("%d item is peeked",item);
                break;
            case 4:
                printf("%d is the size of queue",size(&q));
                break;
            case 5:
                display(&q);
                break;
            case 6:
                exit(1);
                break;
            default:
                puts("Enter choice is invalid");
           }
        getch();
    }
}