// 04.04.2021 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

#include <gtkmm/application.h>

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("testbench.vipclub");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<LibSymbIot>(argc, argv);
}