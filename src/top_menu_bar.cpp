#include "top_menu_bar.h"

TopMenuBar::TopMenuBar(QWidget *parent) : QMenuBar(parent) {
  SetupSelfState();
  SetupFileMenu();
}

TopMenuBar::~TopMenuBar() {
  DestroyFileMenu();
}

void TopMenuBar::SetupSelfState() {
  this->setObjectName("top_menu_bar");
}

void TopMenuBar::SetupFileMenu() {
  file_menu = new QMenu("File", this);

  action_new_file = new QAction("New", file_menu);
  action_new_file->setObjectName("action_new_file");
  file_menu->addAction(action_new_file);

  action_open_file = new QAction("Open", file_menu);
  action_open_file->setObjectName("action_open_file");
  file_menu->addAction(action_open_file);

  action_save_file = new QAction("Save", file_menu);
  action_save_file->setObjectName("action_save_file");
  file_menu->addAction(action_save_file);

  action_save_as_file = new QAction("SaveAs", file_menu);
  action_save_as_file->setObjectName("action_save_as_file");
  file_menu->addAction(action_save_as_file);

  this->addMenu(file_menu);
}

void TopMenuBar::DestroyFileMenu() {
  delete action_save_as_file;
  delete action_save_file;
  delete action_open_file;
  delete action_new_file;
  delete file_menu;
}