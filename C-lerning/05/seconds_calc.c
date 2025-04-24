#include <stdio.h>


// nice brute force :)
/*void calc_secends(int s)
{
    int sec = 0;
    int minuts = 0; 
    int hours = 0; 

    for (int i = 0; i < s; i++)
    {
       sec +=1;
    
       if (minuts == 60)
       {
        hours += 1;
        minuts = 0;
       }
       
       else if (sec == 60)
       {
        minuts += 1;
        sec = 0;
       }
       
    }

    printf("H = %i ,M = %i ,S = %i\n",hours,minuts,sec);
}
*/
void calc_secends(int s)
{
    int sec = s % 60;
    int minuts = (s % 3600)/60; 
    int hours = s / 3600;

    printf("%i seconds is equal to %i hours, %i minutes, and %i seconds.",s,hours,minuts,sec);
}



int main(void)
{
    int sec;
    puts("Enter the amount of seconds:");
    scanf("%i", &sec);

    calc_secends(sec);
    return 0;
}
