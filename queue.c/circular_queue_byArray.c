//circular queue using array
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *que;
};

void enqueue(struct queue *q , int x);
int dequeue(struct queue *q);
void display(struct queue *q);

int main()
{
    struct queue *q;
    printf("enter the size of queue\n");
    scanf("%d",&q->size);
    q->que = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;
    enqueue(q , 10);
    enqueue(q , 20);
    enqueue(q , 30);
    enqueue(q , 40);
    display(q);
    dequeue(q);
    display(q);
    return (0);
}
void enqueue(struct queue *q , int x)
{
    if((q->rear + 1) % q->size == q->front)
    printf("queue is full\n");
    else
    {
       q->rear = (q->rear + 1) % q->size;
       q->que[q->rear] = x;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if(q->rear == q->front)
    printf("queue is full\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->que[q->front];
    }
    return(x);
}
void display(struct queue *q)
{ 
    int i = q->front + 1;
   do
   {
       printf("%d\t",q->que[i]);
       i = (i + 1) % q->size;
   } while (i != (q->rear + 1) % q->size);
   printf("\n");
}