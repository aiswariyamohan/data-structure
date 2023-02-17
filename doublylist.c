#include<stdio.h>
#include<stdlib.h>

void display();
int in_b();
void in_e();
void in_bw();
void dispf();
void dispb();
void del_b();
void del_e();
void del_bw();
struct link
{
    int data;
    struct link *prev;
    struct link *next;
};
typedef struct link node;

node *start,*head,*tail=NULL;

node *create()
   {
       node *nptr=((node*)malloc(sizeof(node)));
       if(nptr==NULL)
          {
            printf("Memory Overflow");
            return 0;
          }
       else
           return nptr;
   } 
   
   void main()
{
    int x;
    printf("Singly linked list\n");
    printf("MENU\n");
    printf("1.Display.\n2.Inserting a node at begining.\n3.Insert a node at the end.\n4.Inserting in between two nodes.\n5.Display forward.\n6.Display backward.\n7.Deletion at begining\n8.Deletion at end\n9.Deletion in between\n");
     while(1)
       {

        printf("\nEnter your choice: ");
        scanf("%d",&x);
            switch(x)
            {
                case 1:
                       display();
                       break;
                case 2:
                       in_b();
                        break;
                case 3:
                       in_e();
                       break;
                case 4:
                        in_bw();
                        break;
                case 5:
                       dispf();
                       break;
                case 6:
                       dispb();
                       break;
                case 7:
                       del_b();
                       break;
                case 8:
                       del_e();
                       break;
                case 9:
                        del_bw();
                        break;                                                   
                default:
                        exit(0);
             }
         }
 }
 void display() 
 {  
   node *current=start;  
    if(current==NULL) 
    {  
        printf("List is empty\n");  
        return;  
    } 
    else
       { 
          printf("Nodes of doubly linked list: \n");  
          while(current!=NULL) 
           {  
             printf("%d\t",current->data);  
             current=current->next;  
           }
       }    
 } 
 int in_b()
 {
    node *nptr=create();
    int e;
    if(nptr==NULL)
    {
       printf("Memory Overflow");
     }
    else
      {
         printf("Enter the item:");
         scanf("%d",&e);
         nptr->data=e;
          if(start==NULL)
            {
               start=nptr;
               nptr->next=NULL;
               nptr->prev=NULL;
             }
           else
              {
                 nptr->next=start;
                 nptr->prev=NULL;
                 start->prev=nptr;
                 start=nptr;
               }
        }
printf("Element inserted successfully!!");
}  

void in_e()
  {
    node *nptr=create();
    node *temp=start;  
    int e;
    if(nptr==NULL)
      printf("Memory Overflow");
    else
       {
         printf("Enter the item:");
         scanf("%d",&e);
         nptr->data=e;
           if(temp==NULL)
             {
                start=nptr;
                nptr->next=NULL;
                nptr->prev=NULL;
              }
            else
               {
                 while(temp->next!=NULL)
                    {
                      temp=temp->next;
                     } 
                temp->next=nptr;
                nptr->prev=temp;
                nptr->next=NULL;           
               } 
        }
printf("Element inserted succesfully.!!");
}

void in_bw()
 {
   node *nptr=create();
   node *temp=start;
   node *ptr;
   int pos,val,c=1;
   printf("Enter the position to be inserted");
   scanf("%d",&pos);
   printf("Enter the element:");
   scanf("%d",&val);
   nptr->data=val;
   nptr->next=NULL; 
     while(temp!=NULL)
         {
           if(c==pos)
              {
                 nptr->next=temp;
                 temp->prev=nptr;
                 nptr->prev=ptr;
                 ptr->next=nptr;
                 break;
               }
           ptr=temp;
           temp=temp->next;
           c++;
          }
   printf("Element inserted successfully.!");
   } 
   
void dispf()
 {
   node *temp;
   temp=start;
   if(temp==NULL)
      printf("Empty List!");
   else
     {
       printf("Linkded list is:\n");
        while(temp!=NULL)
           {
              printf("%d\t",temp->data);
              temp=temp->next;
            }
      }
  }  
  
  void dispb()
   {
       int count;
     node *temp;
     temp=start;
       if(temp==NULL)
         printf("Empty List!.");
       else
         {
           printf("Linked list is:\n");
            while(temp->next!=NULL)
               {
               count=1;
                 temp=temp->next;
                }
            while(temp!=NULL)
               {              
                 printf("%d\t",temp->data);
                 temp=temp->prev; 
               }
           }
     }   
  
  void del_b()
    {
      node *nptr;
      if(start==NULL)
        printf("Empty list.!!");
      else
      {
        nptr=start;
        printf("Element deleted is:%d",nptr->data);
        start=nptr->next;
       }
      nptr->next->prev=NULL;
      free(nptr);
   }
 
 void del_e()
   {
      node *nptr,*temp,*ptr;
      int c;
      if(start==NULL)
        printf("Empty List.!!");
      else
       {
         temp=start;
         while(temp->next!=NULL)
           {
             ptr=temp;
             temp=temp->next;
             c++;
           }
        }
   printf("Element deleted is:%d",temp->data);
   ptr->next=NULL;
   free(temp);
    if(c==1)
      start=NULL;
   }                      
                                       
void del_bw()
  {
     int c=1,pos;
     node *ptr,*temp;
     printf("Enter the position:");
     scanf("%d",&pos);
     temp=start;
      while(temp!=NULL)
         {
           if(c==pos)
             {
               ptr->next=temp->next;
               printf("Element deleted is:%d",temp->data);
               temp->next->prev=ptr;
               free(temp);
             }
           ptr=temp;
           temp=temp->next;
           c++;
         }
   }            
                                                                                                                     
