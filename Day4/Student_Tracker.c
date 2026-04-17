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
    printf("1. Not Started\n2. In Progress\n3. Completed\nChoice: ");
    c = getValidInt();

    if (c >= 1 && c <= 3) return (Status)c;

    printf("Invalid status.\n");
    return 0;
}

/* ---------- ADD ---------- */

void addStudent(Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Storage full.\n");
        return;
    }

    printf("Enter ID: ");
    int id = getValidInt();
    if (id <= 0) return;

    for (int i = 0; i < *count; i++) {
        if (s[i].id == id) {
            printf("ID already exists.\n");
            return;
        }
    }

    s[*count].id = id;

    clearBuffer();
    printf("Enter Name: ");
    fgets(s[*count].name, NAME_LENGTH, stdin);
    s[*count].name[strcspn(s[*count].name, "\n")] = 0;

    printf("Enter Progress (0-100): ");
    double p = getValidDouble();
    if (p < 0 || p > 100) return;

    s[*count].progress = p;

    Status st = getValidStatus();
    if (st == 0) return;

    s[*count].status = st;

    (*count)++;
    printf("Student added successfully.\n");
}

/* ---------- SHOW ---------- */

void showStudents(Student s[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n===== STUDENTS =====\n");

    for (int i = 0; i < count; i++) {
        printf("\n------------------------\n");
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("Progress: %.2lf\n", s[i].progress);
        printf("Status: %s\n", getStatusText(s[i].status));
    }
}

/* ---------- REPORT ---------- */

void report(Student s[], int count) {
    if (count == 0) {
        printf("No data available.\n");
        return;
    }

    double total = 0, max = s[0].progress, min = s[0].progress;
    int completed = 0;

    for (int i = 0; i < count; i++) {
        total += s[i].progress;

        if (s[i].status == COMPLETED) completed++;

        if (s[i].progress > max) max = s[i].progress;
        if (s[i].progress < min) min = s[i].progress;
    }

    double avg = total / count;

    printf("\n===== REPORT =====\n");
    printf("Total Students: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Average: %.2lf\n", avg);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);

    if (avg < 50) printf("Performance: LOW\n");
    else if (avg < 80) printf("Performance: MEDIUM\n");
    else printf("Performance: HIGH\n");
}

/* ---------- UPDATE ---------- */

void updateStudent(Student *st) {
    printf("Enter new progress: ");
    double p = getValidDouble();
    if (p < 0 || p > 100) return;

    st->progress = p;

    Status s = getValidStatus();
    if (s == 0) return;

    st->status = s;

    printf("Student updated successfully.\n");
}

void updateById(Student s[], int count) {
    printf("Enter ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            updateStudent(&s[i]);
            return;
        }
    }

    printf("Student not found.\n");
}

/* ---------- SEARCH ---------- */

void search(Student s[], int count) {
    printf("Enter ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("\n===== FOUND =====\n");
            printf("Name: %s\n", s[i].name);
            printf("Progress: %.2lf\n", s[i].progress);
            printf("Status: %s\n", getStatusText(s[i].status));
            return;
        }
    }

    printf("Student not found.\n");
}

/* ---------- SORT + RANK ---------- */

void sortStudents(Student s[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (s[i].progress < s[j].progress) {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void ranking(Student s[], int count) {
    if (count == 0) return;

    printf("\n===== RANKING =====\n");

    for (int i = 0; i < count; i++) {
        printf("#%d %s (%.2lf)\n", i + 1, s[i].name, s[i].progress);
    }
}

/* ---------- DELETE ---------- */

void deleteStudent(Student s[], int *count) {
    if (*count == 0) {
        printf("No students to delete.\n");
        return;
    }

    printf("Enter ID to delete: ");
    int id = getValidInt();

    for (int i = 0; i < *count; i++) {
        if (s[i].id == id) {

            for (int j = i; j < *count - 1; j++) {
                s[j] = s[j + 1];
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
    Student s[MAX_STUDENTS];
    int count = 0, choice;

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
            case 1: addStudent(s, &count); break;
            case 2: showStudents(s, count); break;
            case 3: report(s, count); break;
            case 4: search(s, count); break;
            case 5: updateById(s, count); break;
            case 6: sortStudents(s, count); ranking(s, count); break;
            case 7: deleteStudent(s, &count); break;
            case 8: printf("Exiting program.\n"); break;
            default: printf("Invalid option.\n");
        }

    } while (choice != 8);

    return 0;
}
