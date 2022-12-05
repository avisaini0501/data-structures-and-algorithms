//concatenation of linked list(add second linked list at the end of first)
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*first = NULL , *second = NULL;

void create1(int arr1[] , int n);
void create2(int arr2[] , int n);
void display(struct node *ptr);
void concat(struct node *p , struct node *q);

int main()
{
    int arr1[] = {10 ,20 , 30 , 40 , 50};
    int arr2[] ={60 , 70 , 80 , 90 , 100};

    create1(arr1 , 5);
    create2(arr2 , 5);

    display(first);
    display(second);

    concat(first , second);

    display(first);
    
    return(0);
    
}

void create1(int arr1[] , int n)
{
    int i;
    struct node *t , *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr1[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr1[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int arr2[] , int n)
{
    int i;
    struct node *t , *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = arr2[0];
    second->next = NULL;
    last = second;

    for(i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr2[i];
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

void concat(struct node *p , struct node *q)
{
    while (p->next)
    {
        p = p->next;
    }

    p->next = q;
    second = NULL;
    
}