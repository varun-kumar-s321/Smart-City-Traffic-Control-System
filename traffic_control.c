#include <stdio.h>
#include <unistd.h>   // for sleep()

int getTrafficDensity()
{
    int density;
    // Simulated sensor input
    printf("Enter traffic density (0-Low, 1-Medium, 2-High): ");
    scanf("%d", &density);
    return density;
}

int main()
{
    int road = 1;
    int density, green_time;

    while (1)
    {
        printf("\n==============================");
        printf("\nROAD %d", road);

        density = getTrafficDensity();

        if (density == 2)
            green_time = 10;   // High traffic
        else if (density == 1)
            green_time = 6;    // Medium traffic
        else
            green_time = 4;    // Low traffic

        printf("\nGREEN  - GO (%d sec)", green_time);
        sleep(green_time);

        printf("\nYELLOW - READY (2 sec)");
        sleep(2);

        printf("\nRED    - STOP (2 sec)");
        sleep(2);

        // Circular road change
        road++;
        if (road > 4)
            road = 1;
    }

    return 0;
}
