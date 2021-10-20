//merging two sorted arrays in sorted manner
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arrA[5] = {3,8,16,20,25};
    int arrB[5] = {4,10,12,22,23};
    int arrC[10];
    int n = 5, m = 5;
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if(arrA[i] < arrB[j]) //if element of array A is smaller than array B , then assign it to arr C
        arrC[k++] = arrA[i++];

        else                  //else  assign element of arr B
        arrC[k++] = arrB[j++];
    }

    
    // at last for remaining elements
    for(; i < n; i++)
    {
        arrC[k++] = arrA[i];
    }

    for(; j < m ; j++)
    {
        arrC[k++] = arrB[j];
    }


    for(i = 0; i < 10; i++)
    {
        printf("%d\t",arrC[i]);
    }
    

    return(0);
}
