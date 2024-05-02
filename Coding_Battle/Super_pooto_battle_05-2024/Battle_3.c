#include "Lib.h"

void Battle_3() {
    int N_carte = 0, pts_joueur_1 = 0, pts_joueur_2 = 0, suspense = 0;

    //__________________________________________________________

    scanf("%d", &N_carte);

    ListInt* carte_joueur_1 = ListInt_create();
    ListInt* carte_joueur_2 = ListInt_create();
    ListInt* carte_tas_1 = ListInt_create();
    ListInt* carte_tas_2 = ListInt_create();

    int tmp = 0;

    for (int i = 0; i < N_carte; i++) {
        scanf("%d", &tmp);
        ListInt_insertLast(carte_joueur_1, tmp);
    }

    for (int i = 0; i < N_carte; i++) {
        scanf("%d", &tmp);
        ListInt_insertLast(carte_joueur_2, tmp);
    }
    
    //__________________________________________________________

    while(!ListInt_isEmpty(carte_joueur_1) || !ListInt_isEmpty(carte_joueur_2)) {
        int a = ListInt_popFirst(carte_joueur_1),
            b = ListInt_popFirst(carte_joueur_2);

        if(a == b) {
            suspense++;
            ListInt_insertLast(carte_tas_1, a);
            ListInt_insertLast(carte_tas_2, b);
        }
        else if(a > b) {
            pts_joueur_1 += 1 + suspense;

            ListInt_concatenate(carte_tas_1, carte_tas_2);
            ListInt_concatenate(carte_joueur_1, carte_tas_1);
            
            suspense = 0;
        }
        else {
            pts_joueur_2 += 1 + suspense;

            ListInt_concatenate(carte_tas_2, carte_tas_1);
            ListInt_concatenate(carte_joueur_2, carte_tas_2);

            suspense = 0;
        }
    }
    
    ListInt_destroy(carte_joueur_1);
    ListInt_destroy(carte_joueur_2);
    ListInt_destroy(carte_tas_1);
    ListInt_destroy(carte_tas_2);

    printf("%d %d", pts_joueur_1, pts_joueur_2);
}