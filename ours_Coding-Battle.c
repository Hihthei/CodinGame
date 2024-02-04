/*******
* Read input from STDIN
* Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
* Use: fprintf(stderr, ...);  to output debugging information to stderr.
* ***/
#include <stdlib.h>
#include <stdio.h>
//#include "libisograd.h"

int main()
{
    char* tab = calloc(101, sizeof(char));

    scanf("%s", tab);

    int i = 0, pos_b = -1, pos_c = -1;

    for (int i = 0; i < 101; i++)
    {

        if (tab[i] == 'B')
        {
            if (pos_c == -1)
            {
                printf("NO");
                break;
            }
            pos_b = i;
            printf("pos_b : %d\n", pos_b);

            if (pos_c > 0)
            {
                if((pos_b - pos_c) >= pos_c -1)
                    printf("YES");
                else if((pos_b - pos_c) < pos_c -1)
                printf("NO");
            }   
        }
        else if (tab[i] == 'C')
        {
            pos_c = i;
            printf("pos_c : %d\n", pos_c);
        }
            
    }
    return 0;
}