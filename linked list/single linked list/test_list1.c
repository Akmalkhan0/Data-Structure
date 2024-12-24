#include "list1.c"

int main(){
    list l;
    itype item,gitem;
    int ch,p;
    node * ptr;

    init(&l);
    while(1){
        system("cls");
        puts("1 for insert from last");
        puts("2 for insert from first");
        puts("3 for insert after given");
        puts("4 for insert before given");
        puts("5 for display");
        puts("6 for search item");
        puts("7 for size");
        puts("8 for delete first");
        puts("9 for delete last");
        puts("10 for delete given item");
        puts("11 for delete before given item");
        puts("12 for delete after given item");
        puts("13 for min");
        puts("14 for max");
        puts("15 for insert at given position");
        puts("16 for insert at sorted list");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                puts("Enter the item");
                scanf("%d",&item);
                inslast(&l,item);
                break;
            case 2:
                puts("Enter the item");
                scanf("%d",&item);
                insfirst(&l,item);
                break;
            case 3:
                puts("Enter the given item");
                scanf("%d",&gitem);
                puts("Enter item");
                scanf("%d",&item);
                insaftergiven(&l,gitem,item);
                break;
            case 5:
                display(&l);
                break;
            case 4:
                puts("Enter the given item");
                scanf("%d",&gitem);
                puts("Enter item");
                scanf("%d",&item);
                insbeforegiven(&l,gitem,item);
                break;
            case 6: 
                printf("Enter the searching item: ");
                scanf("%d",&item);
                ptr = search(&l,item);
                if(ptr != NULL)
                printf("%d item is found\n",ptr->info);
                else{
                    puts("Enter item is not found");
                }
                break;
            case 7:
                printf("%d is the size of list",size(&l));
                break;
            case 8:
                item = deletefir(&l);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
            case 9:
                item = deletelas(&l);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
            case 10:
                puts("Enter the for deletion");
                scanf("%d",&gitem);
                item = deletegivenitem(&l,gitem);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
            case 11:
                puts("Enter the for delete");
                scanf("%d",&gitem);
                item = deletebeforegiven(&l,gitem);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
             case 12:
                puts("Enter the for delete");
                scanf("%d",&gitem);
                item = deleteaftergiven(&l,gitem);
                if(item != 0){
                    printf("%d item is deleted",item);
                }
                break;
            case 13:
                printf("%d is the min",min(&l));
                break;
            case 14:
                printf("%d is the min",max(&l));
                break;
            case 15:
                puts("enter the position to insert element");
                scanf("%d",&p);
                puts("enter item");
                scanf("%d",&item);
                insertatp(&l,item,p);
                break;
            case 16:
                puts("enter item");
                scanf("%d",&item);
                insertsort(&l,item);
                break;
            default:
                exit(1);
        }
        getch();
    }
}