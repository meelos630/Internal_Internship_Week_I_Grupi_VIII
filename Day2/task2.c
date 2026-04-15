#include <stdio.h>

int main() {

    int score = 78;  

    if (score < 0 || score > 100) {
        printf("Invalid input!\n");
    }
    else if (score >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Shume mire\n");
    }
    else if (score >= 50) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
