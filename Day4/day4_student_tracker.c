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
    printf("\n1. Nevojitet ushtrim\n2. Ne progres\n3. Perfunduaar\nZgjedh: ");
    scanf("%d", &z);

    switch(z) {
        case 1: return NEVOJITET_USHTRIM;
        case 2: return NE_PROGRES;
        case 3: return PERFUNDUAR;
        default: return NEVOJITET_USHTRIM;
    }
}

// ================= SHTO =================
void shtoStudent(struct Student *s) {
    printf("\nID: "); scanf("%d", &s->id);
    printf("Emri: "); scanf("%s", s->emri);
    printf("Progresi: "); scanf("%lf", &s->progresi);

    if (s->progresi < 0 || s->progresi > 100)
        s->progresi = 0;

    s->status = zgjedhStatus();
}

// ================= UPDATE (POINTER) =================
void updateStudent(struct Student *s) {
    printf("\nNdrysho emrin: ");
    scanf("%s", s->emri);

    printf("Ndrysho progresin: ");
    scanf("%lf", &s->progresi);

    if (s->progresi < 50) s->status = NEVOJITET_USHTRIM;
    else if (s->progresi < 80) s->status = NE_PROGRES;
    else s->status = PERFUNDUAR;

    printf("U perditesua!\n");
}

// ================= FSHI =================
void fshiStudent() {
    int id, found = 0;
    printf("\nID per fshirje: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lista[i].id == id) {
            // zhvendos elementet
            for (int j = i; j < count - 1; j++) {
                lista[j] = lista[j + 1];
            }
            count--; // zvogëlo count
            printf("U fshi me sukses!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Nuk u gjet!\n");
}

// ================= SEARCH =================
void kerkoStudent() {
    int id, found = 0;
    printf("\nID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (lista[i].id == id) {
            printf("Emri: %s | Progresi: %.2lf\n",
                   lista[i].emri, lista[i].progresi);

            if (lista[i].progresi < 50)
                printf("Rrezik!\n");
            else if (lista[i].progresi >= 80)
                printf("Shume mire!\n");

            found = 1;
        }
    }

    if (!found)
        printf("Nuk u gjet!\n");
}

// ================= SHFAQ =================
void shfaq() {
    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d | %s | %.2lf\n",
               lista[i].id,
               lista[i].emri,
               lista[i].progresi);
    }
}

// ================= RAPORT =================
void raport() {
    if (count == 0) return;

    double sum = 0;
    for (int i = 0; i < count; i++)
        sum += lista[i].progresi;

    printf("Mesatarja: %.2lf\n", sum / count);
}

// ================= RENDIT =================
void rendit() {
    struct Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lista[j].progresi < lista[j+1].progresi) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    printf("\n--- Renditje ---\n");
    shfaq();
}

// ================= MAIN =================
int main() {
    int z;

    do {
        printf("\nMENU\n");
        printf("1. Shto\n");
        printf("2. Shfaq\n");
        printf("3. Update\n");
        printf("4. Fshi\n");
        printf("5. Kerko\n");
        printf("6. Raport\n");
        printf("7. Rendit\n");
        printf("0. Dil\n");
        printf("Zgjedh: ");
        scanf("%d", &z);

        switch(z) {
            case 1:
                if (count < MAX) {
                    shtoStudent(&lista[count]);
                    count++;
                } else printf("Plot!\n");
                break;

            case 2: shfaq(); break;

            case 3: {
                int id, found = 0;
                printf("ID: "); scanf("%d", &id);
                for (int i = 0; i < count; i++) {
                    if (lista[i].id == id) {
                        updateStudent(&lista[i]);
                        found = 1;
                    }
                }
                if (!found) printf("Nuk u gjet!\n");
                break;
            }

            case 4: fshiStudent(); break;
            case 5: kerkoStudent(); break;
            case 6: raport(); break;
            case 7: rendit(); break;

        }

    } while (z != 0);

    return 0;
}
