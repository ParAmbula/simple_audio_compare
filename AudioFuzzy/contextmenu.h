#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H
#include<QWidget>
#include<QTextEdit>
#include<QMenu>
#include<QContextMenuEvent>

class ContextMenu :public QTextEdit
{
    Q_OBJECT
public:
    ContextMenu(QWidget *parent=0);

private:
    QMenu* m_menu;
protected:
    virtual void contextMenuEvent(QContextMenuEvent*pe);
public slots:
    void slotActivatedMenu(QAction*pAction);

};

#endif // CONTEXTMENU_H
