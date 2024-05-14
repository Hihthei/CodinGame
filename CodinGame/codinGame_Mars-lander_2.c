#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // the number of points used to draw the surface of Mars.
    int surface_n = 0,
        plat_x = 0,
        plat_y = 0;
    scanf("%d", &surface_n);

    int* coord = (int*)calloc(surface_n, sizeof(int));

    for (int i = 0; i < surface_n; i++) {
        // X coordinate of a surface point. (0 to 6999)
        int land_x;
        // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        int land_y;
        scanf("%d%d", &land_x, &land_y);
        coord[i] = land_y;
        if (coord[i] == coord[i-1] && i > 0) {
            plat_x = land_x - 500;
            plat_y = land_y;
        }
    }

    free(coord);

    int target_rotate = 0,
        target_power = 0;

    // game loop
    while (1) {
        int X = 0, Y = 0;
        // the horizontal speed (in m/s), can be negative.
        int h_speed = 0;
        // the vertical speed (in m/s), can be negative.
        int v_speed = 0;
        // the quantity of remaining fuel in liters.
        int fuel = 0;
        // the rotation angle in degrees (-90 to 90).
        int rotate = 0;
        // the thrust power (0 to 4).
        int power = 0;
        scanf("%d%d%d%d%d%d%d", &X, &Y, &h_speed, &v_speed, &fuel, &rotate, &power);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        if (X > plat_x - 100 && X < plat_x + 100) {
            // Lander is over the platform
            target_rotate = (h_speed > -10 && h_speed < 10) ? 0 : target_rotate; // Keep the Lander horizontal
            target_power = (v_speed < 40) ? 3 : 4; // Adjust power based on vertical speed
        } else if (X < plat_x) {
            // Lander is to the left of the platform
            target_rotate -= (target_rotate > -45) ? 15 : 0; // Rotate left
            target_power = 4; // Use maximum power
        } else if (X > plat_x) {
            // Lander is to the right of the platform
            target_rotate += (target_rotate < 45) ? 15 : 0; // Rotate right
            target_power = 4; // Use maximum power
        }

        

        // Output
        printf("%d %d\n", target_rotate, target_power);
    }

    return 0;
}
