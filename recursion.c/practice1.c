#include<stdio.h>
#include<stdlib.h>

void recur(int arr[] , int i)
{
    static int a[5] = {0};
    if(i >= 5 || i < 0)
    return;

    if(a[i] == 1)
    return;

    if(arr[i] == 0)
    return;

    a[i] = 1;
    i++;
    recur(arr , i);
    recur(arr , i--);
    a[i] = 0;
}
int main()
{
    int mat1[] = {1 , 1 , 1 , 0 , 0};
    recur(mat1 , 0);
    return 0;
}