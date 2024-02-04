#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int tmp = 0, min = 5527, temp = 0, n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        tmp = temp;

        if(tmp < 0)
        {
            tmp *= -1;

            if(tmp < min)
                min = temp;
        }
        else if(tmp < min)
            min = temp;
    }

    printf("%d\n", min);

    return 0;
}