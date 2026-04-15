#include <stdio.h>

int main() {
    int age;
    char initial;
    double points;
    int option;

    // INPUT
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your previous points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1, 2 or 3): ");
    scanf("%d", &option);

    // AGE CHECK
    if (age < 16 || age > 60) {
        printf("\nYou are not eligible to participate (age limit).\n");
    }
    else {

        // POINTS CLASSIFICATION
        if (points < 50) {
            printf("\nStatus: Needs more practice\n");
        }
        else if (points >= 50 && points < 75) {
            printf("\nStatus: Ready to continue\n");
        }
        else {
            printf("\nStatus: Ready for challenge\n");
        }

        // SWITCH FOR WORKSHOP
        printf("\nWorkshop selection: ");

        switch(option) {
            case 1:
                printf("Workshop 1 - Basics of Programming\n");
                break;
            case 2:
                printf("Workshop 2 - Intermediate Level\n");
                break;
            case 3:
                printf("Workshop 3 - Advanced Level\n");
                break;
            default:
                printf("Invalid workshop selection\n");
        }

        // FINAL SUMMARY
        printf("\n--- SUMMARY ---\n");
        printf("Age: %d\n", age);
        printf("Initial: %c\n", initial);
        printf("Points: %.2lf\n", points);
        printf("Workshop option: %d\n", option);
    }

    return 0;
}
