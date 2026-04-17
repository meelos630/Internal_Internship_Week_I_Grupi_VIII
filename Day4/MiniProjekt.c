#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    double progress;
} Student;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nStorage full. Cannot add more students.\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &students[*count].id);

    clearBuffer();

    printf("Enter Name: ");
    fgets(students[*count].name, NAME_LENGTH, stdin);

    int len = strlen(students[*count].name);
    if (students[*count].name[len - 1] == '\n') {
        students[*count].name[len - 1] = '\0';
    }

    printf("Enter Progress (0-100): ");
    scanf("%lf", &students[*count].progress);

    (*count)++;

    printf("Student added successfully.\n");
}

void showStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students stored.\n");
        return;
    }

    printf("\n--- Student List ---\n");

    for (int i = 0; i < count; i++) {
        printf("\n------------------\n");
        printf("Student #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2lf\n", students[i].progress);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=====================\n");
        printf("Student Tracker\n");
        printf("=====================\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 3);

    return 0;
}
