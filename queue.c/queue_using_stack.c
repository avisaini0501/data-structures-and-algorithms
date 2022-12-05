//implementation of queue using stack
#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int top;
    int *stack;
}s1  , s2;

void push(int x);
int pop();
void enqueue(int x);
int dequeue();
void display();
int main()
{
    printf("enter the size\n");
    scanf("%d",&s1.size);
    s1.top = -1;
    s2.top = -1;
    s1.stack = (int *)malloc(s1.size * sizeof(int));
    s2.stack = (int *)malloc(s1.size * sizeof(int));

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    display();
    return(0);
}
void push(int x)
{
    if(s1.top == s1.size - 1)
    printf("queue is full\n");
    else
    {
        s1.top++;
        s1.stack[s1.top] = x; 
    }
}
int pop()
{
    int x = -1;
    if(s2.top == s1.size - 1)
    printf("recycle bin is full\n");
    else
    {
        while(s1.top != -1)
        {
          s2.top++;
          s2.stack[s2.top] = s1.stack[s1.top];
          s1.top--;
        }

        x = s2.stack[s2.top];
        s2.top--;
    }
    return(x);
}
void enqueue(int x)
{
    push(x);
}
int dequeue()
{
        if(s1.top == -1)
        printf("queue is empty\n");
        else
        {
            pop();        
        }
    
}
void display()
{
    int i = 0;
    while (i != s2.top + 1)
    {
        printf("%d\t",s2.stack[i++]);
    }
    
}