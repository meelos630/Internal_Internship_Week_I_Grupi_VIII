#include <stdio.h>

int main() {
    int n, choice;

    printf("Jep nje numer (1-12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Input i pavlefshem! Duhet te jete 1 deri 12.\n");
        return 0;
    }

    printf("Zgjedh pattern-in:\n");
    printf("1 - Yje (*)\n");
    printf("2 - Numra\n");
    printf("Zgjedhja: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nPattern me yje:\n");

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }

    } 
    else if (choice == 2) {
        printf("\nPattern me numra:\n");

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }

    } 
    else {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}
