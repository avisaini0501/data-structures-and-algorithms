//program to insert an element in an arrray

#include<stdio.h>
#include<stdlib.h>

void insert(int index, int x); //here x is element

int main()
{
   int index = 4; 
   int x = 15;
   insert(index,x);    
}

void insert(int index, int x)
{
    int arrA[10] = {8,3,7,12,6,9,10};
    int i , length = 7;

    for(i = 0; i < length; i++)
    {
        printf("%d\t\n\n",arrA[i]);
    }

    for(i = length; i > index; i--)
    {
       arrA[i] = arrA[i-1];
    }

    arrA[i] = x;
    length++;

    for(i = 0; i < length; i++)
    {
       printf("%d\t",arrA[i]);
    }
}