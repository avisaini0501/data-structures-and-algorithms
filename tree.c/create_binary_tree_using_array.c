//create binary tree using array
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};

struct node *root = NULL;

void create_queue(struct queue *q , int size);
void enqueue(struct queue *q , struct node *x);
struct node * dequeue(struct queue *q);
int isEmpty(struct queue q);
void create_tree();
void preorder(struct node *t);
void inorder(struct node *t);
void postorder(struct node *t);

int main()
{
   create_tree();
   printf("inorder:");
   inorder(root);
   return(0);    
}

void create_tree()
{
    struct node *p , *t;
    int x;
    struct queue q;
    create_queue(&q , 50);
    printf("enter root value\n");
    scanf("%d",&x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q , root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("enter left child of %d\n",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q , t);
        }
        printf("enter right child of %d\n",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q , t);
        }
    }
}
void preorder(struct node *t)
{
    if(t)
    {
        printf("%d\t",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void inorder(struct node *t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%d\t",t->data);
        inorder(t->rchild);
    }    
}
void postorder(struct node *t)
{
    if(t)
    {
      postorder(t->lchild);
      postorder(t->rchild);
      printf("%d\t",t->data);
    }
}
void create_queue(struct queue *q , int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}
void enqueue(struct queue *q , struct node *x)
{
    if((q->rear + 1) % q->size == q->front)
    printf("queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct node * dequeue(struct queue *q)
{
   struct node *x = NULL;
   if(q->rear == q->front)
   printf("queue is empty\n");
   else
   {
       q->front = (q->front + 1) % q->size;
       x = q->Q[q->front];
   }    
   return x;
}
int isEmpty(struct queue q)
{
    return (q.rear == q.front);
}