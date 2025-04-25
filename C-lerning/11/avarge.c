#include <stdio.h>
#include <ctype.h>

int main() {
    double sum = 0;
    int count = 0;
    double holdTheScore = 0;
    char toCountine;
    int flag = 0;

    while (flag == 0) {
        printf("Enter a test score: ");
        scanf("%lf", &holdTheScore);

        sum += holdTheScore;
        count++;

        while ((getchar()) != '\n');

        printf("Would you like to continue? Y/N ");
        scanf("%c", &toCountine);

        toCountine = toupper(toCountine);

        
        while (toCountine != 'Y' && toCountine != 'N') {
            while ((getchar()) != '\n');  
            printf("ONLY N OR Y ALLOWED! Would you like to continue? Y/N ");
            scanf("%c", &toCountine);
            toCountine = toupper(toCountine);
        }

        if (toCountine == 'N') {
            flag = 1;
        }
    }

    if (count > 0) {
        printf("%.2lf is the average.\n", sum / count);
    } else {
        printf("No scores entered.\n");
    }

    return 0;
}

