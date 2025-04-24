#include <stdio.h>
#include <math.h>

void quadratic(double a, double b, double c)
{
    double result = pow(b, 2) - 4 * a * c;
    if (result > 0)
    {
        double x1 = (-b + sqrt(result)) / (2 * a);
        double x2 = (-b - sqrt(result)) / (2 * a);
        printf("The solution using the x1 operator is: %.2lf\n",x1);
        printf("The solution using the x2 operator is: %.2lf\n",x2);
    }
    else if (result == 0)
    {
        double x1 = -b / (2 * a);
        printf("Only one solution: %.2lf\n",x1);

    }
    
    

}

int main(void)
{
    double A;
    double B;
    double C;

    printf("Enter the value of variable 'A': ");
    scanf("%lf", &A);
    printf("Enter the value of variable 'B': ");
    scanf("%lf", &B);
    printf("Enter the value of variable 'C': ");
    scanf("%lf", &C);

    // printf("A = %lf , B = %lf, C = %lf",A,B,C);
    quadratic(A, B, C);

    return 0;
}
