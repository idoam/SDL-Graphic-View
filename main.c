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
GtkSwitch  *insert_switch;
GtkSwitch  *select_switch;
GtkSwitch  *basic_switch;
GtkSwitch  *binary_switch;
GtkSwitch  *show_steps_switch;

GtkButton  *launch_button;

GtkSpinButton *bubble_iterations;
GtkSpinButton *insert_iterations;
GtkSpinButton *select_iterations;
GtkSpinButton *basic_iterations;
GtkSpinButton *binary_iterations;

void launch_graphics();

int main(void)
{
    gtk_init(NULL, NULL);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "graphics.glade", NULL);
    gtk_builder_connect_signals(builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    bubble_switch = GTK_SWITCH(gtk_builder_get_object(builder, "bubbleSwitch"));
    insert_switch = GTK_SWITCH(gtk_builder_get_object(builder, "insertSwitch"));
    select_switch = GTK_SWITCH(gtk_builder_get_object(builder, "selectSwitch"));
    basic_switch = GTK_SWITCH(gtk_builder_get_object(builder, "basicSwitch"));
    binary_switch = GTK_SWITCH(gtk_builder_get_object(builder, "binarySwitch"));
    show_steps_switch = GTK_SWITCH(gtk_builder_get_object(builder, "showSteps"));

    bubble_iterations = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "bubbleIte"));
    insert_iterations = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "insertIte"));
    select_iterations = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "selectIte"));
    basic_iterations = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "basicIte"));
    binary_iterations = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "binaryIte"));

    launch_button = GTK_BUTTON(gtk_builder_get_object(builder, "launchButton"));

    g_object_unref(builder);
    gtk_widget_show(window);
    launch_graphics();

    gtk_main();

    return 0;
}


void on_window_destroy()
{
    gtk_main_quit();
}

void launch_graphics()
{
    gboolean show_bubble = gtk_switch_get_active(bubble_switch);
    gboolean show_insert = gtk_switch_get_active(insert_switch);
    gboolean show_select = gtk_switch_get_active(select_switch);

    gboolean show_basic = gtk_switch_get_active(basic_switch);
    gboolean show_binary = gtk_switch_get_active(binary_switch);

    int length = 200;
    int array[length];
    int iterations;

    if (show_bubble)
    {
        iterations = (int)gtk_spin_button_get_value(bubble_iterations);
        create_environment((iterations * 6) * (int)(200/iterations), (iterations * 4) * (int)(200/iterations));

        for (int i = 0; i < length; i++)
            array[i] = rand() % length;
        bubble_sort(array, iterations);
        wait_for_keypressed();

        destroy_environment();
    }

    if (show_insert)
    {
        iterations = (int)gtk_spin_button_get_value(insert_iterations);
        create_environment((iterations * 6) * (int)(200/iterations), (iterations * 4) * (int)(200/iterations));

        for (int i = 0; i < length; i++)
            array[i] = rand() % length;
        insert_sort(array, iterations);
        wait_for_keypressed();

        destroy_environment();
    }

    if (show_select)
    {
        iterations = (int)gtk_spin_button_get_value(select_iterations);
        create_environment((iterations * 6) * (int)(200/iterations), (iterations * 4) * (int)(200/iterations));

        for (int i = 0; i < length; i++)
            array[i] = rand() % length;
        select_sort(array, iterations);
        wait_for_keypressed();

        destroy_environment();
    }

    if (show_basic)
    {
        iterations = (int)gtk_spin_button_get_value(basic_iterations);
        create_environment((iterations * 6) * (int)(200/iterations), (iterations * 4) * (int)(200/iterations));

        for (int i = 0; i < length; i++)
            array[i] = i;
        basic_path(array, iterations, (rand() % (iterations - 3)) + 3);
        wait_for_keypressed();

        destroy_environment();
    }

    if (show_binary)
    {
        iterations = (int)gtk_spin_button_get_value(binary_iterations);
        gboolean show_steps = gtk_switch_get_active(show_steps_switch);

        create_environment((iterations * 6) * (int)(200/iterations), (iterations * 4) * (int)(200/iterations));

        for (int i = 0; i < length; i++)
            array[i] = i;
        if (show_steps)
            binary_path(array, iterations, (rand() % (iterations - 3)) + 3, 1);
        else
            binary_path(array, iterations, (rand() % (iterations - 6)) + 3, 0);

        wait_for_keypressed();

        destroy_environment();
    }

}
