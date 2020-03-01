#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "graphics.h"
#include "sorts.h"


//               a-r-g-b-
Uint32 red   = 0xffff0000;
Uint32 green = 0xff00ff00;
Uint32 blue  = 0xff0000ff;
Uint32 white = 0xffffffff;
Uint32 black = 0xff000000;

SDL_Surface *surface;

SDL_Surface *create_environment(int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    return surface;
}


void destroy_environment()
{
    SDL_FreeSurface(surface);
    SDL_Quit();
}


void wait_for_keypressed()
{
    SDL_Event event;
    do {
        SDL_PollEvent(&event);
    } while (event.type != SDL_KEYDOWN);
}


void display_image()
{
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(surface->w, surface->h, 0, SDL_SWSURFACE
            |SDL_ANYFORMAT);


    SDL_BlitSurface(surface, NULL, screen, NULL);
    SDL_UpdateRect(screen, 0, 0, surface->w, surface->h);
}


void set_pixel(int x, int y, Uint32 pixel)
{
    if (x >= surface->w || x < 0 || y >= surface->h || y < 0)
    {
        printf("access pixel refund -> x:%d y:%d\n", x, y);
        return;
    }

    int bpp = surface->format->	BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

Uint32 get_pixel(int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;
    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;
    }
}


void draw_row(int i, int h, int l, Uint32 color)
{
    for (int n = surface->h - 1; n >= surface->h - h; n--)
    {
        for (int k = 0; k < l; k++)
            set_pixel(i + k, n, color);
    }
}


void draw_array(int array[], 
        int length, Uint32 color)
{
    int max = array_max(array, length);
    int v = surface->h / max;
    int l = surface->w / (length);
    for (int i = 0; i < length; i += 1)
        draw_row(i * l + 2, array[i] * v - 6, l - 4, color);
}


int array_max(int array[], int length)
{
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

void fill(Uint32 color)
{
    for (int i = 1; i < surface->w; i++)
    {
        for (int j = 1; j < surface->h; j++)
            set_pixel(i, j, color);
    }
}
