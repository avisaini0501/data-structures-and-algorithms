#include<stdio.h>
#include<stdlib.h>

int fabinocci(int n);

//midification in method using static array
int modify_fib(int n);

int main()
{
    int n , result;

    printf("enter the value of n\n");
    scanf("%d",&n);

    result  = modify_fib(n);

    printf("fabinocci series up to %dth term = %d\n",n,result);
    return(0);

}

int fabinocci(int n)
{
    if(n <= 1)
    return n;

    return fabinocci(n - 2) + fabinocci(n - 1);

}

int modify_fib(int n)
{
    static int array[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int length = n;

    if(n <= 1)
    {
        array[n] = n;
        return n;
    }

    else
    {
        if(array[n - 2] == -1)
        array[n - 2] = modify_fib(n - 2);

        if(array[n - 1] == -1)
        array[n - 1] = modify_fib(n - 1);
    }


    return array[n - 2] + array[n - 1];
}

