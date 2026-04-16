#include <stdio.h>

int main() {

    int a;
    float b;

    int *ptrA;
    float *ptrB;

    // input
    printf("Enter an integer: ");
    scanf("%d", &a);

    printf("Enter a float: ");
    scanf("%f", &b);

    // pointer marrin adresat
    ptrA = &a;
    ptrB = &b;

    printf("\n--- BEFORE CHANGE ---\n");
    printf("a value: %d\n", a);
    printf("a address: %p\n", ptrA);
    printf("a via pointer: %d\n", *ptrA);

    printf("\nb value: %.2f\n", b);
    printf("b address: %p\n", ptrB);
    printf("b via pointer: %.2f\n", *ptrB);

    // ruaj vlerën e vjetër
    int oldA = a;

    // ndryshim përmes pointer-it
    *ptrA = *ptrA + 10;

    printf("\n--- AFTER CHANGE ---\n");
    printf("New a value: %d\n", a);

    // kontroll me if/else
    if (a > oldA) {
        printf("Value increased\n");
    }
    else if (a < oldA) {
        printf("Value decreased\n");
    }
    else {
        printf("Value stayed the same\n");
    }

    return 0;
}
