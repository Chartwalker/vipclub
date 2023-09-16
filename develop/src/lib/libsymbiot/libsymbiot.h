#ifndef __LIBSYMBIOT_H__
#define __LIBSYMBIOT_H__

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libsymbiot/bitops.h>
#include "../../src/config.h"

// #include <glib/gstdio.h>
// #include <glib/gprintf.h>
// #include <gio/gio.h>
// #include <gtk/gtk.h>
#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/application.h>

class LibSymbIot : public Gtk::Window
{

public:
  LibSymbIot();
  ~LibSymbIot() override;

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

#endif // __LIBSYMBIOT_H__