#include "menu_bar_top.h"

TopMenuBar::TopMenuBar(QWidget *parent) : QMenuBar(parent) {
  SetupSelfMeta();
  SetupFileMenu();
}

TopMenuBar::~TopMenuBar() {
  delete file_menu;
}

void TopMenuBar::SetupSelfMeta() {
  this->setObjectName("top_menu_bar");
}

void TopMenuBar::SetupFileMenu() {
  file_menu = new FileMenu(this);
  this->addMenu(file_menu);
}