//program to find missing elements in both sorted and unsorted array

#include<stdio.h>
#include<stdlib.h>
//only for one element is missing

//function for finding missing element for first n natural numbers in sorted array
void missing_element();
//function to find missing element in sorted array (this method not for first n natural numbers)
void find_element();

//now function for multielements missing in sorted array
void multi_element_missing();

//now for unsorted array
void missing_element_in_unsorted();




int main()
{
   
   missing_element_in_unsorted();
    return(0);

}

void missing_element()
{
    int arr[11] = {1 , 2 , 3 , 4 , 5 , 6 , 8 , 9 , 10 , 11 , 12 };
    int i , sum = 0 , n = 12 , s;//here n is the last element of array

    for(i = 0; i < 11; i++)
    {
        sum = sum + arr[i];
    }
    
    s = n * (n + 1) / 2; //this is a formula for f,ind sum of first n natural numbers
    printf("%d is the missing element\n",s - sum);
}

//function to find missing element in sort array
void find_element()
{
    int arr[11] = {6 , 7 , 8, 9 , 10 , 11 , 13 , 14 , 15 , 16 , 17};
    int i , l = 6 , h = 17 , n = 11 , diff =  l - 0;
    for(i = 0; i < 11; i++)
    {
        if(arr[i] - i != diff)
        {
           printf("%d is missing\n",i + diff);
           break;
        }
    }
}

void multi_element_missing()
{
    int arr[11] = {6  ,7 ,8 ,9 ,11 , 12 , 15 , 16 , 17 , 18 , 19};
    int diff = 6 , n = 11 , i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] - i != diff)
        {
            while(diff < arr[i] - i)
            {
                printf("%d is missing\n",i + diff);
                diff++;
            }
        }
    }
}

void missing_element_in_unsorted()
{
  int arr[10] = {3, 7 , 4 , 9 , 12 ,6 , 1 , 11 , 2 , 10};
  int arrH[13] = {0};
  int i , l = 1, h = 12 ,n = 10;
  
  for(i = 0; i < n; i++)
  {
    arrH[arr[i]]++; 
  }

  for(i = l; i <= h; i++)
  {
      if(arrH[i] == 0)
      {
        printf("%d is missing\n",i);
      }
  } 


}