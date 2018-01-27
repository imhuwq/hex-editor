#ifndef QT_TUTORIAL_WINDOW_H
#define QT_TUTORIAL_WINDOW_H

#include <QWidget>
#include <QMainWindow>

class Window : public QMainWindow {
 public:
  explicit Window(QWidget *parent = nullptr);

  ~Window();

 private:
//  QWidget *top_menu_bar;
//  QWidget *main_editor;
//  QWidget *bottom_viewer;

  void InitLayout();

  void SetupMeta();

  void CreateComponents();

  void CreateTopMenuBar();

  void CreateMainEditor();

  void CreateBottomViewer();
};

#endif //QT_TUTORIAL_WINDOW_H
