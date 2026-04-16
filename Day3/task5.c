#include <stdio.h>

enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {

    int choice;
    int valid = 0, invalid = 0;

    for (int i = 1; i <= 3; i++) {

        printf("\nEnter level (1-4): ");
        scanf("%d", &choice);

        enum Level userLevel = choice;

        switch (userLevel) {

            case BEGINNER:
                printf("BEGINNER\n");
                valid++;
                break;

            case INTERMEDIATE:
                printf("INTERMEDIATE\n");
                valid++;
                break;

            case ADVANCED:
                printf("ADVANCED\n");
                valid++;
                break;

            case EXPERT:
                printf("EXPERT\n");
                valid++;
                break;

            default:
                printf("INVALID\n");
                invalid++;
                break;
        }
    }

    printf("\n--- STATISTICS ---\n");
    printf("Valid: %d\n", valid);
    printf("Invalid: %d\n", invalid);

    return 0;
}
