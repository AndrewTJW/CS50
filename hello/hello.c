#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string user_name = get_string("Hello, what is your name?: ");
    printf("Hello, %s! Nice to meet you!\n", user_name);
}
