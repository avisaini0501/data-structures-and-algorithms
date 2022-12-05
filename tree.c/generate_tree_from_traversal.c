//generate tree from traversal using inorder and preorder
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;
int search_in_inorder(int arr[] , int start , int end , int value);
struct node * newNode(int data);
struct node * buildTree(int in[] , int pre[] , int start , int end);
void printInorder(struct node *node);

int main()
{
    int pre[] = {4 , 7 , 9 , 6 , 3 , 2 , 5 , 8 , 1};
    int in[] =  {7 , 6 , 9 , 3 , 4 , 5 , 8 , 2 , 1};
    int len = sizeof(in) / sizeof(in[0]);
    root = buildTree(in , pre , 0 , len - 1);
    printf("inorder traversal of constructed tree\n");
    printInorder(root);    
    return (0);
}
struct node * buildTree(int in[] , int pre[] , int start , int end)
{
    static int preIndex = 0;
    struct node *tnode;
    int inIndex;

    if(start > end)
    return NULL;

    //pick current node from preorder traversal using preindex and increment it
    tnode = newNode(pre[preIndex++]);
    //if this node has no children then return
    if(start == end)
    return tnode;

    //else find the index of this node in inorder traversal
    inIndex = search_in_inorder(in , start , end , tnode->data);
    //using index in inorder traversal construct left and right subtrees
    tnode->lchild = buildTree(in , pre , start , inIndex - 1);
    tnode->rchild = buildTree(in , pre , inIndex + 1 , end);
    return tnode;   
}
int search_in_inorder(int arr[] , int start , int end , int value)
{ 
   int i;
   for(i = start ; i <= end ; i++)
   {
       if(arr[i] == value)
       return i;
   }
}
struct node * newNode(int data)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->lchild = t->rchild = NULL;
    return t;
}
void printInorder(struct node *node)
{
    if(node == NULL)
    return;
    //first recur on left child
    printInorder(node->lchild);
    //then print the data of node
    printf("%d\t",node->data);
    printInorder(node->rchild);
}