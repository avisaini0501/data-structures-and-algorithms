//basic operations of stack like , push , pop , peek , stacktop
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};
void push(struct stack *st , int x);
int pop(struct stack *st);
int peek(struct stack *st , int pos);
int stackTop(struct stack *st);
void display(struct stack *st);
int main()
{
    struct stack st;
    printf("enter the size of stack\n");
    scanf("%d",&st.size);
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));
    push(&st , 10);
    push(&st , 20);
    push(&st , 30);
    push(&st , 40);
    push(&st , 50);
    push(&st , 60);
    display(&st);
    pop(&st);
    display(&st);
    peek(&st , 6);
    stackTop(&st);
    return(0);
}
void display(struct stack *st)
{
    int i;
    for(i = st->top; i >= 0; i--)
    {
        printf("%d ",st->s[i]);
    }
    printf("\n");
}
void push(struct stack *st , int x)
{
    if(st->top == st->size - 1)
    printf("stack over flow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct stack *st)
{
   int x = -1;
   if(st->top == -1)
   printf("stack under flow\n");

   else
   {
       x = st->s[st->top];
       st->top--;
   }
   return x;
}
int peek(struct stack *st , int pos)
{
    int x;
    if(st->top - pos + 1 < 0)
    printf("invalid position\n");
    else
    x = st->s[st->top - pos + 1];
    return(0);
}
int stackTop(struct stack *st)
{
    if(st->top == -1)
    {
       printf("stack is empty\n");
       return -1;
    }
    else
    {
       printf("%d\n",st->s[st->top]);
       return st->s[st->top];
    }
}