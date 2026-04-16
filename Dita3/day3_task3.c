#include <stdio.h>

int main() {
    int fillimi, fundi;
    int shuma3 = 0, numruesi3 = 0;
    int shuma5 = 0, numruesi5 = 0;

    // Marrja e input-it nga përdoruesi
    printf("Jepni fillimin e intervalit: ");
    scanf("%d", &fillimi);
    printf("Jepni fundin e intervalit: ");
    scanf("%d", &fundi);

    // Trajtimi i input-it të pavlefshëm (nëse fillimi > fundi)
    if (fillimi > fundi) {
        printf("Gabim: Fillimi i intervalit duhet te jete me i vogel se fundi.\n");
        return 1;
    }

    // Përdorimi i for loop për të kontrolluar çdo numër
    for (int i = fillimi; i <= fundi; i++) {
        // Kategoria 1: Numrat që pjesëtohen me 3
        if (i % 3 == 0) {
            shuma3 += i;
            numruesi3++;
        } 
        // Kategoria 2: Numrat që pjesëtohen me 5 por jo me 3
        else if (i % 5 == 0) {
            shuma5 += i;
            numruesi5++;
        }
    }

    // Shfaqja e rezultateve
    printf("\n--- Rezultatet ---\n");
    printf("Kategoria (pjesetohen me 3): Shuma = %d, Sa numra = %d\n", shuma3, numruesi3);
    printf("Kategoria (pjesetohen me 5, jo 3): Shuma = %d, Sa numra = %d\n", shuma5, numruesi5);

    // Krahasimi i shumave
    if (shuma3 > shuma5) {
        printf("Rezultati: Shuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (shuma5 > shuma3) {
        printf("Rezultati: Shuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    } else {
        printf("Rezultati: Te dyja shumat jane te barabarta.\n");
    }

    return 0;
}
