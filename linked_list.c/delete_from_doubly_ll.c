//delete element from doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
}*first = NULL;

void create(int arr[] , int n);
void display(struct node *ptr);
int delete(struct node *p , int pos);

int main()
{
    int result = 0;
    int arr[] = {10 , 20 ,30 , 40 , 50 , 60};

    create(arr , 6);

    display(first);

   result = delete(first , 5);
   if(result < 1)
   {
     printf("\n\ninvalid position\n");
   }
    display(first);

    return(0);
}

void create(int arr[] , int n)
{
    struct node *t , *last;
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = first->pre = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->pre =  last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *ptr)
{

   while (ptr)
   {
       printf("%d\t",ptr->data);
       ptr = ptr->next;
   }

   printf("\n\n");
}

int delete(struct node *p , int pos)
{
   int x = -1 , i;

   if(pos < 1 || pos > 6)
   return -1;

   if(pos == 1)
   {
       first = first->next;
       if(first)
       {
           first->pre = NULL;
       }
       x = p->data;
       free(p);
   }

   else
   {
       for(i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        x = p->data;
        p->pre->next = p->next;
        if(p->next)
        {
            p->next->pre = p->pre;
        }

        free(p);
   }
   return x;
   
}


