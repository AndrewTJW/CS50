#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
int n1;
do
{
    n1 = get_int("Positive integer (More than 9): ");
}
while (n1 < 9);
    // TODO: Prompt for end size
int n2;
do
{
    n2 = get_int("Positive integer (More than the value you've typed in recently): ");
}
while (n2 < n1);
    // TODO: Calculate number of years until we reach threshold
int years = 0;
while (n1 < n2)
{
    n1 = n1 + (n1 / 3) - (n1 / 4);
    years += 1;
}
    // TODO: Print number of years
printf("Years taken: %i\n ", years);
}
