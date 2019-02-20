#ifndef TASKLIST_H
#define TASKLIST_H

#include <QTreeWidget>
#include <QMouseEvent>

class TaskList : public QTreeWidget
{
    Q_OBJECT

public:
    explicit TaskList(QWidget *parent = 0);

signals:
    void doubleClickedOnBlankArea();
    void doubleClickedOnOneTask();

protected:
    void mouseDoubleClickEvent(QMouseEvent *ev);
};

#endif // TASKLIST_H
