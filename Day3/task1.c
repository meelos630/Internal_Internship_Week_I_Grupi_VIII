#include <stdio.h>

int main() {

    int n, choice;

    // Marrja e input
    printf("Enter a number (1-12): ");
    scanf("%d", &n);

    // Kontrolli i input-it
    if (n < 1 || n > 12) {
        printf("Invalid input! Please enter a number between 1 and 12.\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Choose pattern type:\n");
    printf("1 - Stars (*)\n");
    printf("2 - Numbers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n--- Pattern ---\n");

    // Pattern me yje
    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    // Nëse zgjedhja nuk është valide
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
