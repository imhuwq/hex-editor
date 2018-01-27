#ifndef HEX_EDITOR_BODYBOARD_H
#define HEX_EDITOR_BODYBOARD_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>


class BodyBoard : public QWidget {
 public:
  explicit BodyBoard(QWidget *parent);

  ~BodyBoard();

 private:
  QLabel* welcome;
  QBoxLayout * layout;

  void SetupSelfState();

};

#endif //HEX_EDITOR_BODYBOARD_H
