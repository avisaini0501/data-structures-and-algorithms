//print all permutations of strings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int perm(char string[] , int k);

int main()
{
    char string[] = "ABC";
    
    perm(string,0);

    return(0);
}

int perm(char string[] , int k)
{
    static char result[10];
    static int a[10];
    int i;

    

    if(string[k] == '\0')
    {
        result[k] = '\0';
        
        for(i = 0; result[i] != '\0'; i++)
        {
            printf("%c",result[i]);
        }

        printf("\n");

    }

    else
    {
        for(i = 0; string[i] != '\0'; i++)
        {
            if(a[i] == 0)
            {
                result[k] = string[i];
                a[i] = 1;
                perm(string , k+1);
                a[i] = 0;
            }
        }
    }

} 