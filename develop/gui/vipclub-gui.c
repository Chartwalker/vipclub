#include <gtk/gtk.h>
#include "vipclub-gui.h"

GtkWidget *window,*table,*entry;

GdkPixbuf *about_logo;

about_logo = gdk_pixbuf_new_from_file ("./logo.png", NULL);
gtk_show_about_dialog (NULL,
                       "VIP-Club", "Code",
                       "logo", about_logo,
                       "title", _("About Code"),
                       NULL);

/* initialize widget pointers */

table = gtk_table_new(5, 4, TRUE);
entry = gtk_entry_new();
about_logo = gdk_pixbuf_new_from_file ("./logo.png", NULL);

/* packing for take off */
gtk_container_add(GTK_CONTAINER(window), table);

/*set atrributes */
gtk_entry_set_alignment(GTK_ENTRY(entry), 1);
gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);
gtk_table_attach_defaults(GTK_TABLE(table), entry, 0, 4, 0, 1);
 
int main (int argc, char *argv[])
{
    GtkWidget *window;
 
    gtk_init (&argc, &argv);
 
    /* gui main window´ */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "VIP-Club");
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
 
    gtk_widget_show_all(window);
    gtk_main();
 
    return 0;
}