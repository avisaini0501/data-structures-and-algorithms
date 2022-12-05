//delete element from circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head = NULL;

void create(int arr[] , int n);
void display(struct node *ptr);
int delete(int pos , struct node *p);

int main()
{
    int result = 0;

    int arr[] = {10 , 20 , 30 , 40 , 50 , 60};

    create(arr , 6);

    display(head);
    
   result = delete(5 , head);
   if(result < 0)
   {
       printf("\n\ninvalid move\n\n");
   }
   
   printf("after deletion\n");

   display(head);

    return(0);
}

void create(int arr[] , int n)
{
    int i;
    struct node *t , *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = arr[0];
    head->next = head;
    last = head;

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
    do
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
    printf("\n\n");
}

int delete(int pos , struct node *p)
{
    int i;
    int x = 0;
    struct node *q;
    if(pos < 0 || pos > 6)  //for invalid move
    return - 1;

    if(pos == 1)  //for first position
    {
       while (p->next != head)
       {
           p = p->next;
       }
       x = head->data;
       
       if(p == head)  //if linked list have only singe node
       {
          free(p);
          head = NULL;
       }
       
       else
       {
           p->next = head->next;
           free(head);
           head = p->next;
       }

    }

    else      //after first position
    {
       for(i = 0; i < pos - 2; i++)
       {
           p = p->next;
       }

       q = p->next;
       x = q->data;
       p->next = q->next;
       free(q);
    }

    return x;
}