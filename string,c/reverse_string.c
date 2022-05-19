//program to reverse the string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//using single array
void reverse();

int main()
{

    reverse();
    char str[] = "python";
    char revrese[7];
    int i , j;

    for(i = 0; str[i] != '\0'; i++)
    {

    }

    i--;

    for(j = 0; i >= 0; i--,j++)
    {
        revrese[j] = str[i];
    }

    revrese[j] = '\0';

    printf("%s\n",revrese);

    return(0);
}

void reverse()
{
    char str[] = "avisaini";
    int i , j , t;

    for(j = 0; str[j] != '\0'; j++)
    {

    }

    j--;

    for(i = 0; i < j; i++, j--)
    {
      t = str[i];
      str[i] = str[j];
      str[j] = t;
    }

    printf("string in reverse order = %s\n",str);
}