#include <stdio.h>

#define MAX 5

// enum për status
enum Status {
    NEVOJITET_USHTRIM = 1,
    NE_PROGRES,
    PERFUNDUAR
};

// struct për student
struct Student {
    int id;
    char emri[50];
    double progresi;
    enum Status status;
};

struct Student lista[MAX];
int count = 0;

// FUNKSION për zgjedhje statusi (switch)
enum Status zgjedhStatus() {
    int zg;

    printf("\nZgjedh statusin:\n");
    printf("1. Nevojitet ushtrim\n");
    printf("2. Ne progres\n");
    printf("3. Perfunduaar\n");
    printf("Zgjedhja: ");
    scanf("%d", &zg);

    switch(zg) {
        case 1: return NEVOJITET_USHTRIM;
        case 2: return NE_PROGRES;
        case 3: return PERFUNDUAR;
        default:
            printf("Zgjedhje e pavlefshme! Vendoset default.\n");
            return NEVOJITET_USHTRIM;
    }
}

// shtim student
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

// shfaq studentet
void shfaqStudentet() {
    if (count == 0) {
        printf("\nNuk ka regjistrime!\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nStudenti %d\n", i + 1);
        printf("ID: %d\n", lista[i].id);
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

// RAPORT ANALITIK (TASK 3)
void raporti() {
    if (count == 0) {
        printf("\n--- RAPORTI ---\n");
        printf("Nuk ka te dhena per analize!\n");
        return;
    }

    int perfunduar = 0;
    double shuma = 0;
    double max = lista[0].progresi;
    double min = lista[0].progresi;

    for (int i = 0; i < count; i++) {
        shuma += lista[i].progresi;

        if (lista[i].progresi > max)
            max = lista[i].progresi;

        if (lista[i].progresi < min)
            min = lista[i].progresi;

        if (lista[i].status == PERFUNDUAR)
            perfunduar++;
    }

    double mesatarja = shuma / count;

    printf("\n--- RAPORTI ANALITIK ---\n");
    printf("Totali i regjistrimeve: %d\n", count);
    printf("Te perfunduara: %d\n", perfunduar);
    printf("Mesatarja e progresit: %.2lf\n", mesatarja);

    if (mesatarja >= 80) {
        printf("Gjendja: Shume e mire\n");
    } else if (mesatarja >= 50) {
        printf("Gjendja: Mesatare\n");
    } else {
        printf("Gjendja: Duhet permiresim\n");
    }

    printf("Vlera maksimale: %.2lf\n", max);
    printf("Vlera minimale: %.2lf\n", min);
}

int main() {
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Raporti analitik\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        if (zgjedhja < 0 || zgjedhja > 3) {
            printf("Zgjedhje e pavlefshme!\n");
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

            case 3:
                raporti();
                break;

            case 0:
                printf("Dalje...\n");
                break;
        }

    } while (zgjedhja != 0);

    return 0;
}
