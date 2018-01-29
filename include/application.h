#ifndef HEX_EDITOR_APPLICATION_H
#define HEX_EDITOR_APPLICATION_H

#include <QApplication>
#include <QString>

#include "main_window.h"

class Application : public QApplication {
 public:
  Application(int argc, char **argv);

  ~Application();

  int Run() {
    main_window->show();
    return QApplication::exec();
  }

 private:
  MainWindow *main_window;
};

#endif //HEX_EDITOR_APPLICATION_H
