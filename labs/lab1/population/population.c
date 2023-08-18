#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int years_passed = 0, start_size, end_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    if (end_size == start_size)
    {
        printf("Years: %i\n", years_passed);
    }
    else
    {

        do
        {
            start_size = start_size + (start_size / 3) - (start_size / 4);
            years_passed++;
        }
        while (start_size < end_size);
        printf("Years: %i\n", years_passed);
    }
}
