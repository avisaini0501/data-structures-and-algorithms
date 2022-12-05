//insert and search recursively
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
struct node * insert(struct node *t , int key);
struct node * search(struct node *t , int key);
void inorder(struct node *t);

int main()
{
    struct node *ser;
    root = insert(root , 25);
    insert(root , 20);
    insert(root , 10);
    insert(root , 40);
    insert(root , 35);
    insert(root , 45);
    insert(root , 42);
    insert(root , 43);
    inorder(root);
    ser = search(root , 10);
    if(ser != NULL)
    printf("\nkey is found\n");    
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
    t->lchild =  insert(t->lchild , key);
    else
    t->rchild = insert(t->rchild , key);

    return t;

}
struct node * search(struct node *t , int key)
{
    if(t == NULL)
    {
      printf("\nkey is not found\n");
      return NULL;
    }
    else if(key == t->data)
    {
        return t;
    }
    else if(key < t->data)
    {
       return search(t->lchild , key);
    }
    else
    {
      return search(t->rchild , key);
    }  
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