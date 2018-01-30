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
  current_content = "";
  text_editor->setText(current_content);
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
  current_content = in.readAll();
  text_editor->setText(current_content);
  file.close();
  return true;
}