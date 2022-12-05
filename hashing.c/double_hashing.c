//double probing
#include<stdio.h>
#include<stdlib.h>
#define size 10
#define prime 7

int hash(int key);
int probe(int arr[] , int key);
void insert(int arr[] , int key);
int search(int arr[] , int key);
int prime_hash(int key);
int main()
{
   int arr[size] = {0};
   insert(arr , 5);
   insert(arr , 25);
   insert(arr , 15);
   insert(arr , 35);
   insert(arr , 95);
   
   for(int i = 0; i < size; i++)
   printf("%d\t",arr[i]);

   //searching
   printf("\n key is found at %d\n",search(arr , 15));
}
int hash(int key)
{
   int index = key % 10;
   return index;
}
int prime_hash(int key)
{
    return prime - (key % prime);
}
int probe(int arr[] , int key)
{
    int index = hash(key);
    int i = 0;
    while(arr[(index + i * prime_hash(index)) % size] != 0)
    i++;
    return (index + i * prime_hash(index)) % size; 
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
 
   while(arr[(index+i * prime_hash(index))%size]!=key)
   {
      i++;
      if(arr[(index + i * prime_hash(index))%size] == 0)
      return -1;      
   }
   return (index + i * prime_hash(index))%size;
}