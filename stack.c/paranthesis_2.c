//more in paranthesis matching
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *next;
}*top = NULL;

void push(char x);
int pop();
int is_balance(char *exp);

int main()
{
    int result;
    char *exp = "{([a + b] * [c - d])/e}";    
    result =  is_balance(exp);
    printf("%d\n",result);
    if(result < 1)
    printf("not balance\n");
    else
    printf("balance\n");
    return(0);
}
int is_balance(char *exp)
{
    int i;
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        push(exp[i]);
        else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
          if(top == NULL)
          return -1;
          pop();
        }
    }
    return (top == NULL)? 1 : 0;
}
void push(char x)
{
   struct node *t;
   t = (struct node *)malloc(sizeof(struct node));
   if(t == NULL)
   printf("stack over flow\n");
   else
   {
       t->data = x;
       t->next = top;
       top = t;
   }
}
int pop()
{
    int x;
    struct node *t;
    if(top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
       t = top;
       top = top->next;
       x = t->data;
       free(t);
    }
    return(x);
}