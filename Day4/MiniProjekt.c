#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    double progress;
    Status status;
} Student;

/* Utility */
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Convert enum to text */
const char* getStatusText(Status status) {
    switch (status) {
        case NOT_STARTED: return "Not Started";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        default: return "Unknown";
    }
}

/* Input validation */
int getValidInt() {
    int value;
    if (scanf("%d", &value) != 1) {
        clearBuffer();
        return -1;
    }
    return value;
}

double getValidDouble() {
    double value;
    if (scanf("%lf", &value) != 1) {
        clearBuffer();
        return -1;
    }
    return value;
}

/* Get valid status using switch */
Status getValidStatus() {
    int choice;

    printf("Choose Status:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Choice: ");

    choice = getValidInt();

    switch (choice) {
        case 1: return NOT_STARTED;
        case 2: return IN_PROGRESS;
        case 3: return COMPLETED;
        default:
            printf("Invalid status.\n");
            return 0;
    }
}

/* Add student */
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nStorage full. Cannot add more students.\n");
        return;
    }

    printf("\nEnter ID: ");
    int id = getValidInt();
    if (id <= 0) {
        printf("Invalid ID.\n");
        return;
    }

    /* check duplicate ID */
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            printf("ID already exists.\n");
            return;
        }
    }

    students[*count].id = id;

    clearBuffer();

    printf("Enter Name: ");
    fgets(students[*count].name, NAME_LENGTH, stdin);

    int len = strlen(students[*count].name);
    if (students[*count].name[len - 1] == '\n') {
        students[*count].name[len - 1] = '\0';
    }

    if (strlen(students[*count].name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter Progress (0-100): ");
    double progress = getValidDouble();

    if (progress < 0 || progress > 100) {
        printf("Invalid progress.\n");
        return;
    }

    students[*count].progress = progress;

    Status status = getValidStatus();
    if (status == 0) return;

    students[*count].status = status;

    (*count)++;

    printf("Student added successfully.\n");
}

/* Show all students */
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
        printf("Status: %s\n", getStatusText(students[i].status));
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=====================\n");
        printf("Student Progress Tracker\n");
        printf("=====================\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");
        printf("Choose: ");

        choice = getValidInt();

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
                printf("Invalid menu option.\n");
        }

    } while (choice != 3);

    return 0;
}
