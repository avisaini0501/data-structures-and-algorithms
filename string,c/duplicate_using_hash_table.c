// find duplicate using hash table

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char arr[] = "finding";
    int h[26] = {0};
    int i;

    for(i = 0; arr[i] != '\0'; i++)
    {
        h[arr[i] - 97] += 1;
    }

    for(i = 0; i < 26; i++)
    {
        if(h[i] > 1)
        {
        printf("duplicate character is = %c\n",i + 97);
        printf("%d times\n",h[i]);
        }
    }

    return(0);
}