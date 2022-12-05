//count the number of nodes in linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] , int n);
void display(struct node *p);
//count node using loop
void count(struct node *ptr);
//count node using recursion
int  rec_count(struct node *r);

int main()
{
    int result = 0;
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(first);

    count(first);

    result = rec_count(first);
    printf("\n\n%d nodes are present",result);
    
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

void count(struct node *ptr)
{
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }

    printf("\n\n%d node are present in linked list",c);    
}

int rec_count(struct node *r)
{
   if(r == NULL)
   return 0;

   else
   return rec_count(r->next) + 1;

}
