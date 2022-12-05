//deletion with sorting in heap
#include<stdio.h>
#include<stdlib.h>

void create_heap(int arr[]);
void insert(int arr[] , int n);
int delete_and_sort(int arr[] , int n);

int main()
{
    int i = 1 , j = 7 , k = 3 , min;
    int arr[] = {0 , 40 , 35 , 30 , 15 , 10 , 25 , 5};
    create_heap(arr);
    while(j >= 1)
    {
      printf("deleted value is %d\n",delete_and_sort(arr , j));
      j--;
    }
    for(i = 1; i <= 7; i++)
    {
        printf("%d\t",arr[i]);
    }
    for(int i = 0; i <= k; i++)
    {
       min = arr[i];
       
    }
    printf("\n%d\n", min);
    return 0;
}
void create_heap(int arr[])
{
    int i;
    for(i = 2; i <= 7; i++)  
    {
        insert(arr , i);
    }
}
void insert(int arr[] , int n)
{
    int temp , i = n;
    temp = arr[n];
    while(i > 1 && temp > arr[i / 2]) 
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = temp;
}
//here n is size of array
int delete_and_sort(int arr[] , int n)
{
    int i , j , temp , x , val;
    val  = arr[1];
    x = arr[n];
    arr[1] = x;
    arr[n] = val;
    i = 1; j = i + 1;
    while(j < n - 1)
    {
        //comparasion between children of root node
        if(arr[j] < arr[j + 1])
        j = j + 1;

        if(arr[i] < arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
          break;
        } 
    }
    return val;
}