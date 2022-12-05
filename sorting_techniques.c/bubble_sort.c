//bubble sort
#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int arr[] , int n);

int main()
{
    int arr[] = {11,13,7,12,16,9,24,5,10,3};
    bubble_sort(arr , 10);
    for(int i = 0;  i < 10; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
void bubble_sort(int arr[] , int n)
{
    int flag , temp;
    for(int i = 0; i < n - 1; i++)
    {
        flag = 0; //flag is used to made it adaptive
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;  //if swaping is done flag become 1
            }
        }
        if(flag == 0) // if flag is still 0 , means array is already sorted
        break;
    }
}