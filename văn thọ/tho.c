#include<gtk/gtk.h>
#include<stdlib.h>
#include<stdio.h>

void css()
{
    GtkCssProvider*css=gtk_css_provider_new();
    gtk_css_provider_load_from_path(css,"tho.css",NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),GTK_STYLE_PROVIDER(css),GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void main_screen()
{
    GtkWidget *window,*fixed,*calendar;
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    fixed=gtk_fixed_new();
    calendar=gtk_calendar_new();

    gtk_window_set_title(GTK_WINDOW(window),"still a child");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),1400,800);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);

    

    gtk_fixed_put(GTK_FIXED(fixed),calendar,350,100);

    gtk_widget_set_name(calendar,"calendar");
    gtk_widget_set_name(window,"window");

    gtk_container_add(GTK_CONTAINER(window),fixed);

    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    gtk_widget_show_all(window);
}

int main(int argc,char *argv[])
{
    gtk_init(&argc,&argv);
    css();
    main_screen();
    gtk_main();
}
//gcc `pkg-config --cflags gtk+-3.0` -o app tho.c `pkg-config --libs gtk+-3.0`