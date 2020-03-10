#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "graphics.h"
#include "sorts.h"
#include "paths.h"
#include <gtk/gtk.h>

GtkWidget  *window;
GtkBuilder *builder;
GtkSwitch  *bubble_switch;
GtkButton  *launch_button;


void launch_graphics();

int main(void)
{
    gtk_init(NULL, NULL);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "graphics.glade", NULL);
    gtk_builder_connect_signals(builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    bubble_switch = GTK_SWITCH(gtk_builder_get_object(builder, "bubbleSwitch"));
    launch_button = GTK_BUTTON(gtk_builder_get_object(builder, "launchButton"));

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();

    return 0;
}


void on_window_destroy()
{
    gtk_main_quit();
}

void launch_graphics()
{
    create_environment(1200, 800);
    int length = 100;
    int array[length];

    for (int i = 0; i < length; i++)
        array[i] = i;

    basic_path(array, length, 41);
    wait_for_keypressed();
    binary_path(array, length, 41);
    wait_for_keypressed();

    for (int i = 0; i < length; i++)
        array[i] = rand() % length;
    bubble_sort(array, 20);
    wait_for_keypressed();


    for (int i = 0; i < length; i++)
        array[i] = rand() % length;
    insert_sort(array, 20);

    wait_for_keypressed();

    for (int i = 0; i < length; i++)
        array[i] = rand() % length;
    select_sort(array, length);

    wait_for_keypressed();

    destroy_environment();

}
