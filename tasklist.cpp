#include "tasklist.h"

TaskList::TaskList(QWidget *parent) :
    QTreeWidget(parent)
{
}

void TaskList::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int selectionCount = selectedItems().count();
    if (selectionCount == 0)
        emit doubleClickedOnBlankArea();
    else if (selectionCount == 1)
        emit doubleClickedOnOneTask();
    ev->accept();
}
