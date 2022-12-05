//to check the linked is sorted or not
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
void display(struct node *p);
int isSORT(struct node *ptr);

int main()
{
    int sort;
    int arr[] = {10, 25 ,30 ,34 ,40};

    create(arr , 5);
    display(first);
    sort = isSORT(first);
    if(sort > 0)
    printf("\n\nlist is sortes\n");

    else
    printf("\n\nnot sorted\n");

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
    
}

int isSORT(struct node *ptr)
{
    int x = 0;
    while (ptr)
    {
        if(ptr->data < x)
        return -1;
          
        x = ptr->data;
        ptr = ptr->next; 
    }
    
    return 1;
}