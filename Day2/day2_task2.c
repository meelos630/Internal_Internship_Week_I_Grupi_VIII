#include <stdio.h>

int main() {
    int score;

    // Marrja e input-it
    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    // Kontrolli i validitetit
    if (score < 0 || score > 100) {
        printf("Invalid input! Score must be between 0 and 100.\n");
    }
    // Klasifikimi (nga më i larti te më i ulti)
    else if (score >= 90) {
        printf("Result: Excellent (Shkelqyeshem)\n");
    }
    else if (score >= 75) {
        printf("Result: Very Good (Shume mire)\n");
    }
    else if (score >= 60) {
        printf("Result: Good (Mire)\n");
    }
    else {
        printf("Result: Needs Improvement (Ne permiresim)\n");
    }

    return 0;
}
