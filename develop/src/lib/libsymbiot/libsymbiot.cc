#include <libsymbiot/libsymbiot.h>

LibSymbIot::LibSymbIot()
: m_button("Test") 
{

  // sets margin around the button
  m_button.set_margin(10);
  // cb
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &LibSymbIot::on_button_clicked));

  // pack into the window
  set_child(m_button);
}

LibSymbIot::~LibSymbIot()
{
}

void LibSymbIot::on_button_clicked()
{
  std::cout << "test button clicked" << std::endl;
}class MyWindow : public Gtk::Window
{
public:
  MyWindow();
};

MyWindow::MyWindow()
{
  set_title(TSC_PRJG_VERSION_S);
  set_default_size(200, 200);
}
