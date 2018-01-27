#ifndef HEX_EDITOR_QOBJECT_H
#define HEX_EDITOR_QOBJECT_H

#include <QWidget>

class QTObject : public QWidget {
 Q_OBJECT
 public:
  explicit QTObject(QWidget *parent = nullptr) {};
  virtual ~QTObject() = 0;

 protected:
  virtual void init_layout();
};

#endif //HEX_EDITOR_QOBJECT_H
