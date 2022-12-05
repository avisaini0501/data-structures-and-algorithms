//creating binary search tree from preorder traversal
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
struct stack
{
    int size;
    int top;
    struct node **st;
};
void create_BST(int pre[] , int n);
void inorder(struct node *t);
void push(struct stack *stk , struct node *q);
struct node * pop(struct stack *stk);
void preorder(struct node *t);
int main()
{
   int pre[] = {30, 20 , 10 , 15 , 25 , 40 , 50 , 45};
   int n = sizeof(pre) / sizeof(pre[0]);
   create_BST(pre , n);
   inorder(root);
   return 0;
}
void create_BST(int *pre , int n)
{
    struct node *p  , *t;
    struct stack s;
    s.size = n;
    s.top = -1;
    s.st = (struct node **)malloc(s.size * sizeof(struct node *));    
    int i = 0;
   //create root node
      root = (struct node *)malloc(sizeof(struct node));
      root->data = pre[i++];
      root->lchild = root->rchild = NULL;
      p = root;
   while(i < n)
   {
       //create left child
       if(pre[i] < p->data)
       {
           t = (struct node *)malloc(sizeof(struct node));
           t->data = pre[i++];
           t->lchild = t->rchild = NULL;
           p->lchild = t;
           push(&s , p);
           p = t;
       }
       else
       {
    if(s.top > -1)
    {
        if(pre[i] > p->data && pre[i] < s.st[s.top]->data)
       {
           t = (struct node *)malloc(sizeof(struct node));
           t->data = pre[i++];
           t->lchild = t->rchild = NULL;
           p->rchild = t;
           p = t;
       }
    
        else
        p = pop(&s);
    }
    if(s.top < 0)    
    {
        if(pre[i] > p->data && pre[i] < 32767)
       {
           t = (struct node *)malloc(sizeof(struct node));
           t->data = pre[i++];
           t->lchild = t->rchild = NULL;
           p->rchild = t;
           p = t;
       }
    
        else
        p = pop(&s);
    }
   }
}
}
void push(struct stack *stk , struct node *q)
{
   if(stk->top == stk->size - 1)
   printf("stackoverflow\n");
   else
   {
       stk->top++;
       stk->st[stk->top] = q;
   }
}
struct node * pop(struct stack *stk)
{
    struct node *q = NULL;
    if(stk->top == -1)
    printf("StackUnderFlow\n");
    else
    {
       q = stk->st[stk->top];
       stk->top--;
    }
    return q;
}
void inorder(struct node *t)
{
    if(t != NULL)
    {
        inorder(t->lchild);
        printf("%d\t",t->data);
        inorder(t->rchild);
    }
}
void preorder(struct node *t)
{
    printf("%d\t",t->data);
    preorder(t->lchild);
    preorder(t->rchild);
}
