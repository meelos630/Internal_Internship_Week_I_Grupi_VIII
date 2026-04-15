#include <stdio.h>

int main() {
    int age = 16;
    char initial = 'J';
    float height = 1.71;
    double average = 3.0;
    short year = 2026;
    long population = 1800000;

    printf("\n--- PROFILI JUAJ ---\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %.2f m\n", height);
    printf("Mesatarja: %.2lf\n", average);
    printf("Viti (short): %hd\n", year);
    printf("Popullsia (long): %ld\n", population);

    return 0;
}
