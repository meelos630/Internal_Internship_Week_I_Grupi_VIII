#include <stdio.h>

int main() {

    // Deklarimi i variablave me tipe te ndryshme
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;

    short numriFatit = 7;    // vlere e vendosur direkt
    long numriMadh = 123456; // vlere e vendosur direkt

    // Marrja e input nga perdoruesi
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali); // hapesira shmang probleme me input

    printf("Shkruaj gjatesine (ne metra): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    // Shfaqja e te dhenave qe useri i ka shkruajtur
    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f metra\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);

    // Shfaqja e vlerave shtese pa kerkese qe useri ti shenoje
    printf("Numri i fatit (short): %d\n", numriFatit);
    printf("Numri i madh (long): %ld\n", numriMadh);

    return 0;
}
