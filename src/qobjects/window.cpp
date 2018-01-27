#include "qobjects/window.h"

Window::Window(QWidget *parent) : QTObject(parent) {
  this->init_layout();
}

void Window::init_layout() {
  this->setFixedSize(600, 800);
  this->setWindowTitle("Hex Editor");
}
