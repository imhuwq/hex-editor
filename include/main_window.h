#ifndef QT_TUTORIAL_MAIN_WINDOW_H
#define QT_TUTORIAL_MAIN_WINDOW_H

#include <QString>
#include <QWidget>
#include <QMainWindow>

#include "top_menu_bar.h"

class MainWindow : public QMainWindow {
 public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

 private:
  TopMenuBar *top_menu_bar;

  void SetupSelfState();

  void SetupTopMenuBar();
};

#endif //QT_TUTORIAL_MAIN_WINDOW_H
