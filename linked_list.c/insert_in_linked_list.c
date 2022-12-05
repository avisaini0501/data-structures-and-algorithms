//how to insert new node or element in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
void display(struct node *p);
void insert(int pos , int x);

int main()
{
    int arr[] = {1 , 3 , 5 , 10 , 4};

    create(arr , 5);

    display(first);

    insert(4 , 15);

    display(first);

    return(0);
}

void create(int arr[] , int n)
{
   struct node *t , *last;
   int i;
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
    while (p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }

    printf("\n\n");
    
}

void insert(int pos , int x)
{
    int i;
    struct node *t , *p;
    if(pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = first;
        first = t;
    }

    else if(pos > 0)
    {
        p = first;

        for(i = 0; i < pos-1 && p; i++)
        {
            p = p->next;
        }

        if(p)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

