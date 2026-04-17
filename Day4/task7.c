#include <stdio.h>
#include <string.h>

int main() {

    int ids[5];
    char names[5][30];
    int progress[5];

    int count = 0;
    int choice;

    while (1) {

        printf("\n--- Student Tracker PRO ---\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
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

                    printf("Student added!\n");

                } else {
                    printf("Maximum reached!\n");
                }

                break;

            case 2:

                if (count == 0) {
                    printf("No students.\n");
                } else {

                    printf("\n--- LIST ---\n");

                    for (int i = 0; i < count; i++) {

                        printf("%d. ID:%d | Name:%s | Progress:%d\n",
                               i + 1, ids[i], names[i], progress[i]);
                    }
                }

                break;

            case 3: {

                int searchId;
                int found = 0;

                printf("Enter ID to edit: ");
                scanf("%d", &searchId);

                for (int i = 0; i < count; i++) {

                    if (ids[i] == searchId) {

                        printf("Enter new name: ");
                        scanf("%s", names[i]);

                        printf("Enter new progress: ");
                        scanf("%d", &progress[i]);

                        printf("Student updated!\n");

                        found = 1;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4: {

                int searchId;
                int found = 0;

                printf("Enter ID to delete: ");
                scanf("%d", &searchId);

                for (int i = 0; i < count; i++) {

                    if (ids[i] == searchId) {

                        for (int j = i; j < count - 1; j++) {

                            ids[j] = ids[j + 1];
                            progress[j] = progress[j + 1];
                            strcpy(names[j], names[j + 1]);
                        }

                        count--;

                        printf("Student deleted!\n");

                        found = 1;
                        break;
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
