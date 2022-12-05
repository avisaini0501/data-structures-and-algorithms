//to find the largest element in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] ,  int n);
void display(struct node *p);
void max_ele(struct node *ptr);
//using recursion
int rec_max(struct node *r);

int main()
{
    int result = 0;
    int arr[] = {1 , 2 , 3 , 4 , 5};

    create(arr , 5);

    display(first);

    max_ele(first);

    result  = rec_max(first);
    printf("\n\n%d is largest(using recursion)",result);

    return(0);
}

void create(int arr[] ,  int n)
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

void max_ele(struct node *ptr)
{
    int large = -32768;
    
    while(ptr != NULL)
    {
        if(ptr->data > large)
        {
        large = ptr->data;
        }
        
        ptr = ptr->next;
        
    }

    printf("\n%d is the largest element in linked list",large);
}

int rec_max(struct node *r)
{
    int x = 0;
    if(r == NULL)
    return 0;
    
    x = rec_max(r->next);

    return (x > r->data ? x : r->data);


}