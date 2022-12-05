//merging of sorted linked list in a sorted way
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first = NULL , *second = NULL , *third = NULL;

void create1(int arr1[] , int n);
void create2(int arr2[] , int n);
void display(struct node *ptr);
void merge(struct node *p , struct node *q);

int main()
{
    int arr1[] = {10 ,20 , 30 , 40 , 50};
    int arr2[] ={60 , 70 , 80 , 90 , 100};

    create1(arr1 , 5);
    create2(arr2 , 5);

    display(first);
    display(second);

    merge(first , second);

    display(third);
    
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

void merge(struct node *p , struct node *q)
{
    struct node *last;

    if(p->data < q->data)
    {
      third = last = p;
      p = p->next;
      third->next = NULL;
    }

    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }

        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p)
    {
        last->next = p;
    }

    else
    {
        last->next = q;   
    }
    
}