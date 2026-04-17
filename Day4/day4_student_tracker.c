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

// ================= STATUS =================
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

// ================= SHTO =================
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

// ================= POINTER UPDATE =================
void updateProgres(struct Student *s) {
    double ri;
    printf("\nProgresi aktual: %.2lf\n", s->progresi);
    printf("Vendos progres te ri: ");
    scanf("%lf", &ri);

    s->progresi = ri;

    if (ri < 50) s->status = NEVOJITET_USHTRIM;
    else if (ri < 80) s->status = NE_PROGRES;
    else s->status = PERFUNDUAR;

    printf("U perditesua me sukses!\n");
}

// ================= SEARCH =================
void kerkoStudent() {
    int id, found = 0;
    printf("\nShkruaj ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lista[i].id == id) {
            printf("\nEmri: %s\n", lista[i].emri);
            printf("Progresi: %.2lf\n", lista[i].progresi);

            if (lista[i].progresi < 50)
                printf("PARALAJMERIM: Rrezik!\n");
            else if (lista[i].progresi >= 80)
                printf("REKOMANDIM: Shume mire!\n");
            else
                printf("Ne progres normal.\n");

            found = 1;
        }
    }

    if (!found)
        printf("Nuk u gjet!\n");
}

// ================= SHFAQ =================
void shfaq() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d | Emri: %s | Progresi: %.2lf\n",
               lista[i].id, lista[i].emri, lista[i].progresi);
    }
}

// ================= RAPORT =================
void raport() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    double sum = 0, max = lista[0].progresi, min = lista[0].progresi;

    for (int i = 0; i < count; i++) {
        sum += lista[i].progresi;

        if (lista[i].progresi > max) max = lista[i].progresi;
        if (lista[i].progresi < min) min = lista[i].progresi;
    }

    printf("\n--- RAPORT ---\n");
    printf("Mesatarja: %.2lf\n", sum / count);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);
}

// ================= TASK 6: RENDITJE =================
void renditSipasProgresit() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    struct Student temp;

    // Bubble sort (nga me i madhi te me i vogli)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lista[j].progresi < lista[j+1].progresi) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    printf("\n--- RENDITJA (TOP STUDENTS) ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2lf\n", i+1, lista[i].emri, lista[i].progresi);
    }
}

// ================= MAIN =================
int main() {
    int z;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Shto student\n");
        printf("2. Shfaq\n");
        printf("3. Raport\n");
        printf("4. Update progres\n");
        printf("5. Kerko student\n");
        printf("6. Rendit sipas progresit\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &z);

        if (z < 0 || z > 6) {
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

            case 2: shfaq(); break;
            case 3: raport(); break;

            case 4: {
                int id, found = 0;
                printf("ID: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (lista[i].id == id) {
                        updateProgres(&lista[i]);
                        found = 1;
                    }
                }

                if (!found) printf("Nuk u gjet!\n");
                break;
            }

            case 5: kerkoStudent(); break;
            case 6: renditSipasProgresit(); break;

            case 0: printf("Dalje...\n"); break;
        }

    } while (z != 0);

    return 0;
}
