#ifndef QT_TUTORIAL_MAIN_WINDOW_H
#define QT_TUTORIAL_MAIN_WINDOW_H

#include <QString>
#include <QWidget>
#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>

#include "top_menu_bar.h"
#include "body_board.h"
#include "body_editor.h"

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

 private:
  TopMenuBar *top_menu_bar = nullptr;
  BodyBoard *body_board = nullptr;
  BodyEditor *body_editor = nullptr;

  void SetupSelfState();

  void SetWindowToCenter();

  void SetupTopMenuBar();

  void DestroyTopMenuBar();

  void SetupBodyBoard();

  void DestroyBodyBoard();

  void SetupBodyEditor();

  void DestroyBodyEditor();

  void ConnectSlotsAndSignals();

 private slots:
  void slotMenuNewFileTriggered();

  void slotMenuOpenFileTriggered();

  void slotMenuSaveFileTriggered();

  void slotMenuSaveAsFileTriggered();
};

#endif //QT_TUTORIAL_MAIN_WINDOW_H
