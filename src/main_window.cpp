#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  SetupSelfMeta();
  SetupTopMenuBar();
}

MainWindow::~MainWindow() {
  delete top_menu_bar;
}

void MainWindow::SetupSelfMeta() {
  this->setFixedSize(600, 800);
  this->setWindowTitle("Hex Editor");
  this->setObjectName("window");
}

void MainWindow::SetupTopMenuBar() {
  top_menu_bar = new TopMenuBar(this);
  this->setMenuBar(top_menu_bar);
}
