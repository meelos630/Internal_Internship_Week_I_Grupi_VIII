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
        printf("3. Show Report\n");
        printf("4. Exit\n");
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
                        case 1: status[count] = ACTIVE; break;
                        case 2: status[count] = INACTIVE; break;
                        case 3: status[count] = GRADUATED; break;
                        case 4: status[count] = DROPPED; break;
                        default:
                            printf("Invalid status! Set to ACTIVE\n");
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

                    for (int i = 0; i < count; i++) {

                        printf("\nID: %d | Name: %s | Progress: %d | Status: ",
                               ids[i], names[i], progress[i]);

                        if (status[i] == ACTIVE) printf("ACTIVE");
                        else if (status[i] == INACTIVE) printf("INACTIVE");
                        else if (status[i] == GRADUATED) printf("GRADUATED");
                        else printf("DROPPED");
                    }
                    printf("\n");
                }

                break;
            }

            case 3: {

                if (count == 0) {
                    printf("No data to analyze.\n");
                    break;
                }

                int total = 0;
                int max = progress[0];
                int min = progress[0];
                int completed = 0;

                for (int i = 0; i < count; i++) {

                    total += progress[i];

                    if (progress[i] > max)
                        max = progress[i];

                    if (progress[i] < min)
                        min = progress[i];

                    if (progress[i] >= 50)
                        completed++;
                }

                float avg = (float)total / count;

                printf("\n--- REPORT ---\n");
                printf("Total Students: %d\n", count);
                printf("Average Progress: %.2f\n", avg);
                printf("Highest Progress: %d\n", max);
                printf("Lowest Progress: %d\n", min);
                printf("Completed (>=50): %d\n", completed);

                if (avg >= 75)
                    printf("Class Performance: Excellent\n");
                else if (avg >= 50)
                    printf("Class Performance: Good\n");
                else
                    printf("Class Performance: Needs Improvement\n");

                break;
            }

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
