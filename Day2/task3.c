#include <stdio.h>

int main() {

    int day;

    // Marrja e input nga përdoruesi
    printf("Enter a number (1-7): ");
    scanf("%d", &day);

    // Përdorimi i switch për ditët e javës
    switch(day) {

        case 1:
            printf("Monday - Work day\n");
            break;

        case 2:
            printf("Tuesday - Work day\n");
            break;

        case 3:
            printf("Wednesday - Work day\n");
            break;

        case 4:
            printf("Thursday - Work day\n");
            break;

        case 5:
            printf("Friday - Work day\n");
            break;

        case 6:
            printf("Saturday - Weekend\n");
            break;

        case 7:
            printf("Sunday - Weekend\n");
            break;

        default:
            printf("Invalid input! Please enter a number between 1 and 7.\n");
    }

    return 0;
}
