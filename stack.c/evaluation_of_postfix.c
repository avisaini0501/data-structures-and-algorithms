//evaluation of equation in postfix form
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*top = NULL;

void push(char x);
int pop();
int is_operand(char x);
int pre(char x);
char *in_to_post(char *infix);
int evaluate(char *postfix);

int main()
{
  int result;
  char *infix = "3*5+6/2-4";
  char *postfix = in_to_post(infix);
  result = evaluate(postfix);
  printf("result is %d\n",result);
  return(0);
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
    char x = -1;
   struct node *t;
   if(top == NULL)
   printf("stack is empty\n");
   else
   {
       t = top;
       x = top->data;
       top = top->next;
       free(t);
   }  
   return x;
}
int is_operand(char x)
{
   if(x=='+' || x=='-' || x=='*' || x=='/')
   return 0;
   else
   return 1;
}
int pre(char x)
{
  if(x == '*' || x == '/')
  return 2;
  else if(x == '+' || x == '-')
  return 1;
  
  return 0;
}
char *in_to_post(char *infix)
{
    int i = 0 , j = 0;
    char *postfix;
    int len;
    len = strlen(infix);
    postfix = (char *)malloc((len + 2)*sizeof(char));
    while (infix[i] != '\0')
    {
        if(is_operand(infix[i]))
        postfix[j++] = infix[i++];
        else
        {
            if(top == NULL || pre(infix[i]) > pre(top->data))
            push(infix[i++]);
            else
            postfix[j++] = pop();
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;   
}
int evaluate(char *postfix)
{
    int r = 0 , x1 , x2;
    int i = 0;
    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(is_operand(postfix[i]))
        push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '/': r = x1 / x2; break;
                case '*': r = x1 * x2; break;
            }
            push(r);
        }
    }
    return top->data;
}