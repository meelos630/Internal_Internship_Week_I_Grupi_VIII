#include <stdio.h>
#include <string.h>

#define MAX 5

// ===== ENUM =====
enum Status { NEVOJITET_USHTRIM = 1, NE_PROGRES, PERFUNDUAR };

// ===== STRUCT =====
struct Student {
    int id;
    char emri[50];
    double progresi;
    enum Status status;
};

struct Student lista[MAX];
int count = 0;

// ===== UTIL =====
void printStatus(enum Status s) {
    if (s == NEVOJITET_USHTRIM) printf("Nevojitet ushtrim");
    else if (s == NE_PROGRES) printf("Ne progres");
    else printf("Perfunduaar");
}

enum Status zgjedhStatus() {
    int z;
    printf("Status (1-3): ");
    scanf("%d", &z);

    if (z == 1) return NEVOJITET_USHTRIM;
    if (z == 2) return NE_PROGRES;
    if (z == 3) return PERFUNDUAR;
    return NEVOJITET_USHTRIM;
}

// ===== SHTO =====
void shto() {
    if (count >= MAX) {
        printf("Lista eshte plot!\n");
        return;
    }

    printf("\n--- SHTO STUDENT ---\n");

    printf("ID: "); scanf("%d", &lista[count].id);
    printf("Emri: "); scanf("%s", lista[count].emri);
    printf("Progresi: "); scanf("%lf", &lista[count].progresi);

    if (lista[count].progresi < 0 || lista[count].progresi > 100)
        lista[count].progresi = 0;

    lista[count].status = zgjedhStatus();

    count++;
}

// ===== GJEJ INDEX =====
int gjejIndex(int id) {
    for (int i = 0; i < count; i++)
        if (lista[i].id == id)
            return i;
    return -1;
}

// ===== UPDATE =====
void update() {
    int id;
    printf("ID: "); scanf("%d", &id);

    int i = gjejIndex(id);
    if (i == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    printf("Emri i ri: "); scanf("%s", lista[i].emri);
    printf("Progres i ri: "); scanf("%lf", &lista[i].progresi);

    if (lista[i].progresi < 50) lista[i].status = NEVOJITET_USHTRIM;
    else if (lista[i].progresi < 80) lista[i].status = NE_PROGRES;
    else lista[i].status = PERFUNDUAR;
}

// ===== FSHI =====
void fshi() {
    int id;
    printf("ID: "); scanf("%d", &id);

    int i = gjejIndex(id);
    if (i == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    for (int j = i; j < count - 1; j++)
        lista[j] = lista[j + 1];

    count--;
    printf("U fshi!\n");
}

// ===== SHFAQ =====
void shfaq() {
    if (count == 0) {
        printf("Ska te dhena!\n");
        return;
    }

    printf("\n--- LISTA ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d | %s | %.2lf | ",
               lista[i].id,
               lista[i].emri,
               lista[i].progresi);
        printStatus(lista[i].status);
        printf("\n");
    }
}

// ===== RAPORT =====
void raport() {
    if (count == 0) return;

    double sum = 0;
    for (int i = 0; i < count; i++)
        sum += lista[i].progresi;

    printf("\nMesatarja: %.2lf\n", sum / count);
}

// ===== SEARCH =====
void kerko() {
    int id;
    printf("ID: "); scanf("%d", &id);

    int i = gjejIndex(id);
    if (i == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    printf("%s | %.2lf\n", lista[i].emri, lista[i].progresi);
}

// ===== RENDIT =====
void rendit() {
    struct Student temp;

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (lista[j].progresi < lista[j+1].progresi) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }

    printf("U rendit!\n");
}

// ===== MENU =====
void menu() {
    printf("\n===== MENU =====\n");
    printf("1. Shto\n2. Shfaq\n3. Update\n4. Fshi\n");
    printf("5. Kerko\n6. Raport\n7. Rendit\n0. Dil\n");
}

// ===== MAIN =====
int main() {
    int z;

    do {
        menu();
        printf("Zgjedh: ");
        scanf("%d", &z);

        switch(z) {
            case 1: shto(); break;
            case 2: shfaq(); break;
            case 3: update(); break;
            case 4: fshi(); break;
            case 5: kerko(); break;
            case 6: raport(); break;
            case 7: rendit(); break;
        }

    } while (z != 0);

    return 0;
}
