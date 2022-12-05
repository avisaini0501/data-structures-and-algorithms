//chaining technique
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void sorted_insert(struct node **ht , int key);
void insert(struct node *ht[] , int key);
struct node * search(struct node *p , int key);
int main()
{
    int key;
    struct node *result;
    struct node *h[10];
    for(int i = 0; i < 10; i++)
    h[i] = NULL;
    insert(h , 12);
    insert(h , 22);
    insert(h , 42);

   printf("enter the key you have to find\n");
   scanf("%d",&key);
   int index = key % 10;    
   result = search(h[index] , key);
   printf("\nkey is found = %d",result->data);

}
void insert(struct node *ht[] , int key)
{
    int index = key % 10;
    sorted_insert(&ht[index] , key);
}
void sorted_insert(struct node **ht , int key)
{
    struct node *t , *q , *p;
    p = *ht;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->next = NULL;
    if(ht == NULL)
    *ht = t;
    else
    {
        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if(p == *ht)
        {
           t->next = *ht;
           *ht = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
    
}
struct node * search(struct node *p , int key)
{
    while(p != NULL)
    {
        if(key == p->data)
        return p;
        p = p->next;
    }
    
    return NULL;
}
