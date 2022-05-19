//changing upper case to lower and vice versa

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char string[] = "wElcoMe";
    int i;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] >= 65 && string[i] <= 90)
        string[i] += 32;

        else if(string[i] >= 'a' && string[i] <= 122)
        string[i] -=32;
    }

    printf("%s\n",string);
}