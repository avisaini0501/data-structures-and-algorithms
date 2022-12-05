//sum of all elements in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
void display(struct node *p);
void sum(struct node *s);
//sum of linked list using recursion
int rec_add(struct node *r);

int main()
{
    int result;

    int arr[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    create(arr , 10);

    display(first);

    sum(first);

    result = rec_add(first);

    printf("\n%d sum by recursion",result);

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
    while (p != NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    
}

void sum(struct node *s)
{
    int total = 0;
    while(s != NULL)
    {
        total = total + s->data;
        s = s->next; 
    }
    printf("\n\n%d is the sum of linked list",total);

}

int rec_add(struct node *r)
{
    if(r == NULL)
    return (0);

    else
    return rec_add(r->next) + r->data;
}