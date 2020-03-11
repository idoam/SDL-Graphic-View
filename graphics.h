#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL/SDL.h>


SDL_Surface *create_environment(int width, int height);
void destroy_environment();
void wait_for_keypressed();
void display_image();
void set_pixel(int x, int y, Uint32 pixel);
Uint32 get_pixel(int x, int y);
void draw_row(int i, int h, int l, Uint32 color);
void draw_array(int array[], int length);
int array_max(int array[], int length);
void fill(Uint32 color);
void draw_arrow(int array[], int length, int index, Uint32 color);


#endif
