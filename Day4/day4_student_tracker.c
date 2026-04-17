#include <stdio.h>
#include <string.h>

#define MAX 5

// enum për status
enum Status {
    NEVOJITET_USHTRIM = 1,
    NE_PROGRES,
    PERFUNDUAR
};

// struct student
struct Student {
    int id;
    char emri[50];
    double progresi;
    enum Status status;
};

struct Student lista[MAX];
int count = 0;

// ===================== STATUS MENU =====================
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
            printf("Zgjedhje e pavlefshme! Vendoset default.\n");
            return NEVOJITET_USHTRIM;
    }
}

// ===================== SHTO =====================
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

// ===================== SHFAQ =====================
void shfaqStudentet() {
    if (count == 0) {
        printf("\nNuk ka regjistrime!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- STUDENT ---\n");
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

// ===================== KËRKIM (TASK 5) =====================
void kerkoStudent() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    int id;
    char emri[50];
    int gjetur = 0;

    printf("\nKerkim sipas ID (shkruaj ID): ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lista[i].id == id) {
            printf("\n--- U GJET STUDENTI ---\n");
            printf("Emri: %s\n", lista[i].emri);
            printf("Progresi: %.2lf\n", lista[i].progresi);

            // LOGJIKA PARALAJMERUESE
            if (lista[i].progresi < 50 && lista[i].status == NEVOJITET_USHTRIM) {
                printf("PARALAJMERIM: Student me rrezik te larte! Duhet ushtrim.\n");
            } 
            else if (lista[i].progresi >= 80 && lista[i].status == PERFUNDUAR) {
                printf("REKOMANDIM: Shume mire! Mund te kalosh ne nivel me te avancuar.\n");
            } 
            else if (lista[i].progresi >= 50 && lista[i].progresi < 80) {
                printf("INFO: Student ne progres te mire.\n");
            }

            gjetur = 1;
        }
    }

    if (!gjetur) {
        printf("Nuk u gjet asnje student me kete ID!\n");
    }
}

// ===================== RAPORT =====================
void raporti() {
    if (count == 0) {
        printf("\nNuk ka te dhena!\n");
        return;
    }

    int perf = 0;
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
            perf++;
    }

    printf("\n--- RAPORT ---\n");
    printf("Totali: %d\n", count);
    printf("Te perfunduara: %d\n", perf);
    printf("Mesatarja: %.2lf\n", shuma / count);
    printf("Max: %.2lf\n", max);
    printf("Min: %.2lf\n", min);
}

// ===================== MAIN =====================
int main() {
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Raporti\n");
        printf("4. Kerko student\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        if (zgjedhja < 0 || zgjedhja > 4) {
            printf("Zgjedhje e pavlefshme!\n");
            continue;
        }

        switch(zgjedhja) {
            case 1:
                if (count < MAX) {
                    shtoStudent(&lista[count]);
                    count++;
                    printf("Shtuar me sukses!\n");
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

            case 4:
                kerkoStudent();
                break;

            case 0:
                printf("Dalje...\n");
                break;
        }

    } while (zgjedhja != 0);

    return 0;
}
