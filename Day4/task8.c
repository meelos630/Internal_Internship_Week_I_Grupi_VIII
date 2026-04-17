#include <stdio.h>
#include <string.h>

#define MAX 5

int ids[MAX];
char names[MAX][30];
int progress[MAX];
int count = 0;

void menu() {
    printf("\n=============================\n");
    printf("   STUDENT TRACKER FINAL\n");
    printf("=============================\n");
    printf("1. Add Student\n");
    printf("2. Show Students\n");
    printf("3. Edit Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("=============================\n");
    printf("Choose option: ");
}

void addStudent() {

    if (count >= MAX) {
        printf("Maximum capacity reached!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &ids[count]);

    printf("Enter Name: ");
    scanf("%s", names[count]);

    printf("Enter Progress: ");
    scanf("%d", &progress[count]);

    count++;

    printf("Student added successfully!\n");
}

void showStudents() {

    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n------- STUDENT LIST -------\n");

    for (int i = 0; i < count; i++) {
        printf("%d. ID:%d | Name:%s | Progress:%d\n",
               i + 1, ids[i], names[i], progress[i]);
    }

    printf("----------------------------\n");
}

void editStudent() {

    int id;
    int found = 0;

    printf("Enter ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (ids[i] == id) {

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
}

void deleteStudent() {

    int id;
    int found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (ids[i] == id) {

            for (int j = i; j < count - 1; j++) {

                ids[j] = ids[j + 1];
                progress[j] = progress[j + 1];
                strcpy(names[j], names[j + 1]);
            }

            count--;
            found = 1;

            printf("Student deleted!\n");
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

int main() {

    int choice;

    while (1) {

        menu();
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                showStudents();
                break;

            case 3:
                editStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("Exiting final project...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
