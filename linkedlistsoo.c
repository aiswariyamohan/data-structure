#include<stdio.h>
#include<stdlib.h>

struct node
  {
     int value;
     struct node *link;
  }
typedef struct node node1;
node1 *ptr=head;
   node1*create()
     {
       node1 *nptr=((node1*)malloc(sixe of(node1));
       if(nptr==NULL)
          {
            printf("Memory Overflow");
            return 0;
          }
        else
            return nptr;
      }            
void display()
   {
      node1 *ptr=head;
      printf("Elements in the linked list are:");
      while(ptr!=NULL)
         {
           print(ptr->data;
           ptr=ptr->next;
         }
   }
void in_b()
   {
     int val;
     printf("Enter the element to be inserted:");
     scanf("%d",&val);
     *nptr=create();
     nptr->value=val;
     if(start==NULL)
       {
         start=nptr;
         nptr->link=NULL;
        }
      else
        {
          nptr->link=start;
          start=nptr;
         }
    }
void  in_e()
    {
      *nptr=create();
      int val;
       printf("Enter the element to be inserted:");
       scanf("%d",&val);
      nptr->value=val;
      nptr->link=NULL;
      temp=start;
      while(temp->link!=NULL)	
        {
          temp=temp->link;
        }
       temp->link=nptr;
     }
void in_bw()
    {
      node1 *temp,*nptr=create();
      int val,pos,i;
      printf("Enter the element and position to be inserted:");
      scanf("%d %d",&val,&pos);
      nptr->value=val;
      nptr->link=NULL;
      temp=start;
      if(pos==1)
       {
         nptr->link=start;
         start=nptr;
       }
      else
        {
          for(i=1;i<pos-1;i++)
            temp=temp->link;
         }
      nptr->link=temp->link;
      temp->link=nptr;
    }
 void del_b()
    {
      node1 *temp;
      if(start==NULL)
       printf("List is empty!");
      else
       temp=start;
       start=start->link;
       free(temp);
     }
void del_e()
    {
      node1 *temp,*prev;
      temp=start;
      while(temp->link!=NULL)
        {
          prev=temp;
          temp=temp->link;
         }
      prev->link=NULL;
      free(temp);
    }
void del_bw()
   {
     node1 *temp,*prev;
     int i,pos;                                       
                                   
