#include <stdio.h>
#include <string.h>

#define MAX 5

// ================= ENUM =================
enum Status {
    NEVOJITET_USHTRIM = 1,
    NE_PROGRES,
    PERFUNDUAR
};

// ================= STRUCT =================
struct Student {
    int id;
    char emri[50];
    double progresi;
    enum Status status;
};

struct Student lista[MAX];
int count = 0;

// ================= TASK 2: STATUS =================
enum Status zgjedhStatus() {
    int z;
    printf("\nZgjedh statusin:\n");
    printf("1. Nevojitet ushtrim\n");
    printf("2. Ne progres\n");
    printf("3. Perfunduaar\n");
    printf("Zgjedhja: ");
    scanf("%d", &z);

    switch(z) {
        case 1: return NEVOJITET_USHTRIM;
        case 2: return NE_PROGRES;
        case 3: return PERFUNDUAR;
        default:
            printf("Gabim! Vendoset default.\n");
            return NEVOJITET_USHTRIM;
    }
}

// ================= TASK 1: SHTIM =================
void shtoStudent(struct Student *s) {
    printf("\nID: ");
    scanf("%d", &s->id);

    printf("Emri: ");
    scanf("%s", s->emri);

    printf("Progresi (0-100): ");
    scanf("%lf", &s->progresi);

    if (s->progresi < 0 || s->progresi > 100) {
        printf("Progres i pavlefshem! Vendoset 0.\n");
        s->progresi = 0;
    }

    s->status = zgjedhStatus();
}

// ================= TASK 4: POINTER UPDATE REAL =================
// ndryshon progresin real përmes pointer-it
void updateProgres(struct Student *s) {
    double ri;

    printf("\nProgresi aktual: %.2lf\n", s->progresi);
    printf("Vendos progres te ri: ");
    scanf("%lf", &ri);

    // ndryshim REAL përmes pointer-it
    s->progresi = ri;

    if (s->progresi < 50)
        s->status = NEVOJITET_USHTRIM;
    else if (s->progresi < 80)
        s->status = NE_PROGRES;
    else
        s->status = PERFUNDUAR;

    printf("U perditesua me sukses!\n");
}

// ================= TASK 5: SEARCH =================
void kerkoStudent() {
    int id;
    int found = 0;

    printf("\nShkruaj ID per kerkim: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lista[i].id == id) {
            printf("\n--- U GJET ---\n");
            printf("Emri: %s\n", lista[i].emri);
            printf("Progresi: %.2lf\n", lista[i].progresi);

            if (lista[i].progresi < 50)
                printf("PARALAJMERIM: Rrezik deshtimi!\n");
            else if (lista[i].progresi >= 80)
                printf("REKOMANDIM: Shume mire!\n");
            else
                printf("INFO: Ne progres normal.\n");

            found = 1;
        }
    }

    if (!found)
        printf("Nuk u gjet student!\n");
}

// ================= SHFAQ =================
void shfaq() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", lista[i].id);
        printf("Emri: %s\n", lista[i].emri);
        printf("Progresi: %.2lf\n", lista[i].progresi);

        switch(lista[i].status) {
            case NEVOJITET_USHTRIM:
                printf("Status: Nevojitet ushtrim\n");
                break;
            case NE_PROGRES:
                printf("Status: Ne progres\n");
                break;
            case PERFUNDUAR:
                printf("Status: Perfunduaar\n");
                break;
        }
    }
}

// ================= RAPORT =================
void raport() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    double sum = 0, max = lista[0].progresi, min = lista[0].progresi;
    int perf = 0;

    for (int i = 0; i < count; i++) {
        sum += lista[i].progresi;

        if (lista[i].progresi > max)
            max = lista[i].progresi;

        if (lista[i].progresi < min)
            min = lista[i].progresi;

        if (lista[i].status == PERFUNDUAR)
            perf++;
    }

    printf("\n--- RAPORT ---\n");
    printf("Totali: %d\n", count);
    printf("Te perfunduara: %d\n", perf);
    printf("Mesatarja: %.2lf\n", sum / count);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);
}

// ================= MAIN MENU =================
int main() {
    int z;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto student\n");
        printf("2. Shfaq\n");
        printf("3. Raport\n");
        printf("4. Update progres (POINTER)\n");
        printf("5. Kerko student\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &z);

        if (z < 0 || z > 5) {
            printf("Gabim!\n");
            continue;
        }

        switch(z) {
            case 1:
                if (count < MAX) {
                    shtoStudent(&lista[count]);
                    count++;
                } else {
                    printf("Lista plot!\n");
                }
                break;

            case 2:
                shfaq();
                break;

            case 3:
                raport();
                break;

            case 4:
                if (count == 0) {
                    printf("Ska te dhena!\n");
                } else {
                    int id;
                    printf("Shkruaj ID per update: ");
                    scanf("%d", &id);

                    int found = 0;
                    for (int i = 0; i < count; i++) {
                        if (lista[i].id == id) {
                            updateProgres(&lista[i]); // POINTER REAL
                            found = 1;
                        }
                    }

                    if (!found)
                        printf("Nuk u gjet student!\n");
                }
                break;

            case 5:
                kerkoStudent();
                break;

            case 0:
                printf("Dalje...\n");
                break;
        }

    } while (z != 0);

    return 0;
}
