#include <stdio.h>
#include <string.h>

enum Status {
    ACTIVE = 1,
    INACTIVE,
    GRADUATED,
    DROPPED
};

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
        printf("3. Exit\n");
        printf("Choose option: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1: {

                if (count < 5) {

                    printf("Enter ID: ");
                    scanf("%d", &ids[count]);

                    printf("Enter Name: ");
                    scanf("%s", names[count]);

                    printf("Enter Progress (0-100): ");
                    scanf("%d", &progress[count]);

                    int s;

                    printf("\nSelect Status:\n");
                    printf("1. ACTIVE\n2. INACTIVE\n3. GRADUATED\n4. DROPPED\n");
                    printf("Choice: ");
                    scanf("%d", &s);

                    switch (s) {
                        case 1:
                            status[count] = ACTIVE;
                            break;
                        case 2:
                            status[count] = INACTIVE;
                            break;
                        case 3:
                            status[count] = GRADUATED;
                            break;
                        case 4:
                            status[count] = DROPPED;
                            break;
                        default:
                            printf("Invalid status! Default set to ACTIVE\n");
                            status[count] = ACTIVE;
                    }

                    count++;

                    printf("Student added successfully!\n");

                } else {
                    printf("Maximum capacity reached!\n");
                }

                break;
            }

            case 2: {

                if (count == 0) {
                    printf("No students found.\n");
                } else {

                    printf("\n--- STUDENTS LIST ---\n");

                    for (int i = 0; i < count; i++) {

                        printf("\nID: %d", ids[i]);
                        printf("\nName: %s", names[i]);
                        printf("\nProgress: %d", progress[i]);

                        printf("\nStatus: ");

                        switch (status[i]) {
                            case ACTIVE:
                                printf("ACTIVE");
                                break;
                            case INACTIVE:
                                printf("INACTIVE");
                                break;
                            case GRADUATED:
                                printf("GRADUATED");
                                break;
                            case DROPPED:
                                printf("DROPPED");
                                break;
                        }

                        printf("\n-------------------\n");
                    }
                }

                break;
            }

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid menu option!\n");
        }
    }

    return 0;
}
