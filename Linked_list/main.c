#include <stdio.h>
#include <stdlib.h>
char option;
struct sll
{
   int item;
   struct sll *next;

} *first=NULL,*temp=NULL,*new_node=NULL,*last=NULL;
      void insertion()
      {

          int choice1;
          printf("1.insert_at_first\n2.insert_at_last\n3.insert_in_between\n");
          scanf("%d",&choice1);
          switch(choice1)
          {
         case 1:
               {
                   new_node=(struct sll*)malloc(sizeof(struct sll));
                   printf("enter the item: ");
                   scanf("%d",&new_node->item);
                   new_node->next=first;
                   first=new_node;
               }
               break;
          case 2:
              {
                  new_node=(struct sll*)malloc(sizeof(struct sll));
                  printf("enter the item: ");
                  scanf("%d",&new_node->item);
                  for(last=first;last->next!=NULL;last=last->next);
                  last->next=new_node;
                  new_node->next=NULL;
                  last= new_node;
              }
              break;
            case 3:
              {
                  int value;
                  printf("enter the value from where you want to insert: ");
                  scanf("%d",&value);
                  new_node=(struct sll*)malloc(sizeof(struct sll));
                  printf("Enter the element: ");
                  scanf("%d",&new_node->item);
                  for(last=first;last->item!=value;last=last->next);
                  if(last==NULL)
                    printf("Element not found");
                  else
                  {
                      temp=last->next;
                      last->next=new_node;
                      new_node->next=temp;
                  }
              }
              break;
          }
      }

void deletion()
{
   int choice2;
   printf("1.delete_first_node\n2.delete last node\n3.delete in between\n");
   scanf("%d",&choice2);
   switch(choice2)
   {
   case 1:
      {
          temp=first;
          first=first->next;
          free(temp);
      }
      break;
    case 2:
      {
          for(last=first;last->next->next!=NULL;last=last->next);
          temp=last->next;
          last->next=NULL;
          free(temp);
      }
      break;
     case 3:
      {
          int value1;
          printf("enter a value: ");
          scanf("%d",&value1);
          for(last=first;last->next->item!=value1;last=last->next);
          temp=last->next;
          last->next=last->next->next;
          free(temp);
      }
      break;
   }
}
void display()
{
   for(temp=first;temp!=NULL;temp=temp->next)
   {
    printf("%d\t",temp->item);
   }
   printf("\n");
}

void creation()
{
 if(first==NULL)
 {
    new_node=(struct sll*)malloc(sizeof(struct sll));
    if(new_node==NULL)
        printf("Cannot allocated");
    else
    {
        printf("Enter the item: ");
        scanf("%d",&new_node->item);
        new_node->next=NULL;
        first=new_node;
        last=new_node;

    }
 }
 else
 {
     new_node=(struct Sll *)malloc(sizeof(struct sll));
     if(new_node==NULL)
        printf("cannot allocate");
     else
     {
         printf("enter the item: ");
         scanf("%d",&new_node->item);
         last->next=new_node;
         last=new_node;
         last->next=NULL;
     }
 }

}

int main()
 {
     do
     {
           int choice;
           printf("1.creation\n2.insertion\n3.deletion\n4.Display\n5.exit\n");
           printf("Enter your choice\n");
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
     }
   while(option!='n');
 }

