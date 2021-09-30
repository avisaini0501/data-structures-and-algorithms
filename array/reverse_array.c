//program to ravarse an array
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[10] = {1,3,6,15,16,19,7,8,2,12};
    int rev[10] = {};
    int i , j , length = 10;

    for(i = 0; i <length; i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\n\n");
     
    for(i = length - 1, j = 0; i >= 0; i--,j++)
    {
        rev[j] = arr[i];
    }

    for(i = 0; i < length; i++)
    {
        arr[i] = rev[i];
    }

    for(i = 0; i < length; i++)
    {
        printf("%d\t",arr[i]);
    }
}