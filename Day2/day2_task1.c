#include <stdio.h>

int main() {
    // Deklarimi i variablave
    int age;
    char initial;
    float height;
    double average;

    short smallNumber = 10;
    long bigNumber = 100000;

    // Marrja e input-it
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial); // hapësira para %c është e rëndësishme

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your average grade: ");
    scanf("%lf", &average);

    // Output
    printf("\n--- USER PROFILE ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f m\n", height);
    printf("Average Grade: %.2lf\n", average);
    printf("Short Value: %hd\n", smallNumber);
    printf("Long Value: %ld\n", bigNumber);

    return 0;
}
