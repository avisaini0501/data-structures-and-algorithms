//problem  "tower of hanoi"

#include<stdio.h>
#include<stdlib.h>

int tower_of_hanoi(int n , int a , int b , int c);
int main()
{
    int n , a = 1 , b = 2 , c = 3;
    
    printf("enter the number of disks\n");
    scanf("%d",&n);
    
    tower_of_hanoi(n,a,b,c);

    return(0);

}

int tower_of_hanoi(int n , int a, int b, int c)
{
    if(n > 0)
    {
      tower_of_hanoi(n - 1 , a , c , b);

      printf("(%d , %d)",a,c);

      tower_of_hanoi(n - 1 , b , a , c);
    }
} 