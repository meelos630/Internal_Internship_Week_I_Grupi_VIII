#include <stdio.h>

int main() {
    int start, end;

    // Input
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    // Validimi
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 0;
    }

    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Loop
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int total = end - start + 1;

    // Output
    printf("\n--- Rezultatet ---\n");
    printf("Intervali: %d deri %d\n", start, end);
    printf("Totali i numrave: %d\n", total);

    printf("\nNumrat çift:\n");
    printf("Numerimi: %d\n", evenCount);
    printf("Shuma: %d\n", evenSum);

    printf("\nNumrat tek:\n");
    printf("Numerimi: %d\n", oddCount);
    printf("Shuma: %d\n", oddSum);

    // Krahasimi
    printf("\n--- Krahasimi ---\n");
    if (evenCount > oddCount) {
        printf("Ka me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("Ka me shume numra tek.\n");
    } else {
        printf("Numrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}
