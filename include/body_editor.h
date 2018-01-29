#ifndef HEX_EDITOR_BODY_EDITOR_H
#define HEX_EDITOR_BODY_EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class BodyEditor : public QWidget {
 Q_OBJECT
 public:
  explicit BodyEditor(QWidget *parent = 0);
  ~BodyEditor();

  void CreateEmptyFile();

 private:
  QString current_file;
  QString current_content;
  QVBoxLayout *vertical_layout;
  QTextEdit *text_editor;

  void SetupSelfState();
};

#endif //HEX_EDITOR_BODY_EDITOR_H