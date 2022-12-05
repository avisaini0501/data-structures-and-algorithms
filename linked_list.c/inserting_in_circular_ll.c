//inserting new node in circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head = NULL;

void create(int arr[] , int n);
void display(struct node *ptr);
int insert(int pos , int x , struct node *p);

int main()
{
    
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(head);

    insert(4 ,60 , head);

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

int insert(int pos , int x , struct node *p)
{
    int i;
    struct node *t ,*last;
    if(pos < 0 || pos > 5)
    return - 1;
    
    //before first node
    if(pos == 0)
    {
       t = (struct node *)malloc(sizeof(struct node));
       t->data = x;

       if(head == NULL)
       {
           head = t;
           head->next = head;
       }

       else
       {
          while(p->next != head)
          {
            p = p->next;
          }

          t->next = p->next;
          p->next = t;
          head = t;    
       }
    }
    //after first position
    else
    {
        for(i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}