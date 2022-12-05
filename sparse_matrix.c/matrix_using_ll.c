#include<stdio.h>
#include<stdlib.h>
struct node
{
    int col;
    int value;
    struct node *next;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct node **arr;
};
void create(struct sparse *s);
void display(struct sparse *s);
int main()
{
    struct sparse *s;
    create(s);
    display(s);
    return(0);
}
void create(struct sparse *s)
{
    int i , j;
    struct node *t , *last = NULL;
    printf("enter dimension of matrix\n");
    scanf("%d %d",&s->m , &s->n);
    s->arr = (struct node **)malloc(s->m * sizeof(struct node*));
    for(i = 0; i < s->m; i++)
    {
        s->arr[i] = NULL;
       printf("enter the number of non zero elemnts in %d row\n",i+1);
       scanf("%d",&s->num);
       for(j = 0; j < s->num; j++)
       {
           t = (struct node *)malloc(sizeof(struct node));
           printf("enter the column and corresponding element\n");
           scanf("%d %d",&t->col,&t->value);
           t->next = NULL;
           if(s->arr[i] == NULL)
           s->arr[i] = last = t;
           else
           {
           last->next = t;
           last = t;
           }       
        }
    }
    printf("\n\n");
}
void display(struct sparse *s)
{
   int i , j;
   struct node *p;
   for(i = 0; i < s->m; i++)
   {
       p = s->arr[i];
       for(j = 0; j < s->n; j++)
       {
           if(p && j == p->col)
           {
               printf("%d ",p->value);
               p = p->next;
           }
           else
           {
               printf("0 ");
           }
       }
       printf("\n");
   }
}