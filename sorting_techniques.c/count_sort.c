//count sort
#include<stdio.h>
#include<stdlib.h>

void count_sort(int arr[] , int n);
int find_max(int arr[] , int n);
int main()
{
    int arr[] = {6 , 3 , 9 , 10 , 15 , 6 , 8 , 12 , 3 , 6};
    count_sort(arr , 10);
    for(int i = 0; i < 10; i++)
    printf("%d\t",arr[i]);
    return 0;
}
int find_max(int arr[] , int n)
{
    int x = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > x)
        x = arr[i];
    }
    return x;
}
void count_sort(int arr[] , int n)
{
    int *c;
    int max , i , j;
    max = find_max(arr , 10);
    c = (int *)malloc((max + 1) * sizeof(int));
    for(i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }
    i = j = 0;
    while(i < max + 1)
    {
        if(c[i] > 0)
        {
            arr[j++] = i;
            c[i]--;
        }
        else
        i++;
    }
}