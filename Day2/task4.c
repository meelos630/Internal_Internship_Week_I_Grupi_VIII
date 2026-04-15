#include <stdio.h>

int main() {

    int age;
    char initial;
    double points;
    int option;

    // Marrja e input nga përdoruesi
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1-3): ");
    scanf("%d", &option);

    // Kontrolli i moshes
    printf("\n--- Registration Summary ---\n");

    if (age >= 14 && age <= 18) {
        printf("Age: %d (Eligible)\n", age);
    } else {
        printf("Age: %d (Not eligible)\n", age);
    }

    // Klasifikimi sipas pikëve
    if (points < 50) {
        printf("Level: Needs more practice\n");
    }
    else if (points < 80) {
        printf("Level: Ready to continue\n");
    }
    else {
        printf("Level: Ready for challenge\n");
    }

    // Shfaq inicialin dhe pikët
    printf("Initial: %c\n", initial);
    printf("Points: %.2lf\n", points);

    // Switch për workshop
    switch(option) {

        case 1:
            printf("Workshop: Programming Basics\n");
            break;

        case 2:
            printf("Workshop: Web Development\n");
            break;

        case 3:
            printf("Workshop: Cyber Security\n");
            break;

        default:
            printf("Invalid workshop option\n");
    }

    return 0;
}
