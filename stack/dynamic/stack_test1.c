#include "stack1.c"
int main(){
    stack s;
    itype item;
    int choice;
    init(&s);
    while(1){
        system("cls");
        puts("1. Push In Stack");
        puts("2. Pop In Stack");
        puts("3. Peek In Stack");
        puts("4. Size of Stack");
        puts("5. Display Stack");
        puts("6. Exit");
        printf("Enter the size of the stack: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                puts("Enter the item");
                scanf("%d",&item);
                push(&s,item);
                break;
            case 2:
                item = pop(&s);
                if(item != 0)
                    printf("%d item is deleted",item);
                break;
            case 3:
                item = peek(&s);
                if(item != 0)
                    printf("%d item is peeked",item);
                break;
            case 4:
                printf("%d item is found in stack",size(&s));
                break;
            case 5: 
                display(&s);
                break;
            case 6:
                exit(1);
            default:
                puts("Enter choice is invalid");
        }
        getch();
    }
}