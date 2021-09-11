#include "contextmenu.h"


ContextMenu::ContextMenu(QWidget *parent) :QTextEdit(parent)
{
    m_menu=new QMenu(this);
    m_menu->addAction("Red");
    m_menu->addAction("Green");
    m_menu->addAction("Blue");
    connect(m_menu,SIGNAL(treggired(QAction*)),SLOT(slotActivatedMenu(QAction*)));
}

void ContextMenu::contextMenuEvent(QContextMenuEvent *pe)
{
    m_menu->exec(pe->globalPos());
}

void ContextMenu::slotActivatedMenu(QAction *pAction)
{

}
