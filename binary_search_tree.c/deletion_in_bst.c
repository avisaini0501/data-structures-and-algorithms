//delete node in binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
struct node * insert(struct node *t , int key);
void inorder(struct node *t);
struct node *delete(struct node *t , int key);
int height(struct node *p);
struct node * Inpre(struct node *p);
struct node * Insucc(struct node *p);

int main()
{
   root = insert(root , 30);
   insert(root , 20);
   insert(root , 40);
   insert(root , 10);
   insert(root , 25);
   insert(root , 35);
   insert(root , 45);
   insert(root , 42);
   insert(root , 43);
   inorder(root);
   delete(root , 43);
   printf("\nafter deletion of node\n");
   inorder(root);
   return 0;
}
struct node * insert(struct node *t , int key)
{
    struct node *p;
    if(t == NULL)
    {
       p = (struct node *)malloc(sizeof(struct node));
       p->data = key;
       p->lchild = p->rchild = NULL;
       return p;
    }
    else if(key < t->data)
    t->lchild = insert(t->lchild , key);
    else
    t->rchild = insert(t->rchild , key);
}
struct node * delete(struct node *t , int key)
{
   struct node *q = NULL;
   if(t == NULL)
   return NULL;

   if(t->lchild == NULL && t->rchild == NULL)
   {
       if(t == root)
       root = NULL;

       free(t);
       return NULL;
   }
  if(key < t->data)
   {
       t->lchild = delete(t->lchild , key);
   }
   else if(key > t->data)
   {
       t->rchild = delete(t->rchild , key);
   }
   else{
       
       if(height(t->lchild) > height(t->rchild)){
           q = Inpre(t->lchild);
           t->data = q->data;
           t->lchild = delete(t->lchild , q->data);
       }
       else{
           q = Insucc(t->rchild);
           t->data = q->data;
           t->rchild = delete(t->rchild , q->data);
       }
   }
   return t;
}

int height(struct node *p)
{
    int x , y;
    if(p == NULL)
    return 0;

    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x+1 : y+1;
}
struct node * Inpre(struct node *p)
{
    while(p && p->rchild)
    {
        p = p->rchild;
    }
    return p;
}
struct node * Insucc(struct node *p)
{
    while(p && p->lchild)
    {
        p = p->lchild;
    }
    return p;
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