#include "body_editor.h"

BodyEditor::BodyEditor(QWidget *parent) : QWidget(parent) {
  SetupSelfState();
}

BodyEditor::~BodyEditor() {
  delete text_editor;
}

void BodyEditor::SetupSelfState() {
  setObjectName("body_editor");

  text_editor = new QTextEdit(this);
  text_editor->setObjectName(QStringLiteral("textEdit"));

  vertical_layout = new QVBoxLayout(this);
  vertical_layout->addWidget(text_editor);
  vertical_layout->setSpacing(6);
  vertical_layout->setContentsMargins(0, 0, 0, 0);
  this->setLayout(vertical_layout);
};

bool BodyEditor::IsEmpty() {
  return current_file.isEmpty();
}

bool BodyEditor::CreateEmptyFile() {
  current_file = "";
  text_editor->setText("");
  return true;
}

bool BodyEditor::OpenFile() {
  QString file_name = QFileDialog::getOpenFileName(this, "Open File...");
  QFile file(file_name);
  current_file = file_name;
  if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "..", "Fail to open file");
    return false;
  }

  QTextStream in(&file);
  QString text = in.readAll();
  text_editor->setText(text);
  file.close();
  return true;
}

bool BodyEditor::WriteCurrentContentToFile(QString &file_name) {
  QFile file(file_name);
  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "..", "File not opened for write.");
    return false;
  }
  QTextStream out(&file);
  out << text_editor->toPlainText();
  file.flush();
  file.close();
  return true;
}

bool BodyEditor::SaveFile() {
  if (current_file == "") SaveAsFile();
  return WriteCurrentContentToFile(current_file);
}

bool BodyEditor::SaveAsFile() {
  QString file_name = QFileDialog::getSaveFileName(this, "Save as");
  if (WriteCurrentContentToFile(file_name)) {
    current_file = file_name;
    return true;
  }
  return false;
}