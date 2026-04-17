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

/* ---------- UTILITY ---------- */

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidInt() {
    int x;
    if (scanf("%d", &x) != 1) {
        clearBuffer();
        return -1;
    }
    return x;
}

double getValidDouble() {
    double x;
    if (scanf("%lf", &x) != 1) {
        clearBuffer();
        return -1;
    }
    return x;
}

const char* getStatusText(Status s) {
    switch (s) {
        case NOT_STARTED: return "Not Started";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        default: return "Unknown";
    }
}

Status getValidStatus() {
    int c;

    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Choice: ");

    c = getValidInt();

    if (c >= 1 && c <= 3) {
        return (Status)c;
    }

    printf("Invalid status.\n");
    return 0;
}

void printStudent(Student s) {
    printf("\n------------------------\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Progress: %.2lf\n", s.progress);
    printf("Status: %s\n", getStatusText(s.status));
}

/* ---------- ADD ---------- */

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Storage full.\n");
        return;
    }

    printf("Enter ID: ");
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
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    if (strlen(students[*count].name) == 0) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter Progress (0-100): ");
    double p = getValidDouble();

    if (p < 0 || p > 100) {
        printf("Invalid progress.\n");
        return;
    }

    students[*count].progress = p;

    Status st = getValidStatus();
    if (st == 0) {
        return;
    }

    students[*count].status = st;

    (*count)++;
    printf("Student added successfully.\n");
}

/* ---------- SHOW ---------- */

void showStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n===== STUDENTS =====\n");

    for (int i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

/* ---------- REPORT ---------- */

void report(Student students[], int count) {
    if (count == 0) {
        printf("No data available.\n");
        return;
    }

    double total = 0;
    double max = students[0].progress;
    double min = students[0].progress;
    int completed = 0;

    for (int i = 0; i < count; i++) {
        total += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        }

        if (students[i].progress > max) {
            max = students[i].progress;
        }

        if (students[i].progress < min) {
            min = students[i].progress;
        }
    }

    double avg = total / count;

    printf("\n===== REPORT =====\n");
    printf("Total Students: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Average: %.2lf\n", avg);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);

    if (avg < 50) {
        printf("Performance: LOW\n");
    } else if (avg < 80) {
        printf("Performance: MEDIUM\n");
    } else {
        printf("Performance: HIGH\n");
    }
}

/* ---------- UPDATE ---------- */

void updateStudent(Student *student) {
    printf("Enter new progress (0-100): ");
    double p = getValidDouble();

    if (p < 0 || p > 100) {
        printf("Invalid progress.\n");
        return;
    }

    student->progress = p;

    Status s = getValidStatus();
    if (s == 0) {
        return;
    }

    student->status = s;

    printf("Student updated successfully.\n");
}

void updateById(Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("Enter ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]);
            return;
        }
    }

    printf("Student not found.\n");
}

/* ---------- SEARCH ---------- */

void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("Enter ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\n===== FOUND =====\n");
            printStudent(students[i]);

            if (students[i].progress < 50 && students[i].status == NOT_STARTED) {
                printf("Evaluation: Warning. Student is falling behind.\n");
            } else if (students[i].progress < 70 && students[i].status == IN_PROGRESS) {
                printf("Evaluation: Student needs improvement.\n");
            } else if (students[i].progress >= 80 && students[i].status == COMPLETED) {
                printf("Evaluation: Excellent performance.\n");
            } else {
                printf("Evaluation: Normal progress.\n");
            }

            return;
        }
    }

    printf("Student not found.\n");
}

/* ---------- SORT + RANK ---------- */

void sortStudents(Student students[], int count) {
    if (count == 0) {
        printf("No data to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].progress < students[j].progress) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("Students sorted successfully.\n");
}

void ranking(Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n===== RANKING =====\n");

    for (int i = 0; i < count; i++) {
        printf("#%d %s (%.2lf)\n", i + 1, students[i].name, students[i].progress);
    }
}

/* ---------- DELETE ---------- */

void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("No students to delete.\n");
        return;
    }

    printf("Enter ID to delete: ");
    int id = getValidInt();

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

/* ---------- MAIN ---------- */

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Report\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Rank\n");
        printf("7. Delete\n");
        printf("8. Exit\n");
        printf("Choice: ");

        choice = getValidInt();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                report(students, count);
                break;
            case 4:
                searchStudent(students, count);
                break;
            case 5:
                updateById(students, count);
                break;
            case 6:
                sortStudents(students, count);
                ranking(students, count);
                break;
            case 7:
                deleteStudent(students, &count);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 8);

    return 0;
}
