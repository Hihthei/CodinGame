#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fonction de comparaison pour la fonction qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int* powers = (int*)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &powers[i]);
    }

    // Trier les puissances par ordre croissant
    qsort(powers, N, sizeof(int), compare);

    // Trouver la différence minimale
    int min_diff = powers[1] - powers[0];
    for (int i = 2; i < N; i++) {
        int diff = powers[i] - powers[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    printf("%d\n", min_diff);

    free(powers);

    return 0;
}
