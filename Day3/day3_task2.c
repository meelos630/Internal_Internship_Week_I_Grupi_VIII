#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    printf("Jep vleren fillestare: ");
    scanf("%d", &start);

    printf("Jep vleren perfundimtare: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Interval i pavlefshem! Fillimi nuk mund te jete me i madh se fundi.\n");
        return 0;
    }

    int total = end - start + 1;

    for (int i = start; i <= end; i++) {

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } 
        else {
            oddCount++;
            oddSum += i;
        }
    }

    printf("\n--- REZULTATET ---\n");
    printf("Intervali: %d - %d\n", start, end);
    printf("Total numra: %d\n", total);

    printf("Numra çift: %d\n", evenCount);
    printf("Shuma e numrave çift: %d\n", evenSum);

    printf("Numra tek: %d\n", oddCount);
    printf("Shuma e numrave tek: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Ka me shume numra çift.\n");
    } 
    else if (oddCount > evenCount) {
        printf("Ka me shume numra tek.\n");
    } 
    else {
        printf("Numrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}
