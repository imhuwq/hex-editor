#ifndef HEX_EDITOR_MENU_BAR_TOP_H
#define HEX_EDITOR_MENU_BAR_TOP_H

#include <QMenuBar>

class TopMenuBar : public QMenuBar {
 public:
  explicit TopMenuBar(QWidget *parent);
  ~TopMenuBar();

 private:
  QMenu *file_menu;
  QAction *action_new_file;
  QAction *action_open_file;
  QAction *action_save_file;
  QAction *action_save_as_file;

  void SetupSelfState();

  void SetupFileMenu();

  void DestroyFileMenu();
};

#endif //HEX_EDITOR_MENU_BAR_TOP_H
