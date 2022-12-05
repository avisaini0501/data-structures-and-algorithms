//create and display circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create(int arr[] , int n);
void display(struct node *p);

int main()
{
    int arr[] = {10 , 20 , 30 , 40 , 50};

    create(arr , 5);

    display(head);

    return(0);
}

void create(int arr[] , int n)
{
    int i;
    struct node *t  ,*last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = arr[0];
    head->next = head;
    last = head;

    for(i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t; 
    }
}

void display(struct node *p)
{
    do
    {
        printf("%d\t",p->data);
        p = p->next;
    } while (p != head);
    
}