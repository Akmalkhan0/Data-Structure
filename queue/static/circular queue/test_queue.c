#include"queue.c"

int main(){
    queue q;
    itype item;
    int ch;
    init(&q);
    while(1){
        system("cls");
        puts("1 for insert");
        puts("2 for delete");
        puts("3 for peek");
        puts("4 for size");
        puts("5 for display");
        puts("6 for exit");
        printf("Enter your choice: ");
        scanf("%d",&ch);

            switch (ch)
            {
            case 1:
                printf("Enter the item: ");
                scanf("%d",&item);
                insert(&q,item);
                break;
            case 2:
                item = delete(&q);
                if(item != 0){
                    printf("%d is deleted",item);
                }
                break;
            case 3:
                item = peek(&q);
                if(item != 0){
                    printf("%d is peeked",item);
                }
                break;
            case 4:
                printf("%d items found",size(&q));
                break;
            case 5:
                display(&q);
                break;
            case 6:
                exit(0);
            default:
                puts("Entered choice is invalid");
                break;
        }
        getch();
    }
}