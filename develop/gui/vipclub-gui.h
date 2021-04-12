#include "../src/config.h"

#include <libsymbiot/libsymbiot.h>
 
GtkBuilder *builder;
GtkWidget *window;

static gint *retval_i;
static gchar *retval_s;
Buffer_t Buffer;
gchar hexbuf[PAGE_SIZE];

const gchar *err_fn = "vipclub-gui.error";
const gchar *dbg_fn = "vipclub-gui_dbg.txt";
const gchar *log_fn = "vipclub-gui_log.txt";
const gchar *dot_fn = "vipclub-gui.dot";
const gchar *html_fn = "vipclub-gui.html";
const gchar *conf_fn = "vipclub-gui.json";
const gchar *cb_fn = "vipclub_cb-log.txt";

// setup default writeable proj dirs
//const gchar *dir_proj=concat(g_get_home_dir,".",TSC_Proj);


//const gchar *dir_temp=g_get_temp_dir();

// setup default filename

