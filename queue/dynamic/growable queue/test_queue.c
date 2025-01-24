#include"queue.c"

int main(){
    queue q;
    itype item;
    int ch;
    init(&q,10);

    while(1){
        system("cls");
        puts("1 for insert");
        puts("2 for delete");
        puts("3 for peek");
        puts("4 for capacity");
        puts("5 for size");
        puts("6 for display");
        puts("7 for Exit");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                puts("Enter item");
                scanf("%d",&item);
                insert(&q,item);
                break;
            case 2:
               item =  delete(&q);
               if(item != -1)
                    printf("%d item is deleted",item);
                break;
            case 3:
               item =  peek(&q);
               if(item != -1)
                    printf("%d item is peeked",item);
                break;
            case 4:
               printf("%d is the capacity of queue",capacity(&q));
                break;
            case 5:
               printf("%d is the size of queue",size(&q));
                break;
            case 6:
                display(&q);
                break;
            case 7:
                exit(0);
            default:
                puts("Entered choice is invalid");
        }
        getch();
    }
}