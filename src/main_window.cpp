#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  SetupSelfState();
  SetupTopMenuBar();
  SetupBodyBoard();
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
}

void MainWindow::SetupTopMenuBar() {
  top_menu_bar = new TopMenuBar(this);
  this->setMenuBar(top_menu_bar);
}

void MainWindow::DestroyTopMenuBar() {
  delete top_menu_bar;
};

void MainWindow::SetupBodyBoard() {
  body_board = new BodyBoard(this);
  this->setCentralWidget(body_board);
}

void MainWindow::DestroyBodyBoard() {

}

void MainWindow::SetupBodyEditor() {
  DestroyBodyBoard();
}

void MainWindow::DestroyBodyEditor() {

}