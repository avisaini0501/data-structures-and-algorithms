//to remove duplicate from list from sorted list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;
void create(int arr[] , int n);
void display(struct node *p);
void rem_dup(struct node *ptr);

int main()
{
    int arr[] = {10 , 20 , 20 , 40 , 40 ,50 , 60 , 60};
    create(arr , 8);

    display(first);

    rem_dup(first);

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
void display(struct node *p)
{
    while (p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }

    printf("\n\n");
    
}

void rem_dup(struct node *ptr)
{
    struct node *q;
    
    q = ptr->next;

    while (q)
    {
        if(ptr->data != q->data)
        {
            ptr = q;
            q = q->next;
        }

        else
        {
            ptr->next = q->next;
            free(q);
            q = ptr->next;
        }
    }
    
}