//create and display linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
//display using iteration
void display(struct node *p);
//display using recursion
int rec_display(struct node *ptr);

int main()
{
   int arr[] = {10, 20 , 30, 40, 50, 60};
   
   create(arr , 6);
   
   display(first);

   rec_display(first);
   
   return(0);
}

void create(int arr[] , int n)
{
    int i;
    struct node *t , *last;

    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
       t = (struct node *)malloc(sizeof(struct node));
       t->data = arr[i];
       t->next = NULL;
       last->next = t;
       last = t;
    }
}

void display(struct node *p)
{
    while(p != NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int rec_display(struct node *ptr)
{
    if(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        display(ptr->next);
    }
}