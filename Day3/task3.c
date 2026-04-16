#include <stdio.h>

int main() {

    int start, end;

    int sum3 = 0, count3 = 0;
    int sum5 = 0, count5 = 0;

    printf("Enter start value: ");
    scanf("%d", &start);

    printf("Enter end value: ");
    scanf("%d", &end);

    // kontrolli i intervalit
    if (start > end) {
        printf("Invalid interval!\n");
        return 0;
    }

    for (int i = start; i <= end; i++) {

        // pjesëtohet me 3
        if (i % 3 == 0) {
            sum3 += i;
            count3++;
        }

        // pjesëtohet me 5 POR JO me 3
        else if (i % 5 == 0) {
            sum5 += i;
            count5++;
        }
    }

    printf("\n--- Results ---\n");

    printf("Divisible by 3 -> Count: %d, Sum: %d\n", count3, sum3);
    printf("Divisible by 5 (not 3) -> Count: %d, Sum: %d\n", count5, sum5);

    if (sum3 > sum5) {
        printf("Category 3 has larger sum\n");
    }
    else if (sum5 > sum3) {
        printf("Category 5 has larger sum\n");
    }
    else {
        printf("Both categories are equal\n");
    }

    return 0;
}
