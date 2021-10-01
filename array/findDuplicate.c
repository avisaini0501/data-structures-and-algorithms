//methods of finding duplicate elements in both sorted  and unsorted array  

#include<stdio.h>
#include<stdlib.h>

//function for sorted array
void find_Duplicate();
void duplicate_AND_count();
void duplicate_using_HASH_table();

//function for unsorted array

void find_DUPLICATE();
void find_duplicate_using_hash_table();

int main()
{
  find_Duplicate();
  duplicate_AND_count();
  duplicate_using_HASH_table();
  find_DUPLICATE();
  find_duplicate_using_hash_table();
  find_duplicate_using_hash_table();

  return(0);
}

//only find duplicate with count them

void find_Duplicate()
{
   int arr[10] = {3 ,6 , 8 ,8 ,10 ,12 , 15 , 15 , 15 , 20};
   int i , lastDuplicate = 0 , n = 10;
   
   for(i = 0; i < n ; i++)
   {
      if(arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
      {
         printf("%d\n",arr[i]);
         lastDuplicate = arr[i];
      }
   }
}


//find duplicate and count them
void duplicate_AND_count()
{
   int arr[10] = {3 ,6 , 8 ,8 ,10 ,12 , 15 , 15 , 15 , 20};
   int i , j , n = 10;
   
   for(i = 0; i < n-1; i++)
   {
      if(arr[i] == arr[i + 1])
      {
         j = i+1;

         while(arr[i] == arr[j])
         {
            j++;
         }

         printf("%d element found %d times\n",arr[i] , j - i);

         i = j - 1;
      }
   }
}
  //find duplicate in array using hash table

  void duplicate_using_HASH_table()
  {
     int arr[10] = {3 , 6 , 8 , 8 , 10 , 12 , 15 , 15 ,15 , 20};
     int arrB[21] = {0};
     int n , i ;

     for(i = 0; i < n; i++)
     {
        arrB[arr[i]]++;
     }    

     for(i = 0; i <= 20; i++)
     {
        if(arrB[i] > 1)
        {
           printf("%d found %d times\n",i , arrB[i]);
        }
     }
  }

//find duplicate in unsorted array

void find_DUPLICATE()
{
   int arr[10] = {8 , 3 , 6 , 4 , 6 , 5 , 6 , 8 , 2 , 7};
   int i , j , count , n = 10;

   for(i = 0; i < n - 1; i++)
   {
      count  = 1;
      if(arr[i] != -1)
      {
         for(j = i + 1; j < n ; j++)
         {
            if(arr[i] == arr[j])
            {
               count++;
               arr[j] = -1;
            }
         }

         if(count > 1)
         printf("%d found %d times\n",arr[i], count);
      }

   }
}

void find_duplicate_using_hash_table()
{
   int arrA[10] = {8 , 3 , 6 , 4 , 6 , 5 , 6 , 8 , 2 , 7};
   int H[9] = {0};
   int i , j , n = 10;

   for(i = 0; i < n; i++)
   {
     H[arrA[i]]++;
   }

   for(i = 0; i <= 8; i++)
   {
      if(H[i] > 1)
      printf("%d found %d times\n",i,H[i]);
   }
}



