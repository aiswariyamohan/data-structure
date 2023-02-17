#include<stdio.h>
#include<stdlib.h>
void main()
{
   int a[50],b[50],c[50],m,n,i,j,k;
   printf("Enter the size of 1st array:");
   scanf("%d",&m);
   printf("Enter the elements of 1st array in sorted order:");
   for(i=0;i<m;i++)
     scanf("%d",&a[i]);
   printf("Enter the size of 2nd array:"); 
   scanf("%d",&n);
   printf("Enter the elements of 2nd array in sorted order:");
   for(i=0;i<n;i++)
    scanf("%d",&b[i]);  
i=0,j=0;
while(i<m && j<n)
    {
       if(a[i]<b[j])
          { 
             c[k]=a[i];
             i++;
          }    
        else
          {
             c[k]=b[j];
             j++;
          } 
        k++;      
     } 
  if(i>=m)
    {
       while(j<n)
         {
           c[k]=b[j];
           j++;
           k++;
         }         
    }
  if(j>=n)
    {
      while(i<m)
        {
          c[k]=a[i];
          i++;
          k++;
        }        
     } 
 printf("Array after sorting is:\n");
 for(k=0;k<(m+n);k++)
 printf("%d",c[k]);
} 
   
       
