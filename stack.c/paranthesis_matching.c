//checking of brackets , are balance or not
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
int is_balance(char *exp);

int main()
{
    int result;
    char *exp = "((a + b) * (c - d))";
    result = is_balance(exp);
    if(result == 1)
    printf("balanced\n");
    else
    printf("not balanced\n");
    return(0);
}
int is_balance(char *exp)
{
    int i;
    //initialize stack
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        push(exp[i]);
        else if(exp[i] == ')')
        {
            if(top == NULL)
            return -1;
            pop();
        }
    }
return((top == NULL)? 1 : 0);
}
void push(char x)
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
char pop()
{
    char x = -1;
    struct node *t;
    if(top == NULL)
    printf("stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return(x);
}
