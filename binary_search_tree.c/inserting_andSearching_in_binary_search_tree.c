//inserting in binary search tree 
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
void insert(struct node *t ,int key);
void inorder(struct node *t);
struct node * search(struct node *t , int key);

int main()
{ 
    struct node *ser;
    insert(root ,10);
    insert(root ,3);
    insert(root ,20);
    insert(root ,8);
    insert(root ,30);
    inorder(root);
    ser = search(root , 1);
    if(ser == NULL)
    printf("\nkey not found\n");
    else
    printf("\nkey is present at %d node\n",ser);
    
    return 0;
}
void insert(struct node *t , int key)
{
    struct node *p , *r = NULL;
    //if root is null
    if(t == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t != NULL)
    {
        r = t;
        if(t->data == key)
        {
            printf("key is already is present\n");
        }
        else if(key < t->data)
        {
            t = t->lchild;
        }
        else
        t = t->rchild;
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(p->data < r->data)
    r->lchild = p;
    else
    r->rchild = p;
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
struct node * search(struct node *t , int key)
{
    while(t != NULL)
    {
        if(key == t->data)
        return t;
        else if(key < t->data)
        {
            t = t->lchild;
        }
        else
        t = t->rchild;
    }
    return NULL;
}