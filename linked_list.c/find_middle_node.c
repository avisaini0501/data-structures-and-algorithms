//find middle node in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[] , int n);
void display(struct node *ptr);
void middle(struct node *p);

int main()
{
    int arr[] = {10 , 20 , 30 , 40 , 50 , 60 , 70};

    create(arr , 7);

    display(first);

    middle(first);

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

void middle(struct node *p)
{
    struct node *q;
    q = p = first;
    while (q)
    {
        q = q->next;
        if(q)
        {
            q = q->next;
        }

        if(q)
        {
            p = p->next; 
        }
    }

    printf("%d present at middle node\n",p->data);
    
}