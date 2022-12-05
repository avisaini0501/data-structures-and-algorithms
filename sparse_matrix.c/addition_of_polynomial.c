//addition of polynomial
#include<stdio.h>
#include<stdlib.h>

struct term
{
    int coff;
    int exp;
};
struct poly
{
    int num;
    struct term *t;
};

void create(struct poly *ptr);
struct poly * add(struct poly *p1 , struct poly *p2);
void display(struct poly *pol);

int main()
{
    int i;
    struct poly p1 , p2 , *p3;
    
    create(&p1);
    create(&p2);

    p3 = add(&p1 , &p2);

    printf("polynomial 1:\n");
    display(&p1);

    printf("polinomial 2:\n");
    display(&p2);

    printf("sum of polynomials:\n");
    display(p3);

    return 0;

}

void create(struct poly *ptr)
{
    int i;

    struct poly p;

    printf("how many non zero term\n");
    scanf("%d",&ptr->num);

    ptr->t = (struct term *)malloc(ptr->num * sizeof(struct term));

    printf("enter cofficients and their exponents\n");
    for(i = 0; i < ptr->num; i++)
    {
        scanf("%d %d",&ptr->t[i].coff , &ptr->t[i].exp);
    }
}

struct poly * add(struct poly *p1 , struct poly *p2)
{
    int i , j , k;
    struct poly *sum;

    i = j = k = 0;

    sum = (struct poly *)malloc(sizeof(struct poly));
    sum->t = (struct term *)malloc((p1->num + p2->num) * sizeof(struct term));

    while(i < p1->num && j < p2->num)
    {
        if(p1->t[i].exp > p2->t[j].exp)
        sum->t[k++]  = p1->t[i++];

        else if(p1->t[i].exp < p2->t[j].exp)
        sum->t[k++] = p2->t[j++];

        else
        {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coff = (p1->t[i++].coff + p2->t[j++].coff);
            
        }
    }
    for(; i < p1->num; i++)
    {
        sum->t[k++] = p1->t[i];
    }

    for(; j < p2->num; i++)
    {
        sum->t[k++] = p2->t[j];
    }
 

    sum->num = k;

    return sum;
}

void display(struct poly *pol)
{
    int i;

    for(i = 0; i < pol->num; i++)
    {
        printf("%dx^%d + ",pol->t[i].coff , pol->t[i].exp);
    }

    printf("\n");
}