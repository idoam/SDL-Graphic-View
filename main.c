#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "graphics.h"
#include "sorts.h"
#include "paths.h"

int main(void)
{
    create_environment(1200, 800);
    int length = 100;
    int array[length];

    for (int i = 0; i < length; i++)
        array[i] = i;

    basic_path(array, length, 41);
    wait_for_keypressed();
    binary_path(array, length, 41);
/*
    for (int i = 0; i < length; i++)
        array[i] = rand() % length;
    bubble_sort(array, 20);


    for (int i = 0; i < length; i++)
        array[i] = rand() % length;
    insert_sort(array, 20);


    for (int i = 0; i < length; i++)
        array[i] = rand() % length;
    select_sort(array, length);

*/

    wait_for_keypressed();

    destroy_environment();
    return 0;
}
