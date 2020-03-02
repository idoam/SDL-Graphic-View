#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"
#include "paths.h"

Uint32 reddd =  0xffff0000;
Uint32 blueee = 0xff0000ff;
Uint32 greennn= 0xff00ff00;
Uint32 delayy = 0x00000100;

int basic_path(int array[], int length, int target)
{
    for (int i = 0; i < length; i++)
    {
        fill(0xff000000);
        draw_array(array, length, reddd);
        draw_arrow(array, length, i, greennn);
        display_image();

        if (array[i] == target)
        {
            draw_arrow(array, length, i, blueee);
            display_image();
            return i;
        }
    }
    return -1;
}


int binary_path(int array[], int length, int target)
{
    int lowerBound = 0;
    int upperBound = length -1;
    int midPoint = -1;
    int index = -1;

    while (lowerBound <= upperBound) 
    {
        fill(0xff000000);
        draw_array(array, length, reddd);
        draw_arrow(array, length, lowerBound, greennn);
        draw_arrow(array, length, upperBound, greennn);
        display_image();
        //SDL_Delay(delayy);

        midPoint = lowerBound + (upperBound - lowerBound) / 2;

        if (array[midPoint] == target)
        {
            index = midPoint;
            break;
        }
        else
        {
            if (array[midPoint] < target)
                lowerBound = midPoint + 1;
            else
                upperBound = midPoint - 1;
        }

    }

    fill(0xff000000);
    draw_array(array, length, reddd);
    draw_arrow(array, length, index, blueee);
    display_image();


    return index;
}
