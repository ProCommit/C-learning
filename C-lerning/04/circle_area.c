#include <stdio.h>
#include <math.h>


#define PI 3.14159265359 




float circleArea(float radius)
{   
    float A = PI * pow(radius,2);
    return A;

}

int main(void)
{
    float r;

    puts("Enter the radius of your circle:");
    scanf("%f",&r);


    if ( r <= 0){
        puts("Radius cannot be negative.");
        return 1;
    }else
    {
        float A = circleArea(r);

        printf("The area of your circle is: %f\n", A); 
        return 0;
    }
    
  
}
