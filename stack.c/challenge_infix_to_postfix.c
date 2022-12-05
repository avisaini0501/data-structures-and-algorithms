#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
    char data;
    struct node *next;
}*top = NULL;

void push(char x);
char pop();
int is_operand(char x);
int out_stack_pre(char x);
int in_stack_pre(char x);
char *convert(char *infix);

int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    char *postfix = convert(infix);
    printf("postfix form:: %s ",postfix);
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
char pop()
{
    struct node *t;
    char x = -1;
    if(top == NULL)
    printf("stack is empty\n");
    else
    {
        t = top;
        x = t->data;
        top = top->next;
        free(t);
    }    
    return(0);
}
int is_operand(char x)
{
    if(x == 'a' || x == 'b' || x == 'c' || x == 'd' || x == 'e' || x == 'f')
    return 1;
    else
    return 0;
}
int out_stack_pre(char x)
{
   if(x == '+' || x == '-')
   return 1;
   else if(x == '*' || x == '/')
   return 3;
   else if(x == '^')
   return 6;
   else if(x == '(')
   return 7;
   else if(x == ')')
   return 0;
}
int in_stack_pre(char x)
{
    if(x == '+' || x == '-')
   return 2;
   else if(x == '*' || x == '/')
   return 4;
   else if(x == '^')
   return 5;
   else if(x == '(')
   return 0;
}
char *convert(char *infix)
{
    int i = 0 , j = 0;
    int len = strlen(infix);
    char *postfix;
    postfix = (char *)malloc((len + 1) * sizeof(char));
    while (infix[i] != '\0')
    {
        if(is_operand(infix[i]))
        postfix[j++] = infix[i++];
        else
        {
            if(top == NULL || out_stack_pre(infix[i]) > in_stack_pre(top->data))
            push(infix[i++]);
            else if(out_stack_pre(infix[i]) == in_stack_pre(top->data))
            {
               pop();
               i++;
            }
            else
            {
                postfix[j++] = top->data;  
                pop();
            }
        }

    }
    while(top != NULL)
    {
        postfix[j++] = top->data;
        pop();
    }
    postfix[j] = '\0';
    return postfix;
}