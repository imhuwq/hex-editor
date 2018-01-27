#include "menu_file.h"

FileMenu::FileMenu(QWidget *parent) : QMenu(parent) {
  SetupSelfMeta();

  SetupActionNew();
  SetupActionOpen();
  SetupActionSave();
  SetupActionSaveAs();
  SetupActionExit();

  SetupSignalsAndSlots();
}

FileMenu::~FileMenu() {
  delete action_new;
  delete action_open;
  delete action_save;
  delete action_save_as;
  delete action_exit;
}

void FileMenu::SetupSelfMeta() {
  this->setObjectName("file_menu");
  this->setTitle("File");
}

void FileMenu::SetupActionNew() {
  action_new = new QAction(this);
  action_new->setObjectName("action_new");
  action_new->setText("New");
  this->addAction(action_new);
}

void FileMenu::SetupActionOpen() {
  action_open = new QAction(this);
  action_open->setObjectName("action_open");
  action_open->setText("Open");
  this->addAction(action_open);
}

void FileMenu::SetupActionSave() {
  action_save = new QAction(this);
  action_save->setObjectName("action_save");
  action_save->setText("Save");
  this->addAction(action_save);
}

void FileMenu::SetupActionSaveAs() {
  action_save_as = new QAction(this);
  action_save_as->setObjectName("action_save_as");
  action_save_as->setText("SaveAs");
  this->addAction(action_save_as);
}

void FileMenu::SetupActionExit() {
  action_exit = new QAction(this);
  action_exit->setObjectName("action_exit");
  action_exit->setText("Exit");
  this->addAction(action_exit);
}

void FileMenu::SetupSignalsAndSlots() {
  connect(action_new, &QAction::triggered, this, &FileMenu::slotActionNewTriggered);
}

void FileMenu::slotActionNewTriggered() {
  action_new->setText("Triggered!");
}