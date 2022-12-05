//create linked list using insetsion
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create_by_insert(int x);
void display(struct node *p);

int main()
{
      
    create_by_insert(10);
    create_by_insert(20);
    create_by_insert(30);
    create_by_insert(40); 
    create_by_insert(50);
    
    display(first);

    return(0);
}

void create_by_insert(int x)
{
    struct node *t , *last;

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
    {
        first = last = t;   //means this is first node and all pointers should point on it
    }

    else
    {
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