#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompting the user for a positive integer
    int height, x, y, space;
    do
    {
        height = get_int("Size for your block: ");
    }
    while (height < 1 || height > 8);

    // building the bricks
    for (y = 0; y < height; y += 1)
    {
        // adding the spaces (RELATIONSHIP: space = height - row - 1)
        for (space = 0; space < height - x - 1; space += 1)
        {
            printf(" ");
        }
        for (x = 0; x <= y; x += 1)
        {
            printf("#");
        }
        printf("\n");
    }
}