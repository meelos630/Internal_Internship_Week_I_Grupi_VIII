#include <stdio.h>

#define MAX 5

// enum për status
enum Status {
    NEVOJITET_USHTRIM = 1,
    NE_PROGRES,
    PERFUNDUAR
};

// struct
struct Student {
    int id;
    char emri[50];
    double progresi;
    enum Status status;
};

struct Student lista[MAX];
int count = 0;

// funksion për zgjedhje statusi me switch
enum Status zgjedhStatus() {
    int zgjedhja;

    printf("Zgjedh statusin:\n");
    printf("1. Nevojitet ushtrim\n");
    printf("2. Ne progres\n");
    printf("3. Perfunduaar\n");
    printf("Zgjedhja: ");
    scanf("%d", &zgjedhja);

    switch(zgjedhja) {
        case 1: return NEVOJITET_USHTRIM;
        case 2: return NE_PROGRES;
        case 3: return PERFUNDUAR;
        default:
            printf("Zgjedhje e pavlefshme! Status default: Nevojitet ushtrim\n");
            return NEVOJITET_USHTRIM;
    }
}

// shto student (me pointer)
void shtoStudent(struct Student *s) {
    printf("ID: ");
    scanf("%d", &s->id);

    printf("Emri: ");
    scanf("%s", s->emri);

    printf("Progresi (0-100): ");
    scanf("%lf", &s->progresi);

    // validim progresi
    if (s->progresi < 0 || s->progresi > 100) {
        printf("Progres i pavlefshem! Vendoset 0.\n");
        s->progresi = 0;
    }

    // përdor enum për status
    s->status = zgjedhStatus();
}

// shfaq studentet
void shfaqStudentet() {
    if (count == 0) {
        printf("Nuk ka regjistrime!\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", lista[i].id);
        printf("Emri: %s\n", lista[i].emri);
        printf("Progresi: %.2lf\n", lista[i].progresi);

        // switch për status
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

int main() {
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        // validim menu
        if (zgjedhja < 0 || zgjedhja > 2) {
            printf("Zgjedhje e pavlefshme! Provo prap.\n");
            continue;
        }

        switch(zgjedhja) {
            case 1:
                if (count < MAX) {
                    shtoStudent(&lista[count]);
                    count++;
                    printf("Studenti u shtua!\n");
                } else {
                    printf("Lista eshte plot!\n");
                }
                break;

            case 2:
                shfaqStudentet();
                break;

            case 0:
                printf("Dalje...\n");
                break;
        }

    } while (zgjedhja != 0);

    return 0;
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
