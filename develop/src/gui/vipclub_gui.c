#include <vipclub/config.h>
#include <vipclub/vipclub-gui.h>
#include <gtk/gtk.h>

static gint delete_Event(GtkWidget * Widget_p, GdkEvent Event_p, gpointer Data_p){
#ifdef __TSC_PRJG_LANG_DE__
  g_print ("Das Anwendungsfenster wird geschlossen.\n");
#endif
#ifdef __TSC_PRJG_LANG_EN__
  g_print ("The application window will be closed.\n");
#endif
  return FALSE;
}

static void end(GtkWidget * Widget_p, gpointer Data_p) {
#ifdef __TSC_PRJG_LANG_DE__
  g_print ("Die App wird beendet.\n");
#endif
#ifdef __TSC_PRJG_LANG_EN__
  g_print ("The app will exit.\n");
#endif
  gtk_main_quit ();
}

int main(int argc, char **argv) {
  GtkWindow *Window_p;
  GdkPixbuf *Pic_p;
  /* init the environment */
  gtk_init(&argc, &argv);

  /* creating widgets */
  /* load image to Pixbuf */
  Pic_p = gdk_pixbuf_new_from_file ("icon/rattelsnake.png", NULL);
  /* set defaults */
  Window_p = g_object_new (GTK_TYPE_WINDOW,
                      "title", TSC_PRJG_VERSION_S,
                      "default-width", 1000,
                      "default-height", 800,
                      "resizable", TRUE,
                      "window-position", GTK_WIN_POS_CENTER,
                      "border-width", 55, "icon", Pic_p, NULL);
  /* create callbacks  */
  g_signal_connect ( Window_p, "delete-event",
                     G_CALLBACK (delete_Event), NULL);
  g_signal_connect ( Window_p, "destroy",
                     G_CALLBACK (end), NULL);

  /* show widget */
  gtk_widget_show_all (GTK_WIDGET (Window_p));
  /* main loop */
  gtk_main ();
#ifdef __TSC_PRJG_LANG_DE__
  g_print ("Task wird beendet.\n");
#endif
#ifdef __TSC_PRJG_LANG_EN__
  g_print ("Task is terminated.\n");
#endif
  return 0;
}
