#ifndef QT_TUTORIAL_MAIN_WINDOW_H
#define QT_TUTORIAL_MAIN_WINDOW_H

#include <QString>
#include <QWidget>
#include <QMainWindow>

#include "top_menu_bar.h"
#include "body_board.h"

class MainWindow : public QMainWindow {
 public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

 private:
  TopMenuBar *top_menu_bar;
  BodyBoard *body_board;

  void SetupSelfState();

  void SetupTopMenuBar();

  void DestroyTopMenuBar();

  void SetupBodyBoard();

  void DestroyBodyBoard();

  void SetupBodyEditor();

  void DestroyBodyEditor();
};

#endif //QT_TUTORIAL_MAIN_WINDOW_H
