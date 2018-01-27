#include <QApplication>

#include "main_window.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  MainWindow hex_editor;
  hex_editor.show();

  return app.exec();
}
