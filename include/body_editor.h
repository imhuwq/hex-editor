#ifndef HEX_EDITOR_BODY_EDITOR_H
#define HEX_EDITOR_BODY_EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>

class BodyEditor : public QWidget {
 Q_OBJECT
 public:
  explicit BodyEditor(QWidget *parent = 0);
  ~BodyEditor();

  bool IsEmpty();

  bool CreateEmptyFile();

  bool OpenFile();

  bool SaveFile();

  bool SaveAsFile();

 private:
  QString current_file;
  QVBoxLayout *vertical_layout;
  QTextEdit *text_editor;

  void SetupSelfState();

  bool WriteCurrentContentToFile(QString &);
};

#endif //HEX_EDITOR_BODY_EDITOR_H
