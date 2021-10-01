//to test array is sort or not
#include<stdio.h>
#include<stdlib.h>

int is_sort();
int main()
{
    int a;
    a = is_sort();
     printf("%d",a);
   return(0);

}

int is_sort()
{
      int arr[10] = {2,4,5,7,8,9,10,11,12,3};
   int i;
   
   for(i = 0; i < 9; i++)
   {
       if(arr[i] < arr[i + 1])
       {
           return(1);
       }
   }

   return(-1);
}