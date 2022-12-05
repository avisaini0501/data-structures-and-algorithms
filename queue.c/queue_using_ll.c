//queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *next;
}*front = NULL , *rear = NULL;

void enqueue(int x);
int dequeue();
void display();

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    return(0);
}
void enqueue(int x)
{
   struct queue *q;
   q = (struct queue *)malloc(sizeof(struct queue));
   if(q == NULL)
   printf("queue is full\n");
   else
   {
       q->data = x;
       q->next = NULL;
       if(front == NULL)
       {
           front = rear = q;
       }
       else
       {
           rear->next = q;
           rear = q;
       }
   }
}
int dequeue()
{
    int x = -1;
    struct queue *t;
    if(front == NULL)
    printf("queue is empty\n");
    else
    {
        t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}
void display()
{
    struct queue *q;
    q = front;
    while (q != NULL)
    {
        printf("%d\t",q->data);
        q = q->next;
    }
    printf("\n");
}