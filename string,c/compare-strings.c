//comparing two strings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str1[] = "painting";
    char str2[] = "painter";
    int i , j;

    for(i = 0 , j = 0; str1[i] != '\0', str2[j] != '\0'; i++,j++)
    {
        if(str1[i] != str2[j])
        break;
    }

    if(str1[i] == str2[j])
    printf("strings are equal\n");

    else if(str1[i] < str2[j])
    printf("string 1 is smaller\n");

    else 
    printf("string 1 larger\n");

    return(0);
}