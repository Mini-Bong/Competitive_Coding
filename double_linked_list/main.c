#include <stdio.h>
#include <stdlib.h>
char option;
struct dll
{
    int item;
    struct dll *next;
    struct dll *previous;
}*first=NULL, *next=NULL, *temp=NULL, *new_node=NULL;
void creation()
{

}
int main()
{
    do
    {
        int choice;
        printf("Enter your choice:\n");
        printf("1.Creation\n2.Insertion\n3.Deletion\n4.Display\n5.exit");
        scanf("%d",&choice);
        switch(choice)
               {
               case 1:
                creation();
                break;
               case 2:
                insertion();
                break;
               case 3:
                deletion();
                break;
               case 4:
                display();
                break;
               case 5:
                exit(0);
               }
               printf("Do you want to continue?\n");
               scanf("%c",&option);
    }while(option!='n');

    return 0;
}
