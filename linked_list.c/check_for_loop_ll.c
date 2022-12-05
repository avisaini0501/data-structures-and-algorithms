//check linked list don't make loop
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
int isLoop(struct node *p);

int main()
{
    int result = 0;
    struct node *t1 , *t2;
    int arr[] = {10 , 20 , 30 , 40 , 50};
    create(arr , 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    result = isLoop(first);
    if(result < 1)
    printf("loop  is present\n");

    else
    printf("loop is not present\n");

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

int isLoop(struct node *p)
{
    struct node *q;
    p = q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL? q->next : NULL;
    } while (p && q && p != q);

    if(p == q)
    return -1;

    else
    return 1;
    
}