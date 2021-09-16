#include "contextmenu.h"


ContextMenu::ContextMenu(QWidget *parent) :QMenu(parent)
{
    m_menu=new QMenu(this);
    m_menu->addAction("Delete selected");
    m_menu->addAction("Open file location");
    m_menu->addAction("Rename");
    connect(m_menu,SIGNAL(treggired(QAction*)),SLOT(slotActivatedMenu(QAction*)));
}

void ContextMenu::contextMenuEvent(QContextMenuEvent *pe)
{
    m_menu->exec(pe->globalPos());
}

void ContextMenu::slotActivatedMenu(QAction *pAction)
{

}
