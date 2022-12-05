//basic operation of stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top = NULL;
void push(int x);
int pop();
int peek(int pos);
int stack_top();
void display();
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    peek(2);
    display();
    return(0);
}
void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL)
    printf("StackOverFlow\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop()
{
   struct node *p;
   int x = -1;
   if(top == NULL)
   printf("stack is empty\n");
   else
   {
       p = top;
       top = top->next;
       x = p->data;
       free(p);
    }
    return x;
}
int peek(int pos)
{
    struct node *p;
    int i;
    p = top;
    for(i = 0; p != NULL && i < pos - 1; i++)
    {
       p = p->next;
    }
    if(p != NULL)
    return p->data;
    else
    return -1;
}
int stack_top()
{
    if(top)
    return top->data;
    else
    return -1;
}
void display()
{
    struct node *p;
    p = top;
    while (p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}