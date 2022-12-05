//insert node in doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *pev;
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[] , int n);
void display(struct node *ptr);
int insert(struct node *p , int pos , int x);

int main()
{
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(first);

    insert(first , 5 , 60);

    display(first);

    return(0);
}

void create(int arr[] , int n)
{
    int i;
    struct node *t , *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = first->pev = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
       t = (struct node *)malloc(sizeof(struct node));
       t->data = arr[i];
       t->next = last->next;
       t->pev = last;
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

int insert(struct node *p , int pos , int x)
{
    struct node *t;
    int i;
    
    if(pos < 0 || pos > 5)
    return -1;

    if(pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->pev = NULL;
        t->next = first;
        first->pev = t;
        first = t;
    }
    else
    {
        for(i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->pev = p;
        t->next = p->next;
        if(p->next)
        {
           p->next->pev = t;
        }

        p->next = t;
    }
}