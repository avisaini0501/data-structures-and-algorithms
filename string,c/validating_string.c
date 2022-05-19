//to find string entered by user is valid or not
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validate_string(char *username);

int main()
{
    char *username , result;

    printf("enter your username\n");
    scanf("%s",username);

    result = validate_string(username);

    if(result == 0)
    printf("Username is not valid\n");

    else
    printf("succesfull...\n");
    
    
    return(0);
}

int validate_string(char *username)
{
   int i;

   for(i = 0; username[i] != '\0'; i++)
   {
      if(!(username[i] >= 65 && username[i] <= 90) && !(username[i] >= 97 && username[i] <= 122) && !(username[i] >= 48 && username[i] <= 57))
      {
          return 0;
      }

      
   }

   return 1;
}