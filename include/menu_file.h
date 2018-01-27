#ifndef HEX_EDITOR_MENU_FILE_H
#define HEX_EDITOR_MENU_FILE_H

#include <QMenu>
#include <QAction>

class FileMenu : public QMenu {
 Q_OBJECT
 public:
  explicit FileMenu(QWidget *parent);

  ~FileMenu();

 private:
  QAction *action_new;
  QAction *action_open;
  QAction *action_save;
  QAction *action_save_as;
  QAction *action_exit;

  void SetupSelfMeta();

  void SetupActionOpen();

  void SetupActionNew();

  void SetupActionSave();

  void SetupActionSaveAs();

  void SetupActionExit();

  void SetupSignalsAndSlots();

 private slots:
  void slotActionNewTriggered();
};

#endif //HEX_EDITOR_MENU_FILE_H
