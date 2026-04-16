#include <stdio.h>

int main() {
    int a;
    float b;

    int *pA;
    float *pB;

    printf("Shkruaj nje vlere per int (a): ");
    scanf("%d", &a);

    printf("Shkruaj nje vlere per float (b): ");
    scanf("%f", &b);

    // Lidhja e pointerave me adresat
    pA = &a;
    pB = &b;

    printf("\n--- Vlerat fillestare ---\n");
    printf("a = %d\n", a);
    printf("Adresa e a = %p\n", &a);
    printf("Vlera e a permes pointer (*pA) = %d\n", *pA);

    printf("\nb = %.2f\n", b);
    printf("Adresa e b = %p\n", &b);
    printf("Vlera e b permes pointer (*pB) = %.2f\n", *pB);

    // Ruaj vleren e vjeter për krahasim
    int a_old = a;

    // Ndryshimi i vlerës përmes pointer-it
    *pA = *pA + 10;

    printf("\n--- Ndryshimi i vleres se a permes pointer ---\n");
    printf("Para ndryshimit: %d\n", a_old);
    printf("Pas ndryshimit: %d\n", a);

    // Kontroll me if/else
    printf("\n--- Rezultati ---\n");

    if (a > a_old) {
        printf("Vlera eshte rritur.\n");
    } else if (a < a_old) {
        printf("Vlera eshte zvogeluar.\n");
    } else {
        printf("Vlera ka mbetur e njejte.\n");
    }

    // Kontroll intervali
    if (a >= 0 && a <= 100) {
        printf("Vlera eshte brenda intervalit [0, 100].\n");
    } else {
        printf("Vlera eshte jashte intervalit [0, 100].\n");
    }

    return 0;
}
