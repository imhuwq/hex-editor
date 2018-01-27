#ifndef HEX_EDITOR_MENU_BAR_TOP_H
#define HEX_EDITOR_MENU_BAR_TOP_H

#include <QMenuBar>

#include "menu_file.h"

class TopMenuBar : public QMenuBar {
 public:
  explicit TopMenuBar(QWidget *parent);
  ~TopMenuBar();

 private:
  QMenu *file_menu;

  void SetupSelfMeta();

  void SetupFileMenu();
};

#endif //HEX_EDITOR_MENU_BAR_TOP_H
