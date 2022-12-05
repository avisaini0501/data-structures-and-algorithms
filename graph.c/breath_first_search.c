//breadth first search
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front = NULL , *rear = NULL;

void enqueue(int x);
int dequeue();
void BFS(int g[][8] , int n , int start);

int main()
{
   int  g[8][8] = 
 {{0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 1, 1, 1, 0, 0, 0},
 {0, 1, 0, 1, 0, 0, 0, 0},
 {0, 1, 1, 0, 1, 1, 0, 0},
 {0, 1, 0, 1, 0, 1, 0, 0},
 {0, 0, 0, 1, 1, 0, 1, 1},
 {0, 0, 0, 0, 0, 1, 0, 0},
 {0, 0, 0, 0, 0, 1, 0, 0}};
    BFS(g , 8 , 1);
    return 0;
}
void BFS(int g[][8] , int n , int start)
{
   int u;
   int visited[8] = {0};
   printf("%d",start);
   visited[start] = 1;
   enqueue(start);
   while(front != NULL)
   {
       u = dequeue();
       for(int v = 1; v <= n; v++)
       {
           if(g[u][v] == 1 && visited[v] == 0)
           {
              printf("\t%d",v);
              visited[v] = 1;
              enqueue(v);
           }
       }
   }

}
void enqueue(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL)
    printf("queue is full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct node *p;
    if(front == NULL)
    printf("queue is empty\n");
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}