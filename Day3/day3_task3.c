#include <stdio.h>

int main() {
    int start, end;

    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    printf("Jep fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Jep fundin e intervalit: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {

        // Kategoria 1: pjesëtohet me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }

        // Kategoria 2: pjesëtohet me 5 por JO me 3
        else if (i % 5 == 0) {
            sum5 += i;
            count5++;
        }
    }

    printf("\n--- REZULTATET ---\n");

    printf("Numra pjestohet me 3: %d\n", count3);
    printf("Shuma: %d\n", sum3);

    printf("Numra pjestohet me 5 (jo me 3): %d\n", count5);
    printf("Shuma: %d\n", sum5);

    if (sum3 > sum5) {
        printf("Shuma e numrave me 3 eshte me e madhe.\n");
    }
    else if (sum5 > sum3) {
        printf("Shuma e numrave me 5 eshte me e madhe.\n");
    }
    else {
        printf("Shumat jane te barabarta.\n");
    }

    return 0;
}
