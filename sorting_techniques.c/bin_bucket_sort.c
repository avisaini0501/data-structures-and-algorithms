//bin/bucket sort
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void bin_sort(int arr[] , int n);
int find_max(int arr[] , int n);
void insert(struct node **bin , int index);
int delete(struct node **bin , int index);
int main()
{
   int arr[] = {6 , 8 , 3 , 10 , 15 , 6 , 9 , 12 , 6 , 3};
   bin_sort(arr , 10);
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
void bin_sort(int arr[] , int n)
{
    int max , i , j;
    struct node **bin;
    max = find_max(arr , n);
    bin = (struct node **)malloc((max + 1) * sizeof(struct node *));
    for(i = 0; i < max + 1; i++)
    bin[i] = NULL;
    for(i = 0; i < n; i++)
    {
        insert(bin , arr[i]);
    }
    i = 0 , j = 0;
    while(i < max + 1)
    {
        while(bin[i] != NULL)
        {
            arr[j++] = delete(bin , i);
        }
        i++;
    }
}
void insert(struct node **bin , int index)
{
    struct node *t , *p;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = index;
    t->next = NULL;
    if(bin[index] == NULL)
    {
       bin[index] = t;
    }
    else
    {
        p = bin[index];
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}
int delete(struct node **bin , int index)
{
    struct node *p = bin[index];
    bin[index] = bin[index]->next;
    int x = p->data;
    free(p);
    return x;
}