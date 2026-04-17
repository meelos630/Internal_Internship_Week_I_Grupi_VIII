#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED = 0,
    IN_PROGRESS = 1,
    COMPLETED = 2
} Status;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    double progress;
    Status status;
    int isUsed;
} Student;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

const char* getStatusText(Status status) {
    switch (status) {
        case NOT_STARTED:
            return "Not Started";
        case IN_PROGRESS:
            return "In Progress";
        case COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}

Status calculateStatus(double progress) {
    if (progress < 0 || progress > 100) {
        return NOT_STARTED;
    } else if (progress < 50) {
        return NOT_STARTED;
    } else if (progress < 100) {
        return IN_PROGRESS;
    } else {
        return COMPLETED;
    }
}

void addStudent(Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nCannot add more students. Storage is full.\n");
        return;
    }

    Student newStudent;
    newStudent.isUsed = 1;

    printf("\nEnter student ID: ");
    if (scanf("%d", &newStudent.id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    if (newStudent.id <= 0) {
        printf("ID must be greater than 0.\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        if (students[i].isUsed && students[i].id == newStudent.id) {
            printf("A student with this ID already exists.\n");
            return;
        }
    }

    clearInputBuffer();

    printf("Enter student name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);

    size_t len = strlen(newStudent.name);
    if (len > 0 && newStudent.name[len - 1] == '\n') {
        newStudent.name[len - 1] = '\0';
    }

    if (strlen(newStudent.name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter progress (0 - 100): ");
    if (scanf("%lf", &newStudent.progress) != 1) {
        printf("Invalid progress input.\n");
        clearInputBuffer();
        return;
    }

    if (newStudent.progress < 0 || newStudent.progress > 100) {
        printf("Progress must be between 0 and 100.\n");
        return;
    }

    newStudent.status = calculateStatus(newStudent.progress);

    students[*count] = newStudent;
    (*count)++;

    printf("\nStudent added successfully.\n");
}

void showStudents(Student *students, int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        if (students[i].isUsed) {
            printf("\nStudent %d\n", i + 1);
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Progress: %.2lf\n", students[i].progress);
            printf("Status: %s\n", getStatusText(students[i].status));
        }
    }
}

void showSingleStudent(Student *student) {
    if (!student->isUsed) {
        printf("Empty record.\n");
        return;
    }

    printf("\nID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Progress: %.2lf\n", student->progress);
    printf("Status: %s\n", getStatusText(student->status));
}

void searchStudentById(Student *students, int count) {
    int id;
    int found = 0;

    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nEnter student ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].isUsed && students[i].id == id) {
            printf("\nStudent found:\n");
            showSingleStudent(&students[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d was not found.\n", id);
    }
}

void updateProgress(Student *students, int count) {
    int id;
    int found = 0;
    double newProgress;

    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nEnter student ID to update progress: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].isUsed && students[i].id == id) {
            printf("Enter new progress (0 - 100): ");
            if (scanf("%lf", &newProgress) != 1) {
                printf("Invalid progress input.\n");
                clearInputBuffer();
                return;
            }

            if (newProgress < 0 || newProgress > 100) {
                printf("Progress must be between 0 and 100.\n");
                return;
            }

            students[i].progress = newProgress;
            students[i].status = calculateStatus(newProgress);

            printf("Progress updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d was not found.\n", id);
    }
}

void showSummary(Student *students, int count) {
    int notStartedCount = 0;
    int inProgressCount = 0;
    int completedCount = 0;

    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].isUsed) {
            switch (students[i].status) {
                case NOT_STARTED:
                    notStartedCount++;
                    break;
                case IN_PROGRESS:
                    inProgressCount++;
                    break;
                case COMPLETED:
                    completedCount++;
                    break;
                default:
                    break;
            }
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total students: %d\n", count);
    printf("Not Started: %d\n", notStartedCount);
    printf("In Progress: %d\n", inProgressCount);
    printf("Completed: %d\n", completedCount);
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i].isUsed = 0;
    }

    do {
        printf("\n==============================\n");
        printf("Student Progress Tracker\n");
        printf("==============================\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Search student by ID\n");
        printf("4. Update student progress\n");
        printf("5. Show summary\n");
        printf("6. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                searchStudentById(students, count);
                break;
            case 4:
                updateProgress(students, count);
                break;
            case 5:
                showSummary(students, count);
                break;
            case 6:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid option. Please choose from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}
