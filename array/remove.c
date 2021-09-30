//program to delete an element from an array
#include<stdio.h>
#include<stdlib.h>

void rem(int index);

int main()
{
    int index;

    printf("enter the index number to delete\n");
    scanf("%d",&index);

    rem(3);
    
    return(0);
}

void rem(int index)
{
    int arr[10] = {8,3,7,12,15,6,9,10};
    int i , length = 8 , x;

    for(i = 0; i < length; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    x = arr[index];

    printf("the x is = %d\n",x);

    for(i = index; i < length - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    length--;
    
    for(i = 0; i < length; i++)
    {
        printf("%d\t",arr[i]);
    }
}