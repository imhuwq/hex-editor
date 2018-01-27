#include "main_window.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
  SetupSelfMeta();
  SetupTopMenuBar();
}

Window::~Window() {
  delete top_menu_bar;
}

void Window::SetupSelfMeta() {
  this->setFixedSize(600, 800);
  this->setWindowTitle("Hex Editor");
  this->setObjectName("window");
}

void Window::SetupTopMenuBar() {
  top_menu_bar = new TopMenuBar(this);
  this->setMenuBar(top_menu_bar);
}
