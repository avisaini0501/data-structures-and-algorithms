//deapth first search
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front = NULL , *rear = NULL;
void DFS(int G[][8] , int vertex , int num);

int main()
{
    int G[8][8] = 
    {{0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0}};
    DFS(G , 1 , 8);
    return 0;
}
void DFS(int G[][8] , int vertex , int num)
{
    static int visited[8] = {0};
    if(visited[vertex] == 0)
    {
        printf("%d\t",vertex);
        visited[vertex] = 1;
        for(int u = 1; u <= num; u++)
        {
            if(G[vertex][u] == 1 && visited[u] == 0)
            DFS(G , u , num);
        }
    }
}