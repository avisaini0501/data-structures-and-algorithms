//convert infix to postfix using stack
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
struct stack
{
    char data;
    struct stack *next;
}*top = NULL;

void push(char x);
char pop();
int is_operand(char x);
int pre(char x);
char * in_to_post(char *infix);

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = in_to_post(infix);
    printf("%s ",postfix);
    return (0);
}

void push(char x)
{
    struct stack *t;
    t = (struct stack *)malloc(sizeof(struct stack));
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
    struct stack *t;
    char x = -1;
    if(top == NULL)
    printf("stack is empty\n");
    else
    {
       t = top;
       top = top->next;
       x = t->data;
       free(t);  
    }
    return x;
}
int is_operand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
    else
    return 1;
}
int pre(char x)
{
    if(x == '+' || x == '-')
    return 1;
    else if(x == '*' || x == '/')
    return 2;
    return 0;
}
char * in_to_post(char *infix)
{
    int i = 0 , j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2)* sizeof(char));
    while (infix[i] != '\0')
    {
        if(is_operand(infix[i]))
        postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(top->data))
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