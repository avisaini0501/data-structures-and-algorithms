//searching an element in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;

void create(int arr[] ,  int n);
void display(struct node *p);
struct node * searching(struct node *ptr , int key);

int main()
{

    struct node *temp;
    
    int arr[] = {1 , 2 , 3 , 4 , 5};
    
    create(arr , 5);

    display(first);

    temp = searching(first , 6);
    
    if(temp)
    {
       printf("\n\nkey is found");  
       printf("\n\nkey is present at %d address",temp);
    }

    else
    printf("\nkey is no found");

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
    while(p != NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
}

struct node * searching(struct node *ptr , int key)
{
    while (ptr != NULL)
    {
        if(key == ptr->data)
        return ptr;

        ptr = ptr->next;
    }
    return(0);
    
}
