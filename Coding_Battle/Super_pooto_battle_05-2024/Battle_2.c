#include "Lib.h"

void Battle_2() {
    int N_carte = 0, pts_joueur_1 = 0, pts_joueur_2 = 0, suspense = 0;

    scanf("%d", &N_carte);

    int* carte_joueur_1 = (int*)calloc(N_carte, sizeof(int));
    AssertNew(carte_joueur_1);

    int* carte_joueur_2 = (int*)calloc(N_carte, sizeof(int));
    AssertNew(carte_joueur_2);

    for (int i = 0; i < N_carte; i++)
            scanf("%d ", &carte_joueur_1[i]);

    for (int i = 0; i < N_carte; i++)
            scanf("%d ", &carte_joueur_2[i]);

    for (int i = 0; i < N_carte; i++) {
        if(carte_joueur_1[i] == carte_joueur_2[i]) {
            suspense++;
            continue;
        }

        if(carte_joueur_1[i] > carte_joueur_2[i]) {
            pts_joueur_1 += 1 + suspense;
            suspense = 0;
        }
        else {
            pts_joueur_2 += 1 + suspense;
            suspense = 0;
        }
    }
    
    free(carte_joueur_1);
    free(carte_joueur_2);

    printf("%d %d", pts_joueur_1, pts_joueur_2);
}
