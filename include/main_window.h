#ifndef QT_TUTORIAL_MAIN_WINDOW_H
#define QT_TUTORIAL_MAIN_WINDOW_H

#include <QString>
#include <QWidget>
#include <QMainWindow>

#include "menu_bar_top.h"

class Window : public QMainWindow {
 public:
  explicit Window(QWidget *parent = nullptr);

  ~Window();

 private:
  TopMenuBar *top_menu_bar;

  void SetupSelfMeta();

  void SetupTopMenuBar();
};

#endif //QT_TUTORIAL_MAIN_WINDOW_H
