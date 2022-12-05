//linear probing
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
   insert(arr , 26);
   insert(arr , 30);
   insert(arr , 45);
   insert(arr , 23);
   insert(arr , 25);
   insert(arr , 43);
   insert(arr , 74);
   insert(arr , 19);
   insert(arr , 29);
   
   for(int i = 0; i < size; i++)
   printf("%d\t",arr[i]);

   //searching
   printf("\n key is found at %d\n",search(arr , 74));
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
    while(arr[(index + i) % size] != 0)
    i++;
    return (index + i) % 10; 
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
   i++;
 
   return (index+i)%size;
}