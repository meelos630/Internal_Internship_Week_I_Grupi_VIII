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

// array + count
struct Student lista[MAX];
int count = 0;

// funksion me pointer (si kërkohet)
void shtoStudent(struct Student *s) {
    printf("ID: ");
    scanf("%d", &s->id);

    printf("Emri: ");
    scanf("%s", s->emri);

    printf("Progresi (0-100): ");
    scanf("%lf", &s->progresi);

    // vendos status me if
    if (s->progresi < 50) {
        s->status = NEVOJITET_USHTRIM;
    } else if (s->progresi < 80) {
        s->status = NE_PROGRES;
    } else {
        s->status = PERFUNDUAR;
    }
}

// shfaq studentet
void shfaqStudentet() {
    if (count == 0) {
        printf("Nuk ka regjistrime!\n");
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

int main() {
    int zgjedhja;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto student\n");
        printf("2. Shfaq te gjithe studentet\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case 1:
                if (count < MAX) {
                    shtoStudent(&lista[count]); // pointer
                    count++;
                    printf("Studenti u shtua me sukses!\n");
                } else {
                    printf("Lista eshte plot! Nuk mund te shtosh me.\n");
                }
                break;

            case 2:
                shfaqStudentet();
                break;

            case 0:
                printf("Dalje...\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
        }

    } while (zgjedhja != 0);

    return 0;
}
