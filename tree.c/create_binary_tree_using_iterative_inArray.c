//create binary tree using iterative procedure by array and also count the number of nodes
#include<stdio.h>
#include<stdlib.h>
struct stack
{
   int size;
   int top;
   struct node **s;
};
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
struct queue
{
    int size;
    int rear;
    int front;
    struct node **Q;
};
void create_queue(struct queue *q , int size);
void enqueue(struct queue *q , struct node *addr);
struct node * dequeue(struct queue *q);
int isEmpty(struct queue q);
void create_stack(struct stack *st , int size);
void push(struct stack *st , struct node *t);
struct node * pop(struct stack *st);
void create_tree();
void preorder(struct node *t);
void inorder(struct node *t);
void postorder(struct node *t);
void levelorder(struct node *t);
int count_nodes(struct node *p);

int main()
{
    create_tree();
    printf("levelorder:\n");
    levelorder(root);
    printf("\nnumber of nodes: \n%d\n",count_nodes(root));
    return(0);
}

void create_tree()
{
    struct node *p , *t;
    int x;
    struct queue q;
    create_queue(&q , 50);
    printf("enter the root value\n");
    scanf("%d",&x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q , root);
    while(!isEmpty(q))
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
    struct stack st;
    create_stack(&st, 50);
    while(t != NULL || st.top != -1)
    {
        if(t != NULL)
        {
           printf("%d\t",t->data);
           push(&st , t);
           t = t->lchild;
        }
        else
        {
            t = pop(&st);
            t = t->rchild;
        }
    }
} 
void inorder(struct node *t)
{
    struct stack st;
    create_stack(&st, 50);
    while(t != NULL || st.top != -1)
    {
        if(t != NULL)
        {
           push(&st , t);
           t = t->lchild;
        }
        else
        {
            t = pop(&st);
            printf("%d\t",t->data);
            t = t->rchild;
        }
    }
}
void levelorder(struct node *t)
{
    struct queue que;
    create_queue(&que , 50);
    printf("%d\t",t->data);
    enqueue(&que , t);

    while(!isEmpty(que))
    {
      t = dequeue(&que);
      if(t->lchild)
      {
          printf("%d\t",t->lchild->data);
          enqueue(&que , t->lchild);
      }
      if(t->rchild)
      {
          printf("%d\t",t->rchild->data);
          enqueue(&que , t->rchild);
      }
    }
}
int count_nodes(struct node *p)
{
    int x , y;
    if(p != NULL)
    {
        x = count_nodes(p->lchild);
        y = count_nodes(p->rchild);
        return x + y + 1;
    }
    return 0;
    
}
void create_queue(struct queue *q , int size)
{
   q->size = size;
   q->rear = q->front = 0;
   q->Q = (struct node **)malloc(q->size * sizeof(struct node *));   
}
void enqueue(struct queue *q , struct node *addr)
{
    if((q->rear + 1) % q->size == q->front)
    printf("queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = addr;
    }
}
struct node * dequeue(struct queue *q)
{
    struct node *x = NULL;
    if(q->front == q->rear)
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
void create_stack(struct stack *st , int size)
{
    st->size = size;
    st->top = -1;
    st->s = (struct node **)malloc(st->size * sizeof(struct node *));
}
void push(struct stack *st , struct node *t)
{
    if(st->top == st->size -1)
    printf("stackoverflow\n");
    else
    {
        st->top++;
        st->s[st->top] = t;
    }
}
struct node * pop(struct stack *st)
{
    struct node *x = NULL;
    if(st->top == -1)
    printf("stackunderflow\n");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
