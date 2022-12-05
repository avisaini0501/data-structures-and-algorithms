//count leaf ,non leaf and each type nodes
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
struct queue
{
    int rear;
    int front;
    int size;
    struct node **Q;
};
struct stack
{
    int top;
    int size;
    struct node **s;
};
void create_queue(struct queue *q , int size);
void enqueue(struct queue *q , struct node *address_of_element);
struct node * dequeue(struct queue *q);
int isEmpty(struct queue q);
void create_stack(struct stack *st , int size);
void push(struct stack *st , struct node *t);
struct node * pop(struct stack *st);
void create_tree();
void Ipreorder(struct node *t);
void Iinorder(struct node *t);
void Ilevelorder(struct node *t);
int count_leaf_nodes(struct node *p);
int count_nonLeaf_nodes(struct node *p);

int main()
{
    create_tree();
    printf("level order of tree\n");
    Ilevelorder(root);
    printf("\nnumber of leaf nodes\n%d\n",count_leaf_nodes(root));
    printf("number of non leaf nodes %d\n",count_nonLeaf_nodes(root));
    return 0;
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
void Ipreorder(struct node *t)
{
    struct stack st;
    create_stack(&st , 50);
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
void Iinorder(struct node *t)
{
    struct stack st;
    create_stack(&st , 50);
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
void Ilevelorder(struct node *t)
{
    struct queue q;
    create_queue(&q , 50);
    printf("%d\t",t->data);
    enqueue(&q , t);
    while(!isEmpty(q))
    {
        t = dequeue(&q);
        if(t->lchild)
        {
            printf("%d\t",t->lchild->data);
            enqueue(&q , t->lchild);
        }
        if(t->rchild)
        {
            printf("%d\t",t->rchild->data);
            enqueue(&q , t->rchild);
        }
    }
}
int count_leaf_nodes(struct node *p)
{
    int x , y;
    if(p != NULL)
    {
        x = count_leaf_nodes(p->lchild);
        y = count_leaf_nodes(p->rchild);
        if(p->lchild == NULL && p->rchild == NULL)
        return x + y + 1;
        else
        return x + y;
    }
    return 0;
}
int count_nonLeaf_nodes(struct node *p)
{
    int x , y;
    if(p != NULL)
    {
        x = count_nonLeaf_nodes(p->lchild);
        y = count_nonLeaf_nodes(p->rchild);
        if(p->lchild || p->rchild)
        return x + y + 1;
        else
        return x + y;
    }
}
void create_queue(struct queue *q , int size)
{
   q->size = size;
   q->front = q->rear = 0;
   q->Q = (struct node **)malloc(q->size * sizeof(struct node *));   
}
void enqueue(struct queue *q , struct node *address_of_element)
{
    if((q->rear + 1) % q->size == q->front)
    printf("queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = address_of_element;
    }
}
struct node * dequeue(struct queue *q)
{
    struct node *x = NULL;
    if(q->rear == q->front)
    printf("queue is full\n");
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
    if(st->top == st->size - 1)
    printf("stack over flow\n");
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
    printf("stack is empty\n");
    else
    {
       x = st->s[st->top];
       st->top--;
    }
    return x;
}
