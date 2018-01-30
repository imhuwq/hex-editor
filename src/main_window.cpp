#include "application.h"
#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  SetupSelfState();
  SetupTopMenuBar();
  SetupBodyBoard();

  ConnectSlotsAndSignals();
}

MainWindow::~MainWindow() {
  DestroyBodyEditor();
  DestroyBodyBoard();
  DestroyTopMenuBar();
}

void MainWindow::SetupSelfState() {
  this->setFixedSize(800, 1000);
  this->setWindowTitle("Hex Editor");
  this->setObjectName("window");

  SetWindowToCenter();
}

void MainWindow::SetWindowToCenter() {
  setGeometry(
      QStyle::alignedRect(
          Qt::LeftToRight,
          Qt::AlignCenter,
          size(),
          Application::desktop()->availableGeometry()
      )
  );
}

void MainWindow::SetupTopMenuBar() {
  top_menu_bar = new TopMenuBar(this);
  this->setMenuBar(top_menu_bar);
}

void MainWindow::DestroyTopMenuBar() {
  delete top_menu_bar;
};

void MainWindow::SetupBodyBoard() {
  if (!body_board) body_board = new BodyBoard(this);
  if (this->centralWidget()) this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(body_board);
}

void MainWindow::DestroyBodyBoard() {
  delete body_board;
}

void MainWindow::SetupBodyEditor() {
  if (!body_editor) body_editor = new BodyEditor();
  if (this->centralWidget()) this->centralWidget()->setParent(nullptr);
  this->setCentralWidget(body_editor);
}

void MainWindow::DestroyBodyEditor() {
  delete body_editor;
}

void MainWindow::slotMenuNewFileTriggered() {
  SetupBodyEditor();
  body_editor->CreateEmptyFile();
}

void MainWindow::slotMenuOpenFileTriggered() {
  SetupBodyEditor();

  // TODO: & 和 && 的区别
  if (body_editor->IsEmpty() & !body_editor->OpenFile()) SetupBodyBoard();
}

void MainWindow::ConnectSlotsAndSignals() {
  connect(top_menu_bar->findChild<QAction *>(QString("action_new_file"), Qt::FindChildrenRecursively), &QAction::triggered, this, &MainWindow::slotMenuNewFileTriggered);
  connect(top_menu_bar->findChild<QAction *>(QString("action_open_file"), Qt::FindChildrenRecursively), &QAction::triggered, this, &MainWindow::slotMenuOpenFileTriggered);
}