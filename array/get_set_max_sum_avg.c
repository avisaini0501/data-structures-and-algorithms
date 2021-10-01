//program to perform vaarious function like get , set , max ,sum , avg

#include<stdio.h>
#include<stdlib.h>

int get(int);
void set(int n ,int i);
void max();
void average();

int main()
{
    int n , i;

    average();
    
    return(0);
}

int get(int n)
{
    int arr[5] = {2, 5, 10, 12, 3};
    int length = 5;
   if(n >= 0 && n < length)

   return(arr[n]);
}  

void set(int n , int i)
{
    int arr[5] = {2, 5, 10, 12, 3};
    int length = 5 , j;
    if(i >= 0 && i < length)
    arr[i] = n;

    for(j = 0; j < length; j++)
    {
        printf("%d\t",arr[j]);
    }
}

void max()
{
    int arr[5] = {2,5,15,12,3};
    int i , large = arr[0];

    for(i  = 1; i < 5; i++)
    {
        if(arr[i] > large)
        large = arr[i];
    }
printf("the largest number is %d\n",large);

}

void average()
{
    int arr[5] = {5,5,5,5,10};
    int sum = 0 , n = 5 , i;

    for(i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    printf("the average is %d\n",sum/n);



}