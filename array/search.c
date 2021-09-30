//program to search an element in an array

#include<stdio.h>
#include<stdlib.h>

int search(int x);

int main()
{
    int x;

    printf("enter an element to be search\n");
    scanf("%d",&x);

    search(x);

    printf("%d is present at %dth position\n",x,search(x));

    return(0);
}

int search(int x)
{
    int arr[10] = {8,9,4,7,6,3,10,5,14,2};
    int i, length = 10, choice;

    for(i = 0; i < length; i++)
    {
       if(x == arr[i])
       {
           arr[i - 1] = arr[i];
           return(i -1);
       }
        
    }

   search(x);

    return -1;




}

