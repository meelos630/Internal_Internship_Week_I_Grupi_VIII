#include <stdio.h>

int main() {
    int a;
    double b;

    int *pa = &a;
    double *pb = &b;

    printf("Jep nje vlere int: ");
    scanf("%d", &a);

    printf("Jep nje vlere double: ");
    scanf("%lf", &b);

    printf("\n--- PARA NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("adres e a = %p\n", &a);
    printf("vlera nga pointeri pa = %d\n", *pa);

    printf("b = %lf\n", b);
    printf("adres e b = %p\n", &b);
    printf("vlera nga pointeri pb = %lf\n", *pb);

    // ndryshimi përmes pointerit
    *pa = a + 10;
    *pb = b * 2;

    printf("\n--- PAS NDRYSHIMIT ---\n");
    printf("a = %d\n", a);
    printf("b = %lf\n", b);

    printf("\n--- ANALIZA ---\n");

    if (*pa > 20) {
        printf("Vlera e a eshte e madhe.\n");
    } 
    else if (*pa > 0) {
        printf("Vlera e a eshte pozitive dhe normale.\n");
    } 
    else {
        printf("Vlera e a eshte zero ose negative.\n");
    }

    if (*pb > 50.0) {
        printf("Vlera e b eshte shume e madhe.\n");
    } 
    else if (*pb > 0) {
        printf("Vlera e b eshte pozitive.\n");
    } 
    else {
        printf("Vlera e b eshte zero ose negative.\n");
    }

    return 0;
}
