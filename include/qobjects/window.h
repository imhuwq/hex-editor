#ifndef QT_TUTORIAL_WINDOW_H
#define QT_TUTORIAL_WINDOW_H

#include "qt_object.h"

class Window : public QTObject {
 public:
  explicit Window(QWidget *parent = nullptr);

  ~Window() = default;

 private:
  void init_layout();
};

#endif //QT_TUTORIAL_WINDOW_H
