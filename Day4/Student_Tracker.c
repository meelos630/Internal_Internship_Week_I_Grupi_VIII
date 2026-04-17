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

    printf("Choose Status:\n1. Not Started\n2. In Progress\n3. Completed\nChoice: ");
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

/* ---------- ADD ---------- */

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Storage full.\n");
        return;
    }

    printf("Enter ID: ");
    int id = getValidInt();
    if (id <= 0) return;

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            printf("ID exists.\n");
            return;
        }
    }

    students[*count].id = id;

    clearBuffer();

    printf("Enter Name: ");
    fgets(students[*count].name, NAME_LENGTH, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    printf("Enter Progress (0-100): ");
    double p = getValidDouble();
    if (p < 0 || p > 100) return;

    students[*count].progress = p;

    Status s = getValidStatus();
    if (s == 0) return;

    students[*count].status = s;

    (*count)++;
}

/* ---------- SHOW ---------- */

void showStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nProgress: %.2lf\nStatus: %s\n",
               students[i].id,
               students[i].name,
               students[i].progress,
               getStatusText(students[i].status));
    }
}

/* ---------- REPORT ---------- */

void showReport(Student students[], int count) {
    if (count == 0) {
        printf("No data.\n");
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

    printf("\nTotal: %d\nCompleted: %d\nAverage: %.2lf\nMax: %.2lf\nMin: %.2lf\n",
           count, completed, avg, max, min);

    if (avg < 50) printf("LOW\n");
    else if (avg < 80) printf("MEDIUM\n");
    else printf("HIGH\n");
}

/* ---------- POINTER UPDATE ---------- */

void updateStudent(Student *s) {
    printf("New progress: ");
    double p = getValidDouble();
    if (p < 0 || p > 100) return;

    s->progress = p;

    Status st = getValidStatus();
    if (st == 0) return;

    s->status = st;
}

void updateById(Student students[], int count) {
    printf("Enter ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]);
            return;
        }
    }

    printf("Not found.\n");
}

/* ---------- SEARCH ---------- */

void evaluateStudent(Student s) {
    if (s.progress < 50 && s.status == NOT_STARTED)
        printf("Warning.\n");
    else if (s.progress < 70)
        printf("Needs improvement.\n");
    else if (s.progress >= 80 && s.status == COMPLETED)
        printf("Excellent.\n");
    else
        printf("OK.\n");
}

void searchStudent(Student students[], int count) {
    printf("Enter ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found: %s %.2lf\n", students[i].name, students[i].progress);
            evaluateStudent(students[i]);
            return;
        }
    }

    printf("Not found.\n");
}

/* ---------- SORT + RANK (TASK 6) ---------- */

void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].progress < students[j].progress) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void showRanking(Student students[], int count) {
    if (count == 0) {
        printf("No data.\n");
        return;
    }

    printf("\nRANKING:\n");

    for (int i = 0; i < count; i++) {
        printf("#%d %s (%.2lf)\n",
               i + 1,
               students[i].name,
               students[i].progress);
    }
}

/* ---------- MAIN ---------- */

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n1.Add\n2.Show\n3.Report\n4.Search\n5.Update\n6.Rank\n7.Exit\nChoice: ");
        choice = getValidInt();

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: showReport(students, count); break;
            case 4: searchStudent(students, count); break;
            case 5: updateById(students, count); break;
            case 6:
                sortStudents(students, count);
                showRanking(students, count);
                break;
            case 7: break;
            default: printf("Invalid.\n");
        }

    } while (choice != 7);

    return 0;
}
