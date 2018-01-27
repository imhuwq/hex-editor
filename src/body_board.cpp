#include "body_board.h"

BodyBoard::BodyBoard(QWidget *parent) : QWidget(parent) {
  SetupSelfState();
}

BodyBoard::~BodyBoard() {
  delete layout;
  delete welcome;
}

void BodyBoard::SetupSelfState() {
  welcome = new QLabel("Welcome.");
  layout = new QVBoxLayout(this);
  layout->addWidget(welcome, 0, Qt::AlignHCenter);
  this->setLayout(layout);
}
