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
    printf("1.Not Started  2.In Progress  3.Completed: ");
    c = getValidInt();

    if (c >= 1 && c <= 3) return (Status)c;

    printf("Invalid.\n");
    return 0;
}

/* ---------- ADD ---------- */

void addStudent(Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Full.\n");
        return;
    }

    printf("ID: ");
    int id = getValidInt();
    if (id <= 0) return;

    for (int i = 0; i < *count; i++) {
        if (s[i].id == id) {
            printf("Exists.\n");
            return;
        }
    }

    s[*count].id = id;

    clearBuffer();
    printf("Name: ");
    fgets(s[*count].name, NAME_LENGTH, stdin);
    s[*count].name[strcspn(s[*count].name, "\n")] = 0;

    printf("Progress: ");
    double p = getValidDouble();
    if (p < 0 || p > 100) return;

    s[*count].progress = p;

    Status st = getValidStatus();
    if (st == 0) return;

    s[*count].status = st;

    (*count)++;
}

/* ---------- SHOW ---------- */

void showStudents(Student s[], int count) {
    if (count == 0) {
        printf("Empty.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID:%d Name:%s Progress:%.2lf Status:%s\n",
               s[i].id, s[i].name, s[i].progress, getStatusText(s[i].status));
    }
}

/* ---------- REPORT ---------- */

void report(Student s[], int count) {
    if (count == 0) return;

    double total = 0, max = s[0].progress, min = s[0].progress;
    int completed = 0;

    for (int i = 0; i < count; i++) {
        total += s[i].progress;

        if (s[i].status == COMPLETED) completed++;

        if (s[i].progress > max) max = s[i].progress;
        if (s[i].progress < min) min = s[i].progress;
    }

    double avg = total / count;

    printf("\nTotal:%d Completed:%d Avg:%.2lf Max:%.2lf Min:%.2lf\n",
           count, completed, avg, max, min);
}

/* ---------- UPDATE (POINTER) ---------- */

void updateStudent(Student *st) {
    printf("New progress: ");
    double p = getValidDouble();
    if (p < 0 || p > 100) return;

    st->progress = p;

    Status s = getValidStatus();
    if (s == 0) return;

    st->status = s;
}

void updateById(Student s[], int count) {
    printf("ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            updateStudent(&s[i]);
            return;
        }
    }

    printf("Not found.\n");
}

/* ---------- SEARCH ---------- */

void search(Student s[], int count) {
    printf("ID: ");
    int id = getValidInt();

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("Found: %s %.2lf\n", s[i].name, s[i].progress);
            return;
        }
    }

    printf("Not found.\n");
}

/* ---------- SORT + RANK ---------- */

void sort(Student s[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (s[i].progress < s[j].progress) {
                Student t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}

void ranking(Student s[], int count) {
    for (int i = 0; i < count; i++) {
        printf("#%d %s %.2lf\n", i + 1, s[i].name, s[i].progress);
    }
}

/* ---------- DELETE (TASK 7) ---------- */

void deleteStudent(Student s[], int *count) {
    if (*count == 0) {
        printf("Empty.\n");
        return;
    }

    printf("ID to delete: ");
    int id = getValidInt();

    for (int i = 0; i < *count; i++) {
        if (s[i].id == id) {

            for (int j = i; j < *count - 1; j++) {
                s[j] = s[j + 1];   // SHIFT LEFT
            }

            (*count)--;

            printf("Deleted.\n");
            return;
        }
    }

    printf("Not found.\n");
}

/* ---------- MAIN ---------- */

int main() {
    Student s[MAX_STUDENTS];
    int count = 0, choice;

    do {
        printf("\n1.Add 2.Show 3.Report 4.Search 5.Update 6.Rank 7.Delete 8.Exit\nChoice: ");
        choice = getValidInt();

        switch (choice) {
            case 1: addStudent(s, &count); break;
            case 2: showStudents(s, count); break;
            case 3: report(s, count); break;
            case 4: search(s, count); break;
            case 5: updateById(s, count); break;
            case 6: sort(s, count); ranking(s, count); break;
            case 7: deleteStudent(s, &count); break;
            case 8: break;
            default: printf("Invalid.\n");
        }

    } while (choice != 8);

    return 0;
}
