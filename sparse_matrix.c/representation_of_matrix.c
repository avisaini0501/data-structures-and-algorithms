//representation of sparse matrix in the form of array
#include<stdio.h>
#include<stdlib.h>
struct element
{
    int i;
    int j;
    int x;
};
struct sparse 
{
    int m;
    int n;
    int num;
    struct element *e;
};

//creation of matrix
void create(struct sparse *mat);
//display matrix
void display(struct sparse matrix);
int main()
{
    struct sparse s;
    create(&s);
    display(s);
    return(0);
}
void create(struct sparse *mat)
{
  int i;
  printf("enter dimensions of matrix\n");
  scanf("%d %d",&mat->m,&mat->n);
  printf("enter number of non zero elements\n");
  scanf("%d",&mat->num);
  mat->e = (struct element *)malloc(mat->num * sizeof(struct element));
  printf("enter row  , column and all non zero elements\n");
  for(i = 0; i < mat->num; i++)
  {
    scanf("%d %d %d",&mat->e[i].i,&mat->e[i].j,&mat->e[i].x);
  }
  printf("\n\n");
}
void display(struct sparse matrix)
{
    int i, j , k = 0;
    for(i = 0; i < matrix.m; i++)
    {
        for(j = 0; j < matrix.n; j++)
        {
            if(i == matrix.e[k].i && j == matrix.e[k].j)
            printf("%d ",matrix.e[k++].x);

            else
            printf("0 ");
        }
        printf("\n");
    }
}