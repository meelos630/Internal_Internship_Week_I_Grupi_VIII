#include <stdio.h>

int main() {

    int start, end;

    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    // Marrja e input
    printf("Enter start value: ");
    scanf("%d", &start);

    printf("Enter end value: ");
    scanf("%d", &end);

    // Kontrolli i intervalit
    if (start > end) {
        printf("Invalid interval! Start must be <= end.\n");
        return 0;
    }

    // Loop për analizë
    for (int i = start; i <= end; i++) {

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    // Output
    printf("\n--- Interval Analysis ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Total numbers: %d\n", end - start + 1);

    printf("Even numbers: %d\n", evenCount);
    printf("Odd numbers: %d\n", oddCount);

    printf("Sum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("More even numbers\n");
    } else if (oddCount > evenCount) {
        printf("More odd numbers\n");
    } else {
        printf("Equal number of even and odd numbers\n");
    }

    return 0;
}
