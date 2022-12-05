// 1 + x/!1 + x^2/!2 + ..........
#include<stdio.h>
#include<stdlib.h>

int e(int x, int n);

int main()
{
    static int s = 1;
    int x , n, result;
    printf("enter the value of x\n");
    scanf("%d",&x);

    printf("enter a term upto which you want to solve\n");
    scanf("%d",&n);
    
    result = e(x , n);
    
    printf("answer is %d",result);

   return(0);
}

int e(int x , int n)
{
    static int s = 1;

    if(n == 0)
    return s;

    s = 1 + x/n * s;

    return e(x , n - 1);
}