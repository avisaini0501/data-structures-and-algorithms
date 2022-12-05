//power on a number by two methods
#include<stdio.h>
#include<stdlib.h>

//method number one
int power(int m , int n);

//method number two
int easy_pow(int m ,  int n);

int main()
{
    int n , m , result;

    printf("enter a number and their power\n");
    scanf("%d %d",&m,&n);

    result = easy_pow(m , n);

    printf("%d raise to the power %d is = %d",m,n,result);

    return(0);
}

int power(int m , int n)
{
    if(n == 0)
    return(1);
    
    else
    return power(m , n-1) * m;
}

int easy_pow(int m , int n)
{
    if(n == 0)
    return 1;

    if(n % 2 == 0)
    return easy_pow(m * m , n/2);

    else
    return m * easy_pow(m * m , (n - 1) / 2);
}