//create and display doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[] , int n);
void display(struct node *p);

int main()
{
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(first);

    return(0);
}

void create(int arr[] , int n)
{
    int i;
    struct node *t , *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = first->prev = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t =(struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while (p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }

    printf("\n\n");
    
}