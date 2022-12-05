//reverse the doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[] , int n);
void display(struct node *ptr);
void revers_ll(struct node *p);

int main()
{
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(first);

    revers_ll(first);

    display(first);

    return(0);
}

void create(int arr[] , int n)
{
    struct node *t , *last;
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = first->prev = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;        
    }
}

void display(struct node *ptr)
{
    while (ptr)
    {
       printf("%d\t",ptr->data);
       ptr = ptr->next;
    }

    printf("\n\n");
}

void revers_ll(struct node *p)
{
    struct node *temp = NULL;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if(p != NULL && p->next == NULL)
        first = p;
    }
    
}