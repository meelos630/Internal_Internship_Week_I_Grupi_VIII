#include <stdio.h>

int main() {

    int mosha, opsioni;
    char iniciali;
    double pike;

    // Marrja e input-it
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj pike paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjidh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    if (mosha < 10) {
        printf("\nNuk lejohet pjesemarrja (mosha shume e ulet).\n");
    } else if (mosha > 18) {
        printf("\nNuk lejohet pjesemarrja (mosha shume e madhe).\n");
    } else {
        printf("\nMosha eshte e pranueshme.\n");
    }

    // Klasifikimi sipas pikeve
    if (pike < 50) {
        printf("Vleresimi: Nevojitet me shume ushtrim\n");
    } else if (pike < 80) {
        printf("Vleresimi: Gati per vazhdim\n");
    } else {
        printf("Vleresimi: Gati per sfide\n");
    }

    // Zgjedhja e punetorise me switch
    printf("Punetoria e zgjedhur: ");

    switch (opsioni) {
        case 1:
            printf("Programim bazik\n");
            break;
        case 2:
            printf("Algoritme\n");
            break;
        case 3:
            printf("Struktura te dhenash\n");
            break;
        default:
            printf("Opsion jo valid\n");
            break;
    }

    // Permbledhja finale
    printf("\n--- Permbledhje ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Pike: %.2lf\n", pike);
    printf("Opsioni: %d\n", opsioni);

    return 0;
}
