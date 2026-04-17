#include <stdio.h>
#include <string.h>

int main() {

    int ids[5];
    char names[5][30];
    int progress[5];

    int count = 0;
    int choice;

    while (1) {

        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add Record\n");
        printf("2. Show All Records\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                if (count < 5) {

                    printf("Enter ID: ");
                    scanf("%d", &ids[count]);

                    printf("Enter Name: ");
                    scanf("%s", names[count]);

                    printf("Enter Progress (0-100): ");
                    scanf("%d", &progress[count]);

                    count++;

                    printf("Record added successfully!\n");

                } else {
                    printf("Maximum records reached!\n");
                }

                break;

            case 2:

                if (count == 0) {
                    printf("No records available.\n");
                } else {

                    printf("\n--- All Records ---\n");

                    for (int i = 0; i < count; i++) {
                        printf("ID: %d | Name: %s | Progress: %d\n",
                               ids[i], names[i], progress[i]);
                    }
                }

                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
