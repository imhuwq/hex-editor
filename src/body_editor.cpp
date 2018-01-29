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

void BodyEditor::CreateEmptyFile() {
  current_file = "";
  current_content = "";
}
