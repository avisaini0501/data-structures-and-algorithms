//counting vowels and words in a single scan

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//for countning words
void count_words();

int main()
{    
    count_words();
    char string[] = "how are you";
    int i , v_count = 0, c_count = 0;

    for(i = 0; string[i] != '\0'; i++)
    {
       if(string[i] == 'a' || string[i] == 'e' ||string[i] == 'i' ||string[i] == 'o' ||string[i] == 'u' 
        ||string[i] == 'A' ||string[i] == 'E' ||string[i] == 'I' ||string[i] == 'O' ||string[i] == 'U')
        {
          v_count++;
        }

        else if((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122))
        {
            c_count++;
        }
    }

    printf("number of consonents = %d\n",c_count);
    printf("number of vowels = %d\n",v_count);

    return(0);
}

void count_words()
{
    char string[] = "hello my name is avi saini";
    int i , word = 1;

    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == ' ' && string[i- 1] != ' ')
        {
            word++;            
        }

       
    }
     printf("number of words = %d\n",word);
}