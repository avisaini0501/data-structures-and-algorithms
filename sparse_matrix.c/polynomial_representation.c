//representation of polynomial
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

void display(struct poly *pol);

int main()
{
    int i;
    struct poly p;

    printf("how many non zero term\n");
    scanf("%d",&p.num);

    p.t = (struct term *)malloc(p.num * sizeof(struct term));

    printf("enter cofficients and their exponents\n");
    for(i = 0; i < p.num; i++)
    {
        scanf("%d %d",&p.t[i].coff , &p.t[i].exp);
    }

    display(&p);
    
    return(0);
}
   
void display(struct poly *pol)
{
    int i;
    for(i = 0; i < pol->num; i++)
    {
      printf("%dx^%d + ",pol->t[i].coff,pol->t[i].exp);
    }
}