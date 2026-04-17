#include <stdio.h>
#include <string.h>

enum Status {
    ACTIVE = 1,
    INACTIVE,
    GRADUATED,
    DROPPED
};

void updateProgress(int *value) {
    int newProgress;

    printf("Enter new progress: ");
    scanf("%d", &newProgress);

    *value = newProgress;
}

int main() {

    int ids[5];
    char names[5][30];
    int progress[5];
    enum Status status[5];

    int count = 0;
    int choice;

    while (1) {

        printf("\n--- Student Tracker ---\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Show Report\n");
        printf("4. Update Progress (Pointer)\n");
        printf("5. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                if (count < 5) {

                    printf("Enter ID: ");
                    scanf("%d", &ids[count]);

                    printf("Enter Name: ");
                    scanf("%s", names[count]);

                    printf("Enter Progress: ");
                    scanf("%d", &progress[count]);

                    status[count] = ACTIVE;

                    count++;
                    printf("Student added!\n");

                } else {
                    printf("Maximum reached!\n");
                }

                break;

            case 2:

                for (int i = 0; i < count; i++) {
                    printf("\nID: %d | Name: %s | Progress: %d",
                           ids[i], names[i], progress[i]);
                }

                printf("\n");
                break;

            case 3: {

                if (count == 0) {
                    printf("No data.\n");
                    break;
                }

                int total = 0;

                for (int i = 0; i < count; i++)
                    total += progress[i];

                float avg = (float)total / count;

                printf("Average Progress: %.2f\n", avg);

                break;
            }

            case 4: {

                int searchId;
                int found = 0;

                printf("Enter student ID: ");
                scanf("%d", &searchId);

                for (int i = 0; i < count; i++) {

                    if (ids[i] == searchId) {

                        printf("Current progress: %d\n", progress[i]);

                        updateProgress(&progress[i]);

                        printf("Updated progress: %d\n", progress[i]);

                        found = 1;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
