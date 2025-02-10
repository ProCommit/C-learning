#include <stdio.h>
#include <string.h>


void reversIt(char *word)
{
   int length = strlen(word)-1;
   char revers[length];
   int flag = 0;
   

   for (int i = length ; i >= 0; i--)
   {
      revers[flag] = word[i];
      flag++;
      
   }
   revers[flag] = '\0';
   printf("%s\n",revers);
}

int main()
{
   char name[100];

   printf("Enter word to reverse it:\n");
   scanf("%[^\n]99s\n",name);

   reversIt(name);
  
   return 0;
}