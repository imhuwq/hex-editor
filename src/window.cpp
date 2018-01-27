#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
  this->InitLayout();
}

Window::~Window() {
//  delete top_menu_bar;
//  delete main_editor;
//  delete bottom_viewer;
}

void Window::InitLayout() {
  this->SetupMeta();
  this->CreateComponents();
}

void Window::SetupMeta() {
  this->setFixedSize(600, 800);
  this->setWindowTitle("Hex Editor");
}

void Window::CreateComponents() {
  this->CreateTopMenuBar();
  this->CreateMainEditor();
  this->CreateBottomViewer();
}

void Window::CreateTopMenuBar() {

}

void Window::CreateMainEditor() {

}

void Window::CreateBottomViewer() {

}