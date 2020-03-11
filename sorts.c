#include <stdlib.h>
#include <stdio.h>
#include "sorts.h"
#include "graphics.h"

void bubble_sort(int array[], int length)
{
    display_image();
    for (int i = 0; i < length; i++)
    {
        for (int k = 0; k < length - i - 1; k++)
        {
            if (array[k] > array[k+1])
            {
                swap(array, k, k+1);
                fill(0xff000000);
                draw_array(array, length);
                display_image();
            }
        }
    }
}

void insert_sort(int array[], int length)
{
    int key, i, j;
    for (i = 1; i < length; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        fill(0xff000000);
        draw_array(array, length);
        display_image();
        array[j + 1] = key;
    }
}


void select_sort(int array[], int length)
{
    int indexMin,i,j;
    for (i = 0; i < length - 1; i++) 
    {
        indexMin = i;
        for (j = i + 1; j < length; j++)
        {
            if (array[j] < array[indexMin])
                indexMin = j;
        }
        if(indexMin != i)
        {
            int temp = array[indexMin];
            array[indexMin] = array[i];
            array[i] = temp;
            fill(0xff000000);
            draw_array(array, length);
            display_image();
        }
    }
}



void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


void display_array(int array[], int length)
{
     for (int i = 0; i < length; i++)
        printf("%3d\n", array[i]);
}
