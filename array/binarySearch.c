//binary search
//for binary search array always should be in sorted manner
#include<stdio.h>
#include<stdlib.h>


 
//binary search algorithm using loop
int algorithm_bin_search( int low, int high,int key);
//binary search algorithm using recurtion
int algorithm_recur_bin_search(int low, int high, int key);

int main()
{
   int low = 0,high = 14,key,result;

   printf("enter an element to search\n");
   scanf("%d",&key);

   result = algorithm_recur_bin_search(low,high,key);
   printf("%d\n",result);

   return(0);
}

int algorithm_bin_search(int low, int high, int key)
{
   int i,mid,arr[15] = {4,8,10,15,18,21,24,27,29,33,34,37,39,41,43};
   
   while(low <= high)
   {
       mid = ((low + high) / 2);

       if(key == arr[mid])
       return mid;

       else if(key < arr[mid])
       high = mid - 1;

       else if(key > arr[mid])
       low = mid + 1;      
   }

   return (-1);
}

int algorithm_recur_bin_search(int low, int high, int key)
{
   int i,mid,arr[15] = {4,8,10,15,18,21,24,27,29,33,34,37,39,41,43};
   
   if(low <= high)
   {
       mid = ((low + high) / 2);

       if(key == arr[mid])
       return mid;

       else if(key < arr[mid])
       return algorithm_recur_bin_search(low , mid - 1 , key);

       else if(key > arr[mid])
       return algorithm_recur_bin_search(mid + 1 , high , key);
   }

   return (-1);
}
