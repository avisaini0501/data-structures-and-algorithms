//how to delete the element in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
void display(struct node *p);
int deletion(int pos);

int main()
{
    int result;
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(first);

    result = deletion(1);
    if(result != 0)
    printf("\n%d element is deleted\n",result);
    
    else
    printf("\n\ninvalid position\n\n");

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

    for(i = 1 ;i < n; i++)
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
    
}

int deletion(int pos)
{
    int i;
    struct node *p , *q;
    int x = 0;
    if(pos == 1)
    {
       x = first->data;
       p = first;
       first = first->next;
       free(p);
    }

    else
    {
        p = first;
        q = NULL;

        for(i = 0; i <pos-1 && p; i++)
        {
            q = p;
            p = p->next;
        }

        if(p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }

    return x;    
}
