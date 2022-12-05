//quadrative probing
#include<stdio.h>
#include<stdlib.h>
#define size 10

int hash(int key);
int probe(int arr[] , int key);
void insert(int arr[] , int key);
int search(int arr[] , int key);
int main()
{
   int arr[size] = {0};
   insert(arr , 23);
   insert(arr , 43);
   insert(arr , 13);
   insert(arr , 27);
   
   for(int i = 0; i < size; i++)
   printf("%d\t",arr[i]);

   //searching
   printf("\n key is found at %d\n",search(arr , 1));
}
int hash(int key)
{
   int index = key % 10;
   return index;
}
int probe(int arr[] , int key)
{
    int index = hash(key);
    int i = 0;
    while(arr[(index + i*i) % size] != 0)
    i++;
    return (index + i*i) % 10; 
}
void insert(int arr[] , int key)
{
    int index = hash(key);
    if(arr[index] != 0)
    index = probe(arr , key);

    arr[index] = key;
}
int search(int arr[] , int key)
{
  int index=hash(key);
 
   int i=0;
 
   while(arr[(index+i)%size]!=key)
   {
      i++;
      if(arr[(index + i * i)%size] == 0)
      return -1;      
   }
   return (index + i * i)%size;
}