//implementation of queue using array
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int rear;
    int front;
    int *que;
};

void enqueue(struct queue *q , int x);
int dequeque(struct queue *q);
void display(struct queue *q);

int main()
{
   struct queue *q;
   printf("enter the size\n");
   scanf("%d",&q->size);
   q->que = (int *)malloc(q->size * sizeof(int));
   q->front = q->rear = -1;
   enqueue(q , 10);
   enqueue(q , 20);
   enqueue(q , 30);
   enqueue(q , 40);
   enqueue(q , 50);
   display(q);
   return(0);  
}
void enqueue(struct queue *q , int x)
{
    if(q->front == q->size-1)
    printf("queue is full\n");
    else
    {
        q->rear++;
        q->que[q->rear] = x;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    printf("queue is empty\n");
    else
    {
       q->front++;
       x = q->que[q->front];
    }
    return x;
}
void display(struct queue *q)
{
    int i = 0;
    while (i < q->size)
    {
        printf("%d\t",q->que[i++]);
    }
    
}
