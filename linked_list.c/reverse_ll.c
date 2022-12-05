//reverse linked list by reversing the links
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*first = NULL;
void create(int arr[] , int n);
void display(struct node *ptr);
void reverse(struct node *p);

int main()
{
    int arr[] = {10 , 20 , 30  , 40 , 50};

    create(arr , 5);

    display(first);

    reverse(first);

    display(first);

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
void display(struct node *ptr)
{
    while (ptr)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }

    printf("\n\n");
    
}

void reverse(struct node *p)
{
    struct node *r , *q;

    r = NULL;
    q = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    
    first = q;
    
}

