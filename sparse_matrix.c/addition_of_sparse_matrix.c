//addition of sparse matrix
#include<stdio.h>
#include<stdlib.h>

struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

struct element
{
    int i;
    int j;
    int x;
};

struct sparse * add(struct sparse *m1 , struct sparse *m2);

void create(struct sparse *mat);

void display(struct sparse *matrix);

int main()
{
    struct sparse s1, s2, *s3;

    create(&s1);

    create(&s2);

    s3 = add(&s1 , &s2);

    printf("matrix 1:\n");       
    display(&s1);

    printf("matrix 2:\n");
    display(&s2);

    printf("sum of two matrix\n");
    display(s3);

    return(0);
    
}

//create matrix 1
void create(struct sparse *mat)
{
    int i;
    printf("enter the dimension of matrix\n");
    scanf("%d %d",&mat->m,&mat->n);

    printf("enter number of non zero elements\n");
    scanf("%d",&mat->num);

    mat->e = (struct element *)malloc(mat->num * sizeof(struct element));

    printf("enter row , columnn and all non zero elements\n");
    for(i = 0; i < mat->num; i++)
    {
        scanf("%d %d %d",&mat->e[i].i,&mat->e[i].j,&mat->e[i].x);
    }

    printf("\n\n");
}

struct sparse * add(struct sparse *m1 , struct sparse *m2)
{
    struct sparse *sum;
    int i , j , k;
    i = j = k = 0;

    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->e = (struct element *)malloc((m1->num + m2->num) * sizeof(struct element));

    while (i < m1->num && j < m2->num)
    {
        if(m1->e[i].i < m2->e[j].i)
        sum->e[k++] = m1->e[i++];

        else if(m1->e[i].i > m2->e[j].i)
        sum->e[k++] = m2->e[j++];

        else
        {
            if(m1->e[i].j < m2->e[j].j)
            sum->e[k++] = m1->e[i++];

            else if(m1->e[i].j > m2->e[j].j)
            sum->e[k++] = m2->e[j++];

            else
            {
                sum->e[k].i = m1->e[i].i;
                sum->e[k].j = m1->e[i].j;
                sum->e[k++].x = (m1->e[i++].x + m2->e[j++].x);
            }
        }
    }
    for(; i < m1->num; i++)
    {
        sum->e[k++] = m1->e[i];
    }

    for(; j < m2->num; j++)
    {
        sum->e[k++] = m2->e[j];
    }

    sum->m = m1->m;
    sum->n = m1->n;
    sum->num = k;

    return sum;
}


void display(struct sparse *matrix)
{
   int i , j , k = 0;

   for(i = 0; i < matrix->m; i++)
   {
       for(j = 0;j < matrix->n; j++)
       {
           if(i == matrix->e[k].i && j == matrix->e[k].j)
           printf("%d ",matrix->e[k++].x);
           
           else
           printf("0 ");
           
       }

       printf("\n");
   }
}