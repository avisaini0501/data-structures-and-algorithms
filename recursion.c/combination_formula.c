//program to evaluate combination formula
//that is !n / !r * !(n - r)

#include<stdio.h>
#include<stdlib.h>

int combination(int n, int r);

int main()
{
    int n , r , result;

    printf("enter the value of n and r\n");
    scanf("%d %d",&n,&r);
     
   result = combination(n , r);
    
    printf("answer is %d\n",result);

    return(0);
}

int combination(int n , int r)
{
    if(r == 0 || n == r)
    return 1;

    else
    return combination(n - 1 , r - 1) + combination(n - 1 , r);
}

