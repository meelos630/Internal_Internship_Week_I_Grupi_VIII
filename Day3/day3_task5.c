#include <stdio.h>

// enum me 4 vlera
enum Niveli {
    FILLESTAR = 1,
    MESATAR,
    I_AVANCUAR,
    EKSPERT
};

int main() {
    int zgjedhja;
    int valid = 0, invalid = 0;

    // loop për 3 raste
    for (int i = 1; i <= 3; i++) {
        printf("\nRasti %d\n", i);
        printf("Zgjedh nivelin (1-4): ");
        scanf("%d", &zgjedhja);

        switch(zgjedhja) {
            case FILLESTAR:
                printf("Niveli: Fillestar - duhet me ushtru me shume.\n");
                valid++;
                break;

            case MESATAR:
                printf("Niveli: Mesatar - je ne rruge te mire.\n");
                valid++;
                break;

            case I_AVANCUAR:
                printf("Niveli: I avancuar - shume mire.\n");
                valid++;
                break;

            case EKSPERT:
                printf("Niveli: Ekspert - super nivel!\n");
                valid++;
                break;

            default:
                printf("Input i pavlefshem!\n");
                invalid++;
        }
    }

    // statistikat
    printf("\n--- STATISTIKAT ---\n");
    printf("Zgjedhje valide: %d\n", valid);
    printf("Zgjedhje pavlefshme: %d\n", invalid);

    return 0;
}
