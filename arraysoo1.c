#include<stdio.h>
#include<stdlib.h>   
void display(int ar[],int n)
{ 
  int i=0;
  printf("The array elements are:\n");
     for(i=0;i<n;i++) 
         printf("\t%d",ar[i]);
 }           
 void insert(int ar[],int n)
   {
      int ele,loc,i=0;
      printf("Element to be inserted:");
      scanf("%d",&ele);
      printf("Enter the position:");
      scanf("%d",&loc);
      if(i==(ar[n]-1))
        printf("Cant insert,overflow");
      else
      {
        for(i=n;i>=loc-1;i--)
           { 
             ar[i+1]=ar[i];
             
           }
          ar[loc-1]=ele; 
       }
      
      n=n+1;
     printf("Array elements after insertion:");
     for(i=0;i<=n;i++)
       { 
         printf("\t%d",ar[i]);
       }  
     }
void search(int ar[],int n)
  { 
    int i,ele,count=0;
    printf("Enter element to be searched:");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
        if(ar[i]==ele)
          {
            count++;
            break;
           }
     if(count==1)
       printf("Element is found\n");
      else
       printf("Element not found in the array");
    }
void delete(int ar[],int n)
  {
    int loc,i;
    printf("Enter location of the element to be deleted:");
    scanf("%d",&loc);
    if(n==0)
     printf("Underflow");
    else
     {
       for(i=loc;i<n-1;i++)
         {
           ar[i]=ar[i+1];
          }
        n--;
        printf("New array after deletion:");
        for(i=0;i<n;i++)
            printf("\t%d",ar[i]);                        
       }
   }
 void main()
    { 
       int ar[100],ch,n,i;
        printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the array elements:");
       for(i=0;i<n;i++) 
          scanf("%d",&ar[i]);
     
       while(1)
        {    
      printf("Menu:\n 1.Display 2.Insert 3. Search 4.Delete 5.exit\n");
     printf("Enter your choice:");
     scanf("%d",&ch);        
           switch(ch)
               {
                  case 1 :display(ar,n);
                          break;
                  case 2 :insert(ar,n);
                          break;
                  case 3 :search(ar,n);
                          break;
                  case 4 :delete(ar,n);
                         break;
                  default:exit(0);
               }
         }   
       }  
                                                 
