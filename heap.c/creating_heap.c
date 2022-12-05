//creating a heap
#include<stdio.h>
#include<stdlib.h>

void create_heap();
void insert(int arr[] , int n);

int main() 
{
     create_heap();
     return 0;
}
void create_heap()
{
    int x = 1;
    int arr[] = {0 , 10 , 20 , 30 , 25 , 5 , 40 , 35};
    int i;
    for(i = 2 ; i <= 7; i++)
    {
        insert(arr , i);
    }
    while(x <= 7)
    printf("%d\t",arr[x++]);
}
void insert(int arr[] , int n)
{
    int temp , i = n;
    temp = arr[n];
    while(i > 1 && temp > arr[i/2])
    {
        arr[i] = arr[i / 2];
        i = i/2;
    }
    arr[i] = temp;
}
