#include "Lib.h"

char** Alloc_mat(int a, int b) {
    if(a == 0 || b ==0)
        return NULL;

    char** mat = (char**)calloc(a, sizeof(char*));
    AssertNew(mat);

    for (int i = 0; i < a; i++) {
        mat[i] = (char*)calloc(b, sizeof(char));
        AssertNew(mat);
    }
    
    return mat;
}

void Affiche_mat(char** mat, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void River_1() {
    int a = 0, b = 0;

    FILE* pfile = fopen("source.txt", "r");
    AssertNew(pfile);

    fscanf(pfile, "%d %d", &a, &b);

    char** mat = Alloc_mat(a, b+1);

    for (int i = 0; i < a; i++) {
        fscanf(pfile, "%s", mat[i]);
    }

    //Affiche_mat(mat, a, b);

    int shortest_path = b, tmp = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if(mat[i][j] == '.')
                tmp++;
        }
        if(tmp < shortest_path)
            shortest_path = tmp;

        tmp = 0;
    }

    free(mat);
    printf("%d", shortest_path * shortest_path);
}