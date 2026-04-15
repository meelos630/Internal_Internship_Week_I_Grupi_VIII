#include <stdio.h>

int main() {
    // Deklarimi i variablave të tipeve të ndryshme
    int age = 16;              // mosha (numër i plotë)
    char initial = 'I';        // iniciali (karakter)
    float height = 1.80;      // gjatësia (numër me presje)
    double average = 4.5;     // mesatarja (më e saktë se float)

    // Variabla shtesë të kërkuara në detyrë
    short smallNumber = 10;   // numër i vogël
    long bigNumber = 100000; // numër i madh

    // Shfaqja e të dhënave në ekran
    printf("\n--- Student Profile ---\n");

    printf("Age: %d\n", age);               // shfaq moshën
    printf("Initial: %c\n", initial);       // shfaq inicialin
    printf("Height: %.2f\n", height);      // shfaq gjatësinë me 2 shifra pas presjes
    printf("Average: %.2lf\n", average);   // shfaq mesataren
    printf("Short value: %d\n", smallNumber); // shfaq short
    printf("Long value: %ld\n", bigNumber);   // shfaq long

    return 0; // përfundon programi
}

