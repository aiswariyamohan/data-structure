#include<stdlib.h>
#include<stdio.h>
void Push();
void Pop();
void Display();

struct node
   {
     int val;
     struct node *next;
   };
   struct node *head;
   
 void main()
   {
     int ch=0;
     printf("Stack Implementation using linked list");
     while(ch!=4)
        {
           printf("\nMENU\n\n1.Push\n2.Pop\n3.Display\n");
           printf("Enter your choice:");
           scanf("%d",&ch);
         switch(ch)
            {
             
              case 1:Push();
                      break;
              case 2:Pop();
                     break;
              case 3:Display();
                     break;
              default:printf("WRONG INPUT");
                      exit(0);
              }
         }
     }
void Push()
  {
     int val;
     struct node *ptr=(struct node*)malloc(sizeof(struct node));
       if(ptr==NULL)
          printf("Can't Push element!!");
       else
          {
             printf("Enter the value to be inserted:");
             scanf("%d",&val);
               if(head==NULL)
                   {
                      ptr->val=val;
                      ptr->next=NULL;
                      head=ptr;
                   }
                else
                   {
                      ptr->val=val;
                      ptr->next=head;
                      head=ptr;
                   }
               printf("Item Pushed!!");
           }
   }
 void Pop()
   {
      int item;
      struct node *ptr;
      if(head==NULL)
        printf("Underflow!!");
      else
         {
           item=head->val;
           ptr=head;
           head=head->next;
           free(ptr);
          } 
           printf("Item Popped!!");
   }
   
 void Display()
   {
     int i;
     struct node*ptr;
     ptr=head;
      if(ptr==NULL)
        printf("Stack is empty!!");
      else
        {
         printf("Stack elements are:\n");
         while(ptr!=NULL)
           {
              printf("%d\t",ptr->val);
              ptr=ptr->next;
            }
        }
   }                                                                                              
