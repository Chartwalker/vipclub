#include "vipclub-gui.h"
#include <glib.h>

#include <gtk/gtk.h>

 gint color;

 GtkWidget *image[4];
 GtkWidget *window;
 GtkWidget *list;
 GtkWidget *button;

 gint color = 0;
 gint color_max=2;
 gint color_min=0;

static void cb_print_inc (GtkWidget *widget,gpointer data){
 g_print ("%s=image[%i]=%p<-%p\n",(char*)data,color,image[0],image[color]);
 
 if (color<color_max) color++; else color=color_min;
 image[0]=image[color];

}

static void cb_print_dec (GtkWidget *widget,gpointer data){
 g_print ("%s=image[%i]=%p<-%p\n",(char*)data,color,image[0],image[color]);

 if (color>color_min) color--; else color=color_max;
 image[0]=image[color];

}

static gboolean cb_expose_event (GtkWidget *widget, GdkEventExpose * event, gpointer data){
 g_print ("%s=image[%i]=%p<-%p\n",(char*)data,color,image[0],image[color]);

 if (color>color_min) color--; else color=color_max;
 image[0]=image[color];

}


int main (int argc, char *argv[])
{
  
 gtk_init (&argc, &argv);
 window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title (GTK_WINDOW (window), "LED-Test");
 
 g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
 gtk_container_set_border_width (GTK_CONTAINER (window), 10);
 
 list = gtk_list_box_new ();
 gtk_container_add (GTK_CONTAINER (window), list);
 
 button = gtk_button_new_with_label ("prev color");
 g_signal_connect (button, "clicked", G_CALLBACK (cb_print_dec), "prev color");
 gtk_list_box_insert (GTK_LIST_BOX (list), button,0);
 
 button = gtk_button_new_with_label ("next color");
 g_signal_connect (button, "clicked", G_CALLBACK (cb_print_inc), "next color");
 gtk_list_box_insert (GTK_LIST_BOX (list), button,1);
 
 button = gtk_button_new_with_label ("Quit");
 g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
 gtk_list_box_insert (GTK_LIST_BOX (list), button,2);


 image[0] = gtk_image_new_from_file ("led_gray.jpg");
 image[1] = gtk_image_new_from_file ("led_red.jpg");
 image[2] = gtk_image_new_from_file ("led_green.jpg");
 image[3] = gtk_image_new_from_file ("led_blue.jpg");

 g_signal_connect (G_OBJECT (image[0]), "expose_event",
 G_CALLBACK (cb_expose_event), NULL);

 gtk_list_box_insert (GTK_LIST_BOX (list), image[0],3);
 gtk_widget_show_all (window);
 gtk_main ();
 return 0;
}
