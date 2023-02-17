#include<stdlib.h>
#include<stdio.h>
int isfull(int top,int n)
{ 
  if(top==n)
  return 1;
  else
  return 0;
}
int isempty(int top)
{
 if(top==-1)
 return 1;
 else
 return 0;
}  
void Display(int stack[],int n,int top)
   {
     int i=0; 
     if(top>-1)
      {
     printf("The stack elements are:");
     for(i=top;i>=n;i--)
     {
     printf("\t%d",stack[i]);  
     }
       }  
   }        
 void Push(int stack[],int n,int top)
   {
   int ele;
    printf("Enter the element to be inserted:");
     scanf("%d",&ele);
      if(!isfull(top,n))
       {
         top=top+1;
         stack[top]=ele;
        } 
      else
        {
          printf("Couldn't insert element,stack is full\n");
        }
    }     
 int Pop(int stack[],int n,int top)
   {
     int ele;
     if(!isempty(top))
       { 
         ele=stack[top];
         top=top-1;
         return ele;
       }
      else
        {
          printf("Coudn't retrieve data,stack is empty\n");
        }          
    }
int Peek(int stack[],int n,int top)
    {
      return stack[top];
    }             
 void main()
 {
  int stack[50],top,i,n,ch;
  printf("Enter the size of the stack:");
  scanf("%d",&n);
  printf("Enter the stack elements:");
  scanf("%d",&stack[i]);
  top=(n-1);
  
  
    while(1)
     {
       printf("Menu:\n 1.Display 2.Push 3.Pop 4.Peek 5.Exit \n");
       printf("Enter your choice:");
       scanf("%d",&ch);
      switch(ch)
        {
          case 1: Display(stack,n,top);
                  break;
          case 2: Push(stack,n,top);
                  break;
          case 3: Pop(stack,n,top);
                  break;
          case 4: Peek(stack,n,top);
                  break;
          default: exit(0);
         }                                   
      }
}   
       
