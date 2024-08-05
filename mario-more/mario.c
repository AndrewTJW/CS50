#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for size
    int height, verticle, horizontal, space;
    do
    {
        height = get_int("Height of obstacle: ");
    }
    while (height < 1 || height > 8);

    // building the bricks
    for (verticle = 0; verticle < height; verticle += 1)
    {
        for (space = 0; space < height - horizontal - 1; space += 1)
        {
            printf(" ");
        }
        for (horizontal = 0; horizontal <= verticle; horizontal += 1)
        {
            printf("#");
        }
        printf("  ");
        for (horizontal = 0; horizontal <= verticle; horizontal += 1)
        {
            printf("#");
        }
        printf("\n");
    }
}