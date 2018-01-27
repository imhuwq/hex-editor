#include "application.h"

Application::Application(int argc, char **argv) : QApplication(argc, argv), main_window(new MainWindow()) {}

Application::~Application() {
  delete main_window;
}
