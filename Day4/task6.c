#include <stdio.h>
#include <string.h>

int main() {

    int ids[5];
    char names[5][30];
    int progress[5];

    int count = 0;
    int choice;

    while (1) {

        printf("\n--- Student Tracker FINAL ---\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student\n");
        printf("4. Rank Students\n");
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

                    count++;
                    printf("Student added successfully!\n");

                } else {
                    printf("Maximum students reached!\n");
                }

                break;

            case 2:

                if (count == 0) {
                    printf("No students available.\n");
                } else {

                    printf("\n--- STUDENT LIST ---\n");

                    for (int i = 0; i < count; i++) {

                        printf("%d. ID: %d | Name: %s | Progress: %d\n",
                               i + 1, ids[i], names[i], progress[i]);
                    }
                }

                break;

            case 3: {

                int searchId;
                int found = 0;

                printf("Enter ID to search: ");
                scanf("%d", &searchId);

                for (int i = 0; i < count; i++) {

                    if (ids[i] == searchId) {

                        printf("Found: %s | Progress: %d\n",
                               names[i], progress[i]);

                        found = 1;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4: {

                if (count == 0) {
                    printf("No students to rank.\n");
                    break;
                }

                for (int i = 0; i < count - 1; i++) {

                    for (int j = i + 1; j < count; j++) {

                        if (progress[j] > progress[i]) {

                            int tempId = ids[i];
                            ids[i] = ids[j];
                            ids[j] = tempId;

                            int tempProgress = progress[i];
                            progress[i] = progress[j];
                            progress[j] = tempProgress;

                            char tempName[30];
                            strcpy(tempName, names[i]);
                            strcpy(names[i], names[j]);
                            strcpy(names[j], tempName);
                        }
                    }
                }

                printf("\n--- STUDENT RANKING ---\n");

                for (int i = 0; i < count; i++) {

                    printf("%d. %s - %d points\n",
                           i + 1, names[i], progress[i]);
                }

                break;
            }

            case 5:
                printf("Exiting final project...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
