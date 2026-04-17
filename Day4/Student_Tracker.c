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

const char* getStatusText(Status status) {
    switch (status) {
        case NOT_STARTED: return "Not Started";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        default: return "Unknown";
    }
}

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

/* Add */
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nStorage full.\n");
        return;
    }

    printf("\nEnter ID: ");
    int id = getValidInt();
    if (id <= 0) {
        printf("Invalid ID.\n");
        return;
    }

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

    printf("Student added.\n");
}

/* Show all */
void showStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students.\n");
        return;
    }

    printf("\n--- Students ---\n");

    for (int i = 0; i < count; i++) {
        printf("\n------------------\n");
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2lf\n", students[i].progress);
        printf("Status: %s\n", getStatusText(students[i].status));
    }
}

/* REPORT */
void showReport(Student students[], int count) {
    if (count == 0) {
        printf("\nNo data.\n");
        return;
    }

    int completed = 0;
    double total = 0;
    double max = students[0].progress;
    double min = students[0].progress;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].status == COMPLETED) completed++;

        if (students[i].progress > max) max = students[i].progress;
        if (students[i].progress < min) min = students[i].progress;
    }

    double avg = total / count;

    printf("\n===== REPORT =====\n");
    printf("Total: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Average: %.2lf\n", avg);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);

    if (avg < 50) printf("Performance: LOW\n");
    else if (avg < 80) printf("Performance: MEDIUM\n");
    else printf("Performance: HIGH\n");
}

/* NEW: SEARCH + WARNING */
void evaluateStudent(Student s) {
    printf("\n--- Evaluation ---\n");

    if (s.progress < 50 && s.status == NOT_STARTED) {
        printf("Warning: Student is falling behind. Needs immediate action.\n");
    } else if (s.progress < 70 && s.status == IN_PROGRESS) {
        printf("Notice: Student progressing slowly. Encourage improvement.\n");
    } else if (s.progress >= 80 && s.status == COMPLETED) {
        printf("Excellent performance.\n");
    } else {
        printf("Normal progress.\n");
    }
}

void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students.\n");
        return;
    }

    int option;
    printf("\nSearch by:\n1. ID\n2. Name\nChoice: ");
    option = getValidInt();

    int found = 0;

    if (option == 1) {
        printf("Enter ID: ");
        int id = getValidInt();

        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                printf("\nFound:\n");
                printf("ID: %d\nName: %s\nProgress: %.2lf\nStatus: %s\n",
                       students[i].id,
                       students[i].name,
                       students[i].progress,
                       getStatusText(students[i].status));

                evaluateStudent(students[i]);
                found = 1;
            }
        }

    } else if (option == 2) {
        char name[NAME_LENGTH];
        clearBuffer();

        printf("Enter name: ");
        fgets(name, NAME_LENGTH, stdin);

        int len = strlen(name);
        if (name[len - 1] == '\n') name[len - 1] = '\0';

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("\nFound:\n");
                printf("ID: %d\nName: %s\nProgress: %.2lf\nStatus: %s\n",
                       students[i].id,
                       students[i].name,
                       students[i].progress,
                       getStatusText(students[i].status));

                evaluateStudent(students[i]);
                found = 1;
            }
        }

    } else {
        printf("Invalid option.\n");
        return;
    }

    if (!found) {
        printf("No matching student found.\n");
    }
}

/* MAIN */
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
        printf("3. Show Report\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
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
                showReport(students, count);
                break;
            case 4:
                searchStudent(students, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 5);

    return 0;
}
